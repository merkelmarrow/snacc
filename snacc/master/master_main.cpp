// master/master_main.cpp

// necessary grcp and service impl libraries
#include "master_service_impl.cpp"
#include "grpcpp/grpcpp.h"
#include "grpcpp/security/server_credentials.h"
#include "grpcpp/security/credentials.h"

// for working with concurrency
#include <thread>
#include <chrono>

// for working with files
#include <filesystem>
#include <fstream>

// for output
#include <iostream> 

// for signal handling for graceful shutdown
#include <csignal>

// for local specific paths and values (to be replaced with general later)
#include "secrets.h"
#include <format>

// for linux/unix 
// #include <unistd.h>

// globals
std::unique_ptr<grpc::Server> server;
HeartbeatServiceImpl* service_ptr = nullptr;


void SignalHandler(int32_t signum);
std::string read_file(const std::string& filename);
bool isValidPort(const std::string& port);


int main(int argc, char** argv) {
	// Register signal handlers
	std::signal(SIGINT, SignalHandler);
	std::signal(SIGTERM, SignalHandler);

	// Validate paths
	if (!std::filesystem::exists(SERVER_KEY_PATH)) {
		std::cerr << "Server key file not found: " << SERVER_KEY_PATH << std::endl;
		return 1;
	}
	if (!std::filesystem::exists(SERVER_CRT_PATH)) {
		std::cerr << "Server certificate file not found: " << SERVER_CRT_PATH << std::endl;
		return 1;
	}
	if (!std::filesystem::exists(SERVER_ROOT_CERTS)) {
		std::cerr << "Root certificates file not found: " << SERVER_ROOT_CERTS << std::endl;
		return 1;
	}

	try {
		// Create service instance
		HeartbeatServiceImpl service;
		service_ptr = &service; // For signal handler

		// Set up SSL creds
		grpc::SslServerCredentialsOptions::PemKeyCertPair pem_key_cert_pair;
		
		try {
			pem_key_cert_pair.private_key = read_file(std::getenv("SERVER_KEY_PATH") ? std::getenv("SERVER_KEY_PATH") : SERVER_KEY_PATH);
			pem_key_cert_pair.cert_chain = read_file(std::getenv("SERVER_CRT_PATH") ? std::getenv("SERVER_CRT_PATH") : SERVER_CRT_PATH);
		}
		catch (const std::runtime_error& e) {
			std::cerr << "Failed to read SSL certs: " << e.what() << std::endl;
			return 1;
		}
		
		grpc::SslServerCredentialsOptions ssl_opts;
		ssl_opts.pem_root_certs = read_file(std::getenv("SERVER_ROOT_CERTS") ? std::getenv("SERVER_ROOT_CERTS") : SERVER_ROOT_CERTS);
		ssl_opts.pem_key_cert_pairs.push_back(pem_key_cert_pair);

		auto server_creds = grpc::SslServerCredentials(ssl_opts);

		
		if (!isValidPort(MASTER_GRPC_PORT)) {
			std::cerr << "Invalid grpc port: " << MASTER_GRPC_PORT << std::endl;
			return 1;
		}
		// Build server listening on VPN interface
		std::string server_address = std::format("{}:{}", 
			std::getenv("MASTER_VPN_IP") ? std::getenv("MASTER_VPN_IP") : MASTER_VPN_IP,
			std::getenv("MASTER_GRPC_PORT") ? std::getenv("MASTER_GRPC_PORT") : MASTER_GRPC_PORT);
		grpc::ServerBuilder builder;

		builder.AddListeningPort(server_address, server_creds);
		builder.SetMaxMessageSize(64 * 1024 * 1024); // 64 MB max message size (loads)
		builder.SetMaxReceiveMessageSize(64 * 1024 * 1024);

		builder.RegisterService(&service);

		// Build and start
		server = builder.BuildAndStart();
		if (!server) {
			std::cerr << "Failed to start server." << std::endl;
			return 1;
		}

		std::cout << "Master node listening on " << server_address << std::endl;
		std::cout << "Accessible via public IP: " << MASTER_PUBLIC_IP << std::endl;

		// Monitoring thread
		std::thread monitor_thread([&service]() {
			try {
				while (service.IsRunning()) {
					std::this_thread::sleep_for(std::chrono::seconds(5));
					service.PrintAllWorkersConnStatus();
				}
			}
			catch (const std::exception& e) {
				std::cerr << "Monitor thread error: " << e.what() << std::endl;
				SignalHandler(SIGTERM);
			}
			});

		// Wait for server to shutdown (blocking)
		server->Wait();

		// Clean shutdown
		service.Shutdown();
		if (monitor_thread.joinable()) {
			monitor_thread.join();
		}

		return 0;
	}
	catch (const std::exception& e) {
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return 1;
	}
}

std::string read_file(const std::string& filename) {
	std::filesystem::path filepath(filename);
	if (!std::filesystem::exists(filepath)) {
		throw std::runtime_error("File not found: " + filename);
	}

	std::ifstream file(filepath, std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file: " + filename);
	}

	return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void SignalHandler(int32_t signum) {
	std::cout << "\nReceived signal \"" << signum << "\". Initiating graceful shutdown..." << std::endl;

	if (service_ptr) {
		service_ptr->Shutdown();
	}
	if (server) {
		server->Shutdown();
	}
}

bool isValidPort(const std::string& port) {
	try {
		int port_num = std::stoi(port);
		return port_num >= 0 && port_num <= 65535;
	}
	catch (...) {
		return false;
	}
}