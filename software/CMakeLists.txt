cmake_minimum_required (VERSION 3.16)

if(${CMD_BUILD_PLATFORM} MATCHES "target")
    include(third-party/pico-sdk/pico_sdk_init.cmake)
    project (NoiseCanceler CXX C ASM)
    pico_sdk_init()
elseif(${CMD_BUILD_PLATFORM} MATCHES "simulations")
    project (NoiseCancelerSimulation CXX C ASM)
endif()

include(cmake/build_unittests.cmake)

add_subdirectory (src)
add_subdirectory (third-party)
add_subdirectory(test)