# master/CMakeLists.txt

cmake_minimum_required (Version 3.21)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package (protobuf CONFIG REQUIRED)
find_package (gRPC CONFIG REQUIRED)

add_library (heartbeat_proto STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/../proto/heartbeat.pb.cc
	${CMAKE_CURRENT_SOURCE_DIR}/../proto/heartbeat.grpc.pb.cc
)

target_include_directories (heartbeat_proto PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../proto
	${Protobuf_INCLUDE_DIRS}
)

target_link_libraries (heartbeat_proto PUBLIC
	protobuf::libprotobuf
	gRPC::grpc
	gRPC::grpc++
	gRPC::grpc++_reflection
)

add_executable (master
	master_main.cpp
	master_service.impl.cpp
)

target_link_libraries (master PRIVATE
	heartbeat_proto
)