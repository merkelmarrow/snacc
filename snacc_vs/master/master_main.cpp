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

// for local specific paths and values (to be replaced with general later)
#include "secrets.h"

std::string read_file (const std::string& filename) {
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

int main (int argc, char** argv) {
	// Create service instance
	HeartbeatServiceImpl service;

	// Set up SSL creds
	grpc::SslServerCredentialsOptions::PemKeyCertPair pem_key_cert_pair;

	pem_key_cert_pair.private_key = read_file(LOCAL_PATH_TO_SERVER_KEY);
	pem_key_cert_pair.cert_chain = read_file(LOCAL_PATH_TO_SERVER_CRT);

	grpc::SslServerCredentialsOptions ssl_opts;
	ssl_opts.pem_root_certs = read_file(LOCAL_PATH_TO_SERVER_ROOT_CERTS);
	ssl_opts.pem_key_cert_pairs.push_back(pem_key_cert_pair);

	auto server_creds = grpc::SslServerCredentials(ssl_opts);

	// Build server listening on VPN interface
	std::string server_address(LOCAL_VPN_MASTER_IP_AND_PORT);
	grpc::ServerBuilder builder;

	builder.AddListeningPort(server_address, server_creds);
	builder.SetMaxMessageSize(64 * 1024 * 1024); // 64 MB max message size (loads)
	builder.SetMaxReceiveMessageSize(64 * 1024 * 1024);

	builder.RegisterService(&service);

	// Build and start
	std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
	std::cout << 
}

