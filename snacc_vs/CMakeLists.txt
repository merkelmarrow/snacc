# CMakeList.txt : CMake project for snacc_vs, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("snacc")


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#find_package(Protobuf CONFIG REQUIRED)

# Compile the generated .pb.cc file
#add_library(student_proto STATIC student.pb.cc)
#target_include_directories(student_proto PUBLIC ${Protobuf_INCLUDE_DIRS})
#target_link_libraries(student_proto PUBLIC protobuf::libprotobuf)

# Worker executable
#add_executable (worker "worker/worker.cpp")
#target_link_libraries(worker PRIVATE student_proto)

# Master executable
#add_executable (master "master/master.cpp")
#target_link_libraries (master PRIVATE student_proto)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  #set_property(TARGET master PROPERTY CXX_STANDARD 20)
  #set_property(TARGET worker PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
### this is heuristically generated, and may not be correct
  # find_package(gRPC CONFIG REQUIRED)
  ## note: 15 additional targets are not displayed.
  # target_link_libraries(main PRIVATE gRPC::gpr gRPC::grpc gRPC::grpc++ gRPC::grpc++_alts)