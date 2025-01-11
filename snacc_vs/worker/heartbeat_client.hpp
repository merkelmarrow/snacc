// worker/heartbeat_client.hpp

#pragma once
#include "heartbeat.grpc.pb.h"
#include <string>
#include <memory>



class HeartbeatClient {
private:
	std::string server_address_;
	std::string root_cert_path_;
	std::string client_cert_path_;
	std::string client_key_path_;
	std::unique_ptr<heartbeat::HeartbeatService::Stub> stub_;
	std::atomic<bool> running_{ false };
	std::string last_error_;

	std::shared_ptr<grpc::Channel> CreateChannel();
	void SetLastError(const std::string& error);
	std::string ReadFile(const std::string& path);

public:
	HeartbeatClient(const std::string& server_address,
		const std::string& root_cert_path,
		const std::string& client_cert_path,
		const std::string& client_key_path);

	bool Initialise();
	bool SendHeartbeat(int32_t worker_id, float cpu_usage, float memory_usage);
	void Shutdown();
	bool IsRunning() const { return running_; }
	std::string GetLastError() const { return last_error_; }
};