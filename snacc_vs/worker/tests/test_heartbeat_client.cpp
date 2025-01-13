#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "../heartbeat_client.hpp"
#include "mock_heartbeat_service.hpp"


// anonymous namespace
namespace {
	// MockFileReader to avoid actual file I/O
	class MockFileReader : public IFileReader {
	public:
		MOCK_METHOD(std::string, Read, (const std::string&), (override));
	};

	// utility class to create a mock "channel" that returns MockHeartbeatServiceStub
	class MockChannel final : public grpc::ChannelInterface {
	public:
		explicit MockChannel(std::shared_ptr<MockHeartbeatServiceStub> stub)
			: stub_(std::move(stub)) {}

		// below are required overrides from ChannelInterface:
		::grpc::CompletionQueue* CallbackCQ() override { return nullptr; }

		grpc_connectivity_state GetState(bool /*try_to_connect*/) override {
			return GRPC_CHANNEL_READY; // Mock a ready state for simplicity
		}

		void NotifyOnStateChangeImpl(grpc_connectivity_state /*last_observed*/,
			gpr_timespec /*deadline*/,
			grpc::CompletionQueue* /*cq*/,
			void* /*tag*/) override {
			// No-op for mock
		}

		bool WaitForStateChangeImpl(grpc_connectivity_state /*last_observed*/,
			gpr_timespec /*deadline*/) override {
			return true; // Simulate a successful state change
		}

		void PerformOpsOnCall(grpc::internal::CallOpSetInterface* /*ops*/,
			grpc::internal::Call* /*call*/) override {
			// No-op for mock
		}

		void* RegisterMethod(const char* /*method*/) override {
			return nullptr; // Simulate no registration for mock
		}

		grpc::internal::Call CreateCall(const grpc::internal::RpcMethod& /*method*/,
			grpc::ClientContext* /*context*/,
			grpc::CompletionQueue* /*cq*/) override {
			return grpc::internal::Call(); // Return a default Call object
		}

		grpc::internal::Call CreateCallInternal(
			const grpc::internal::RpcMethod& /*method*/,
			grpc::ClientContext* /*context*/,
			grpc::CompletionQueue* /*cq*/,
			size_t /*interceptor_pos*/) override {
			return grpc::internal::Call(); // Return a default Call object
		}


		// custom method that return mock stub
		std::shared_ptr<heartbeat::HeartbeatService::StubInterface> GetMockStub() {
			return  stub_;
		}

	private:
		std::shared_ptr<MockHeartbeatServiceStub> stub_;
	};

	// create a shared_ptr<grpc::Channel> that actually returns the mock stub
	// cast from MockChannel to a grpc::Channel*
	std::shared_ptr<grpc::Channel> CreateMockChannel(std::shared_ptr<MockHeartbeatServiceStub> mock_stub) {
		auto ch = std::make_shared<MockChannel>(std::move(mock_stub));
		return std::shared_ptr<grpc::Channel>(
			reinterpret_cast<grpc::Channel*>(ch.get()), [](grpc::Channel*) { /* no-op custom deleter*/ }
		);
	}
} // end anonymous namespace