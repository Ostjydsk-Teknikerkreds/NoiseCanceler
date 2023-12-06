set(MODULE simulation)

add_executable(${MODULE}
    main.cpp
)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

target_link_libraries(${MODULE}
    PUBLIC
        python3.10
        domain::domain
)