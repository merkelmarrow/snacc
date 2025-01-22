# master/CMakeLists.txt

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
find_package(magic_enum CONFIG REQUIRED)

# If using pthread explicitly on Linux (sometimes needed)
if(UNIX AND NOT APPLE)
  set(THREADS_PREFER_PTHREAD_FLAG ON)
  find_package(Threads REQUIRED)
endif()

add_library (heartbeat_proto STATIC
	${CMAKE_CURRENT_SOURCE_DIR}/../proto/heartbeat.pb.cc
	${CMAKE_CURRENT_SOURCE_DIR}/../proto/heartbeat.grpc.pb.cc
	${CMAKE_CURRENT_SOURCE_DIR}/../secrets/secrets.h
)

target_include_directories (heartbeat_proto PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/../proto
	${CMAKE_CURRENT_SOURCE_DIR}/../Secrets
	${Protobuf_INCLUDE_DIRS}
)

target_link_libraries (heartbeat_proto PUBLIC
	ZLIB::ZLIB
	protobuf::libprotobuf
	gRPC::grpc
	gRPC::grpc++
	gRPC::grpc++_reflection
	magic_enum::magic_enum
)

# Link pthread if on Linux
if(UNIX AND NOT APPLE)
  target_link_libraries(heartbeat_proto PRIVATE Threads::Threads)
endif()

if(WIN32)
  target_link_libraries(heartbeat_proto PUBLIC pdh psapi)
endif()

add_executable (master
	master_main.cpp
	master_service_impl.cpp
)

target_link_libraries (master PRIVATE
	heartbeat_proto
)

add_compile_definitions(
    SERVER_KEY_PATH=\"${MY_SERVER_KEY_PATH}\"
    SERVER_CRT_PATH=\"${MY_SERVER_CRT_PATH}\"
    SERVER_ROOT_CERTS=\"${MY_SERVER_ROOT_CERTS}\"
    MASTER_VPN_IP=\"${MY_MASTER_VPN_IP}\"
    MASTER_PUBLIC_IP=\"${MY_MASTER_PUBLIC_IP}\"
    MASTER_GRPC_PORT=\"${MY_MASTER_GRPC_PORT}\"
)

#### Example CMAke build
#cmake -DCUSTOM_SERVER_KEY_PATH="/custom/path/to/server.key" \
#      -DCUSTOM_SERVER_CRT_PATH="/custom/path/to/server.crt" \
#      -DCUSTOM_SERVER_ROOT_CERTS="/custom/path/to/ca.crt" \
#      -DCUSTOM_MASTER_VPN_IP="192.168.1.1" \
#      -DCUSTOM_MASTER_PUBLIC_IP="203.0.113.1" \
#      -DCUSTOM_MASTER_GRPC_PORT="60051" ..
