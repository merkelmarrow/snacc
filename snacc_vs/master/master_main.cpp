// master/master_main.cpp


#include "master_service_impl.cpp"
#include "grpcpp/grpcpp.h"
#include "grpcpp/security/server_credentials.h"
#include "grpcpp/security/credentials.h"

#include <thread>
#include <chrono>

#include <filesystem>
#include <fstream>

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

	grpc::SslServerCredentialsOptions::PemKeyCertPair pem_key_cert_pair;

	pem_key_cert_pair.private_key = read_file("")
}

