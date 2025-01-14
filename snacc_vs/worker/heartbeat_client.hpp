// worker/heartbeat_client.hpp

#pragma once
#include "heartbeat.grpc.pb.h"
#include <string>
#include <memory>
#include <atomic>
#include <filesystem>
#include <stdexcept>

// interface to decouple file I/O from HeartbeatClient
class IFileReader {
public:
	virtual ~IFileReader() = default;
	virtual std::string Read(const std::string& path) = 0;
};

class FileReader : public IFileReader {
public:
	std::string Read(const std::string& path) override {
		std::filesystem::path filepath(path);
		if (!std::filesystem::exists(filepath)) {
			throw(std::runtime_error("File not found: " + path));
		}
		std::ifstream file(filepath, std::ios::binary);
		if (!file.is_open()) {
			throw std::runtime_error("Failed to open file: " + path);
		}
		std::stringstream buffer;
		buffer << file.rdbuf();
		return buffer.str();
	}
};

// Interface for HeartbeatClient
class IHeartbeatClient {
public:
	virtual ~IHeartbeatClient() = default;
	virtual bool Initialise() = 0;
	virtual bool SendHeartbeat(int32_t worker_id, float cpu_usage, float memory_usage) = 0;
	virtual void Shutdown() = 0;
	virtual bool IsRunning() const = 0;
	virtual std::string GetLastError() const = 0;
};

class HeartbeatClient  : public IHeartbeatClient {


public:
	HeartbeatClient(const std::string& server_address,
		const std::string& root_cert_path,
		const std::string& client_cert_path,
		const std::string& client_key_path,
		IFileReader& file_reader // injected dependency
		);

	bool Initialise();
	bool SendHeartbeat(int32_t worker_id, float cpu_usage, float memory_usage);
	void Shutdown();
	bool IsRunning() const { return running_; }
	std::string GetLastError() const { return last_error_; }


private:
	std::string server_address_;
	std::string root_cert_path_;
	std::string client_cert_path_;
	std::string client_key_path_;

	IFileReader& file_reader_;

	std::unique_ptr<heartbeat::HeartbeatService::Stub> stub_;
	std::atomic<bool> running_{ true };
	std::string last_error_;

	std::shared_ptr<grpc::Channel> CreateChannel();
	void SetLastError(const std::string& error);
	bool LoadCerts(std::string& root_certs,
		std::string& client_certs,
		std::string& client_key);
};