set(MODULE CppExampleProject)

add_executable (${MODULE} "main.cpp")

if(WINDOWS)

    find_package(Threads REQUIRED)

    target_link_libraries(${MODULE}
    PUBLIC
    PRIVATE
        ws2_32
        -static-libstdc++
        -static-libgcc
        Threads::Threads -static
    )
endif()