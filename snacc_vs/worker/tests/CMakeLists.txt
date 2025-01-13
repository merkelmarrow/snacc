cmake_minimum_required(VERSION 3.21)

project(worker_tests CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Collect test sources
file(GLOB TEST_SOURCES
    "test_*.cpp"
    "mock_heartbeat_service.hpp"
)

add_executable(worker_tests ${TEST_SOURCES})

target_link_libraries(worker_tests PRIVATE
	heartbeat_proto
	GTest::gtest
	GTest::gtest_main
	GTest::gmock
	GTest::gmock_main
)

enable_testing()
add_test(NAME worker_tests COMMAND worker_tests)