// master/master_service_impl.cpp

#include "heartbeat.grpc.pb.h"
#include <chrono>
#include <thread>
#include <mutex>
#include <cstdint>
#include <unordered_map>

//// For reference (namespace heartbeat)
// class Service : public ::grpc::Service {
// public:
//    Service();
//    virtual ~Service();
//    // Worker calls this every 10s to report health
//    virtual ::grpc::Status SendHeartbeat(::grpc::ServerContext* context, 
//        const ::heartbeat::HeartbeatRequest* request, ::heartbeat::HeartbeatReply* response);
// };

class HeartbeatServiceImpl final : public heartbeat::HeartbeatService::Service {
private:
	// Storage for worker states
	std::mutex mutex_;
	std::unordered_map<int32_t, std::chrono::steady_clock::time_point> last_heartbeat_; // workerID (int32_t), timestamp (time_point)

public:
	::grpc::Status SendHeartbeat(::grpc::ServerContext* context,
		const ::heartbeat::HeartbeatRequest* request, ::heartbeat::HeartbeatReply* response) override {
		// 1. Get current timestamp
		auto now = std::chrono::steady_clock::now();

		{
			std::lock_guard<std::mutex> lock(mutex_);
			last_heartbeat_[request->worker_id()] = now;
		}
	}
};