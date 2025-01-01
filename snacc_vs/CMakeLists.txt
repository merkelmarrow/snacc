# CMakeList.txt : CMake project for snacc_vs, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("snacc_vs")


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

find_package(Protobuf CONFIG REQUIRED)

# Compile the generated .pb.cc file
add_library(student_proto student.pb.cc)
target_include_directories(student_proto PUBLIC ${Protobuf_INCLUDE_DIRS})
target_link_libraries(student_proto PUBLIC protobuf::libprotobuf)


# The main executable
add_executable (snacc_vs snacc_vs.cpp)
target_link_libraries(snacc_vs PRIVATE student_proto)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET snacc_vs PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
