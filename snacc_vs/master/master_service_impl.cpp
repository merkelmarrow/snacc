// master/master_service_impl.cpp

#include "heartbeat.grpc.pb.h"
#include <chrono>
#include <thread>
#include <mutex>
#include <cstdint>
#include <unordered_map>

#include <magic_enum/magic_enum.hpp>

//// For reference (namespace heartbeat)
// class Service : public ::grpc::Service {
// public:
//    Service();
//    virtual ~Service();
//    // Worker calls this every 10s to report health
//    virtual ::grpc::Status SendHeartbeat(::grpc::ServerContext* context, 
//        const ::heartbeat::HeartbeatRequest* request, ::heartbeat::HeartbeatReply* response);
// };

enum class WorkerConnStatus {
	CONNECTED,
	DISCONNECTED,
	CONNECTING,
	CONNECTION_LOST,
	UNKNOWN
};

enum class WorkerHealth {
	HEALTHY,
	DEGRADED,
	UNREACHABLE,
	FAILED,
	MAINTENANCE,
	UNKNOWN
};

class HeartbeatServiceImpl final : public heartbeat::HeartbeatService::Service {
private:
	// Storage for worker states
	std::mutex mutex_;
	std::unordered_map<int32_t, std::chrono::steady_clock::time_point> last_heartbeat_; // workerID (int32_t), timestamp (time_point)

	// For clean shutdown
	std::atomic<bool> running_{ true };

public:

	~HeartbeatServiceImpl() {
		running_ = false;
	}

	void Shutdown() {
		running_ = false;
	}

	bool IsRunning() const {
		return running_;
	}

	::grpc::Status SendHeartbeat(::grpc::ServerContext* context,
		const ::heartbeat::HeartbeatRequest* request, ::heartbeat::HeartbeatReply* response) override {
		// 1. Get current timestamp
		auto now = std::chrono::steady_clock::now();

		{
			std::lock_guard<std::mutex> lock(mutex_);
			last_heartbeat_[request->worker_id()] = now;
		}

		enum HeartbeatResponse {
			CONTINUE,
			STOP
		};

		//// TODO: INSERT LOGIC TO EVALUATE HEALTH OF WORKER AND SEND REPONSE CODE
		int32_t response_code = CONTINUE;
		////

		response->set_acknowledged(response_code);

		return ::grpc::Status::OK;
	}

	// don't use unless you've locked the mutex
	WorkerConnStatus GetWorkerConnStatus (int32_t worker_id, uint64_t &diff) {
		constexpr int DISCONNECTED_THRESHOLD = 30;
		constexpr int CONNECTION_LOST_THRESHOLD = 15;


		if (auto it = last_heartbeat_.find(worker_id); it != last_heartbeat_.end()) {
			auto now = std::chrono::steady_clock::now();
			diff = std::chrono::duration_cast<std::chrono::seconds>(now - it->second).count();

			if (diff > DISCONNECTED_THRESHOLD) return WorkerConnStatus::DISCONNECTED;
			if (diff > CONNECTION_LOST_THRESHOLD) return WorkerConnStatus::CONNECTION_LOST;
			return WorkerConnStatus::CONNECTED;
		}

		return WorkerConnStatus::UNKNOWN;
	}

	void PrintAllWorkersConnStatus() {

		auto now = std::chrono::steady_clock::now();
		std::lock_guard lock(mutex_);
		for (const auto& [worker_id, last_heartbeat_time] : last_heartbeat_) {
			uint64_t time_diff;
			WorkerConnStatus conn_status = GetWorkerConnStatus(worker_id, time_diff);
			std::cout << "Worker ID: " << worker_id
				<< ", Status: " << magic_enum::enum_name(conn_status)
				<< ", Last Heartbeat: " << time_diff << " seconds ago." << std::endl;
		}
	}
};