# CMakeList.txt

cmake_minimum_required (VERSION 3.21)

project ("snacc")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

add_executable (PowershellRun main.cpp)

# find_package(tiny-process-library CONFIG REQUIRED)
# target_link_libraries(PowershellRun PRIVATE tiny-process-library::tiny-process-library)