// worker/system_monitor.cpp

#include "system_monitor.hpp"
#include <stdexcept>

SystemMonitor::SystemMonitor() {}

SystemMonitor::~SystemMonitor() {
	Cleanup();
}

void SystemMonitor::Cleanup() {
	if (cpu_query_) {
		PdhCloseQuery(cpu_query_);
		cpu_query_ = NULL;
		cpu_counter_ = NULL;
	}
}

void SystemMonitor::SetLastError(const std::string& error) {
	last_error_ = error;
}

bool SystemMonitor::Initialise() {
	PDH_STATUS status = PdhOpenQuery(NULL, 0, &cpu_query_);
	if (status != ERORR_SUCCESS) {
		SetLastError("Failed to open PDH query");
		return false;
	}

	// Add CPU counter
	status = PdhAddCounter(cpu_query_, TEXT("\\Processor(_Total)\\% Processor Time"), 0, &cpu_counter_);

	if (status != ERROR_SUCCESS) {
		SetLastError("Failed to add CPU counter");
		Cleanup();
		return false;
	}

	status = PdhCollectQueryData(cpu_query_);
	if (status != ERROR_SUCCESS) {
		SetLastError("Failed to collect initial CPU data");
		Cleanup();
		return false;
	}

	return true;
}

