// worker/worker_main.cpp

#include "system_monitor.hpp"
#include "heartbeat_client.hpp"
#include <csignal>
#include <chrono>
#include <thread>
#include <iostream>

SystemMonitor* monitor_ptr = nullptr;
HeartbeatClient* client_ptr = nullptr;

void SignalHandler(int32_t signum);

int main(int argc, char* argv[]) {
	if (argc != 6) {
		std::cerr << "Usage: " << argv[0] << " <worker_id> <server_address> "
			<< "<root_cert_path> <client_cert_path> <client_key_path>" << std::endl;
		return 1;
	}

	try {
		int32_t worker_id = std::stoi(argv[1]);
		std::string server_address = argv[2];
		std::string root_cert_path = argv[3];
		std::string client_cert_path = argv[4];
		std::string client_key_path = argv[5];

		// Register signal handlers
		std::signal(SIGINT, SignalHandler);
		std::signal(SIGTERM, SignalHandler);

		// Initialise system monitor
		SystemMonitor monitor;
		monitor_ptr = &monitor;

		if (!monitor.Initialise()) {
			std::cerr 
				<< "Failed to initialise system monitor: "
				<< monitor.GetLastError() << std::endl;
			return 1;
		}

		// Initialise heartbeat client
		HeartbeatClient client(server_address, root_cert_path, client_cert_path, client_key_path);
		client_ptr = &client;

		if (!client.Initialise()) {
			std::cerr
				<< "Failed to initialise client: "
				<< client.GetLastError() << std::endl;
			return 1;
		}

		std::cout << "Worker started. Sending heartbeats to " << server_address << std::endl;
		
		// Main loop
		while (client.IsRunning()) {
			float cpu_usage = monitor.GetCPUUsage();
			float memory_usage = monitor.GetMemoryUsage();

			if (cpu_usage < 0 || memory_usage < 0) {
				std::cerr << "Failed to get system metrics: "
					<< monitor.GetLastError() << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				continue;
			}

			if (!client.SendHeartbeat(worker_id, cpu_usage, memory_usage)) {
				std::cerr << "Failed to send heartbeat: "
					<< client.GetLastError() << std::endl;

				if (!client.IsRunning()) {
					std::cout << "Server requested stop. Shutting down..." << std::endl;
					break;
				}
			}

			std::this_thread::sleep_for(std::chrono::seconds(10));
		}
		std::cout << "Worker shutting down..." << std::endl;
		return 0;
	}
	catch (const std::exception& e) {
		std::cerr << "Fatal error: " << e.what() << std::endl;
		return 1;
	}
}

void SignalHandler(int32_t signum) {
	std::cout << "\nReceived signal: " << signum << ". Initiating shutdown..." << std::endl;
	if (client_ptr) {
		client_ptr->Shutdown();
	}
}