// worker/system_monitor.hpp
#pragma once
#include <pdh.h>
#include <string>
#include <windows.h>

class SystemMonitor {
private:
	PDH_HQUERY cpu_query_{ NULL };
	PDH_HCOUNTER cpu_counter_{ NULL };
	std::string last_error_;

	void Cleanup();
	void SetLastError(const std::string& error);

public:
	SystemMonitor();
	~SystemMonitor();

	bool Initialise();
	float GetCPUUsage();
	float GetMemoryUsage();
	std::string GetLastError() const { return last_error_; }
};