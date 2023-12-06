cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD_INCLUDE_DIRECTORIES ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 11)

project ("CPP EXAMPLE PROJECT")
include(cmake/build_unittests.cmake)

add_subdirectory (src)
add_subdirectory (third-party)
add_subdirectory(test)

if(${CMD_BUILD_PLATFORM} MATCHES "unittests")
elseif(${CMD_BUILD_PLATFORM} MATCHES "WINDOWS")
    include(cmake/build_windows.cmake)
    message(STATUS "Still WINDOWS")
endif()