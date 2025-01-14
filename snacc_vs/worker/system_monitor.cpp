// worker/system_monitor.cpp

#include "system_monitor.hpp"
#include <stdexcept>
#include <PdhMsg.h>

SystemMonitor::SystemMonitor() {}

SystemMonitor::~SystemMonitor() {
	Cleanup();
}

void SystemMonitor::Cleanup() {
	if (cpu_query_) {
		PdhCloseQuery(cpu_query_);
		cpu_query_ = nullptr;
		cpu_counter_ = nullptr;
	}
}

void SystemMonitor::SetLastError(const std::string& error) {
	last_error_ = error;
}

bool SystemMonitor::Initialise() {
	PDH_STATUS status = PdhOpenQuery(NULL, 0, &cpu_query_);
	if (status != ERROR_SUCCESS) {
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

	// Prime the counter with the first read
	status = PdhCollectQueryData(cpu_query_);
	if (status != ERROR_SUCCESS) {
		SetLastError("Failed to collect initial CPU data.");
		Cleanup();
		return false;
	}

	return true;
}

float SystemMonitor::GetCPUUsage() {
	if (!cpu_query_ || !cpu_counter_) {
		SetLastError("SystemMonitor not initialised");
		return -1.0f;
	}

	PDH_STATUS status = PdhCollectQueryData(cpu_query_);
	if (status != ERROR_SUCCESS) {
		SetLastError("Failed to collect CPU data");
		return -1.0f;
	}

	PDH_FMT_COUNTERVALUE counter_val;
	DWORD dwType;
	status = PdhGetFormattedCounterValue(
		cpu_counter_,
		PDH_FMT_DOUBLE,
		&dwType,
		&counter_val
	);

	if (status != ERROR_SUCCESS) {
		SetLastError("Failed to format CPU counter value");
		return -1.0f;
	}

	return static_cast<float>(counter_val.doubleValue);
}

float SystemMonitor::GetMemoryUsage() {
	MEMORYSTATUSEX mem_info;
	mem_info.dwLength = sizeof(MEMORYSTATUSEX);

	if (!GlobalMemoryStatusEx(&mem_info)) {
		SetLastError("Failed to get memory status");
		return -1.0f;
	}

	return static_cast<float>(mem_info.dwMemoryLoad);
}