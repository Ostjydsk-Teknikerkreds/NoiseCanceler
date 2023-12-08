#add_subdirectory(controller)
add_subdirectory(domain)


if(${CMD_BUILD_PLATFORM} MATCHES "target")
    add_subdirectory(application)
    #add_subdirectory(hal)
    add_subdirectory(infrastructure)
endif()