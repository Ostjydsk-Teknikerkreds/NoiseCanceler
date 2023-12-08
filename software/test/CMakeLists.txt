
#add_subdirectory(unittest)

if(${CMD_BUILD_PLATFORM} MATCHES "simulations")
    add_subdirectory(simulations)
endif()