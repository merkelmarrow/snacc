# worker/CMakeLists.txt

cmake_minimum_required (VERSION 3.21)
project(worker CXX)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

add_executable (worker
	system_monitor.cpp
	heartbeat_client.cpp
	worker_main.cpp
)

target_link_libraries (worker PRIVATE
	heartbeat_proto
)

if(WIN32)
  target_link_libraries(worker PRIVATE pdh psapi)
endif()

find_package(GTest CONFIG REQUIRED)

target_link_libraries(worker PRIVATE
	GTest::gtest
	GTest::gtest_main
	GTest::gmock
	GTest::gmock_main
)

add_subdirectory(tests)

enable_testing()