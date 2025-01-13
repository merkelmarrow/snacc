// worker/system_monitor.hpp

#pragma once

#include <pdh.h>
#include <string>
#include <windows.h>

// Interface for monitoring system metrics
class ISystemMonitor {
public:
	virtual ~ISystemMonitor() = default;
	virtual bool Initialise() = 0;
	virtual float GetCPUUsage() = 0;
	virtual float GetMemoryUsage() = 0;
	virtual std::string GetLastError() const = 0;
};

class SystemMonitor : public ISystemMonitor {
public:
	SystemMonitor();
	~SystemMonitor() override;

	bool Initialise() override;
	float GetCPUUsage() override;
	float GetMemoryUsage() override;
	std::string GetLastError() const override { return last_error_; }

private:
	PDH_HQUERY cpu_query_{ nullptr };
	PDH_HCOUNTER cpu_counter_{ nullptr };
	std::string last_error_;

	void Cleanup();
	void SetLastError(const std::string& error);
};