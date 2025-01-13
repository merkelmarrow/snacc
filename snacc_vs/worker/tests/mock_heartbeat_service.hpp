#pragma once

#include <gmock/gmock.h>
#include "heartbeat.grpc.pb.h"

// Mock class for generated gRPC 'HeartbeatService::StubInterface'
//
// The real code looks like...
//
// class HeartbeatService::StubInterface {
// public:
// 		// Worker calls this every 10s to report health
//		virtual ::grpc::Status SendHeartbeat(::grpc::ClientContext* context, const ::heartbeat::HeartbeatRequest& request, ::heartbeat::HeartbeatReply* response) = 0;
// };


class MockHeartbeatService : public heartbeat::HeartbeatService::StubInterface {
public:
	// Mock the SendHeartbeat method
	MOCK_METHOD(
		::grpc::Status,
		SendHeartbeat,
		(::grpc::ClientContext* context,
			const ::heartbeat::HeartbeatRequest& request,
			::heartbeat::HeartbeatReply* response),
		(override)
	);
};