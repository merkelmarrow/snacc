// main.cpp

/// Program to practice executing powershell commands
#include <iostream> // std::cout, std::cerr, std::endl
#include <string> // std::string
#include <cstdlib> // std::system
#include "process.hpp" // TinyProcessLib::Process

namespace {
	namespace tpl = TinyProcessLib; // Shorten TinyProcessLib to tpl
}

int main() {
	std::string command = "powershell -Command \"Write-Host 'Hi'\"";

	tpl::Process process(command,
		"",
		[](const char* bytes, size_t n) {
			std::cout << "Output: " << std::string(bytes, n);
		},
		[](const char* bytes, size_t n) {
			std::cerr << "Error: " << std::string(bytes, n);
		}
	);

	auto result = process.get_exit_status();

	if (result == 0) {
		std::cout << "Success." << std::endl;
	}
	else {
		std::cerr << "Failure. Error code: " << result << std::endl;
	}

	return 0;
}