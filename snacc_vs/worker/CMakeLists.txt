# worker/CMakeLists.txt

cmake_minimum_required (VERSION 3.21)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package (Protobuf CONFIG REQUIRED)
find_package (gRPC CONFIG REQUIRED)
find_package (ZLIB REQUIRED)

add_executable (worker
	system_monitor.hpp
	system_monitor.cpp
	heartbeat_client.hpp
 "heartbeat_client.cpp")

target_link_libraries (worker PRIVATE
	heartbeat_proto
)


    