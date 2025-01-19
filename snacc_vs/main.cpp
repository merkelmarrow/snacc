// main.cpp

/// Program to practice executing powershell commands
#include <iostream>
#include <string>

int main() {
	std::string command = "powershell -Command \"Write-Host 'Hi'\"";

	int result = std::system(command.c_str());

	if (result == 0) {
		std::cout << "Success." << std::endl;
	}
	else {
		std::cerr << "Failure. Error code: " << result << std::endl;
	}

	return 0;
}