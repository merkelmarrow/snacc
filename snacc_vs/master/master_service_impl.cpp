// master/master_service_impl.cpp

#include "heartbeat.proto"
#include <stdlib>
#include <chrono>

void healthcheck_loop(HeartbeatService* hbservice, bool& stop_loop) {
	if (stop_loop) return;
	std::chrono::timepoint current_time;
	current_time = std::chrono::system_clock::now();
}