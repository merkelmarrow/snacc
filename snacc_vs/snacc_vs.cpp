// snacc_vs.cpp : Defines the entry point for the application.
//

#include "student.pb.h"

#include <iostream>

void ProcessStudentData(const std::string& data) {
	Student student;
	if (!student.ParseFromString(data)) {
		std::cerr << "Error: Failed to parse student data." << std::endl;
		return;
	}

	std::cout << "Deserialised Student Info:" << std::endl;
	std::cout << "Name: " << student.name() << std::endl;
	std::cout << "Age: " << student.age() << std::endl;
	std::cout << "GPA: " << student.gpa() << std::endl;
}


int main() {
	Student s;
	s.set_name("Alice");
	s.set_age(20);
	s.set_gpa(3.7f);

	std::string serialisedData;
	if (!s.SerializeToString(&serialisedData)) {
		std::cerr << "Error: Failed to serialise student." << std::endl;
		return 1;
	}

	ProcessStudentData(serialisedData);
}