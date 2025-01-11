// worker/heartbeatclient.cpp
#include "heartbeat_client.hpp"
#include <grpcpp/grpcpp.h>
#include <fstream>

HeartbeatClient::HeartbeatClient(
	const std::string& server_address,
	const std::string& root_cert_path,
	const std::string& client_cert_path,
	const std::string& client_key_path)
	: server_address_(server_address),
	root_cert_path_(root_cert_path),
	client_cert_path_(client_cert_path),
	client_key_path_(client_key_path) {}

std::string HeartbeatClient::ReadFile(const std::string& path) {
	std::filesystem::path filepath(path);
	if (!std::filesystem::exists(filepath)) {
		throw std::runtime_error("File not found: " + path);
	}

	std::ifstream file(filepath, std::ios::binary);
	if (!file.is_open()) {
		throw std::runtime_error("Failed to open file: " + path);
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	return buffer.str();
}

void HeartbeatClient::SetLastError(const std::string& error) {
	last_error_ = error;
}

std::shared_ptr<grpc::Channel> HeartbeatClient::CreateChannel() {
	try {
		grpc::SslCredentialsOptions ssl_opts;
		ssl_opts.pem_root_certs = ReadFile(root_cert_path_);
		ssl_opts.pem_cert_chain = ReadFile(client_cert_path_);
		ssl_opts.pem_private_key = ReadFile(client_key_path_);

		auto channel_creds = grpc::SslCredentials(ssl_opts);

		grpc::ChannelArguments args;
		args.SetMaxReceiveMessageSize(64 * 1024 * 1024); // 64 MB
		args.SetMaxSendMessageSize(64 * 1024 * 1024); // 64 MB

		return grpc::CreateCustomChannel(server_address_, channel_creds, args);
	}
	catch (const std::exception& e) {
		SetLastError(std::string("Failed to create channel: ") + e.what());
		return nullptr;
	}
}

bool HeartbeatClient::Initialise() {
	auto channel = CreateChannel();
	if (!channel) {
		return false;
	}

	stub_ = heartbeat::HeartbeatService::NewStub(channel);
	return true;
}

bool HeartbeatClient::SendHeartbeat(int32_t worker_id, float cpu_usage, float memory_usage) {
	if (!stub_ || !running_) {
		SetLastError("Client not initialised or shutting down");
		return false;
	}

	heartbeat::HeartbeatRequest request;
	request.set_worker_id(worker_id);
	request.set_worker_hostname("merkelmarrow's Laptop");
	request.set_cpu_usage(cpu_usage);
	request.set_memory_usage(memory_usage);

	heartbeat::HeartbeatReply reply;
	grpc::ClientContext context;

	std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::seconds(5);
	context.set_deadline(deadline);

	grpc::Status status = stub_->SendHeartbeat(&context, request, &reply);
	
	if (!status.ok()) {
		SetLastError("RPC failed: " + status.error_message());
		return false;
	}

	if (reply.acknowledged() == 1) {
		SetLastError("Server requested stop");
		running_ = false;
		return false;
	}

	return true;
}

void HeartbeatClient::Shutdown() {
	running_ = false;
}