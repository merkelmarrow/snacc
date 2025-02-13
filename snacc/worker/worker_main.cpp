// worker/worker_main.cpp

#include "system_monitor.hpp"
#include "heartbeat_client.hpp"
#include <csignal>
#include <chrono>
#include <thread>
#include <iostream>

// Globals for signal handling
static ISystemMonitor* g_monitor_ptr = nullptr;
static IHeartbeatClient* g_client_ptr = nullptr;

void SignalHandler(int32_t signum);

int main(int argc, char* argv[]) {
	if (argc != 6) {
		std::cerr << "Usage: " << argv[0] << " <worker_id> <server_address> "
			<< "<root_cert_path> <client_cert_path> <client_key_path>" << std::endl;
		return 1;
	}

	int32_t worker_id = std::stoi(argv[1]);
	std::string server_address = argv[2];
	std::string root_cert_path = argv[3];
	std::string client_cert_path = argv[4];
	std::string client_key_path = argv[5];

	// Register signal handlers
	std::signal(SIGINT, SignalHandler);
	std::signal(SIGTERM, SignalHandler);	

	// Initialise system monitor
	auto monitor = std::make_unique<SystemMonitor>();

	if (!monitor->Initialise()) {
		std::cerr
			<< "Failed to initialise system monitor: "
			<< monitor->GetLastError() << std::endl;
		return 1;
	}
	g_monitor_ptr = monitor.get();

	// create file reader
	FileReader file_reader;

	// create heartbeat client
	auto client = std::make_unique<HeartbeatClient>(
		server_address,
		root_cert_path,
		client_cert_path,
		client_key_path,
		file_reader	
	);


	if (!client->Initialise()) {
		std::cerr
			<< "Failed to initialise client: "
			<< client->GetLastError() << std::endl;
		return 1;
	}
	g_client_ptr = client.get();

	std::cout << "Worker started. Sending heartbeats to " << server_address << std::endl;

	// Main loop
	while (client->IsRunning()) {
		float cpu_usage = monitor->GetCPUUsage();
		float memory_usage = monitor->GetMemoryUsage();

		if (cpu_usage < 0 || memory_usage < 0) {
			std::cerr << "Failed to get system metrics: "
				<< monitor->GetLastError() << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			continue;
		}

		if (!client->SendHeartbeat(worker_id, cpu_usage, memory_usage)) {
			std::cerr << "Failed to send heartbeat: "
				<< client->GetLastError() << std::endl;

			if (!client->IsRunning()) {
				std::cout << "Server requested stop. Shutting down..." << std::endl;
				break;
			}
		}

		std::this_thread::sleep_for(std::chrono::seconds(10));
	}
	std::cout << "Worker shutting down..." << std::endl;
	return 0;
}


void SignalHandler(int32_t signum) {
	std::cout << "\nReceived signal: " << signum << ". Initiating shutdown..." << std::endl;
	if (g_client_ptr) {
		g_client_ptr->Shutdown();
	}
}