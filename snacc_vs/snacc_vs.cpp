// snacc_vs.cpp : Defines the entry point for the application.
//

#include "snacc_vs.h"
#include "student.pb.h"
#include <fstream>


void WriteStudent()
{
	Student student;

	// Set fields using generated setters
	student.set_name("Alice");
	student.set_gpa(3.8);
	student.set_age(20);

	// Method 1: Serialize to binary file
	std::ofstream output("student.bin", std::ios::binary);
	if (!student.SerializeToOstream(&output)) {
		std::cerr << "Failed to write student." << std::endl;
		return;
	}

	// Method 2: Serialise to a string
	std::string serialized_data;
	serialized_data.resize(student.ByteSizeLong());
	google::protobuf::io::ArrayOutputStream array_output(&serialized_data[0], serialized_data.size());
	google::protobuf::io::CodedOutputStream coded_output(&array_output);
	student._InternalSerialize(
		reinterpret_cast<uint8_t*>(&serialized_data[0]), &coded_output);


}

void ReadStudent() {
    Student student;

    // Method 1: Read from binary file
    std::ifstream input("student.bin", std::ios::binary);
    if (!student.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse student." << std::endl;
        return;
    }

    // Method 2: Parse from string
    google::protobuf::io::ArrayInputStream array_input(
        serialized_data.data(), serialized_data.size());
    google::protobuf::io::CodedInputStream coded_input(&array_input);
    if (!student.ParseFromCodedStream(&coded_input)) {
        std::cerr << "Failed to parse from string." << std::endl;
        return;
    }

    // Now we can access the fields
    std::cout << "Name: " << student.name() << std::endl;
    std::cout << "Age: " << student.age() << std::endl;
    std::cout << "GPA: " << student.gpa() << std::endl;
}
