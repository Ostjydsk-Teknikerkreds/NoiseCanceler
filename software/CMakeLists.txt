cmake_minimum_required (VERSION 3.16)

include(third-party/pico-sdk/pico_sdk_init.cmake)

project (NoiseCanceler CXX C ASM)

pico_sdk_init()

include(cmake/build_unittests.cmake)

add_subdirectory (src)
add_subdirectory (third-party)
add_subdirectory(test)