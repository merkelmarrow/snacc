# worker/CMakeLists.txt

cmake_minimum_required (VERSION 3.21)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

add_executable (worker
	system_monitor.hpp
	system_monitor.cpp
	heartbeat_client.hpp
 "heartbeat_client.cpp")

target_link_libraries (worker PRIVATE
	heartbeat_proto
)

# Copy SSL certificates to build directory
# add_custom_command(TARGET worker POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#        ${CMAKE_SOURCE_DIR}/certs/ca.crt
#        ${CMAKE_SOURCE_DIR}/certs/client.crt
#        ${CMAKE_SOURCE_DIR}/certs/client.key
#        $<TARGET_FILE_DIR:worker>
#)