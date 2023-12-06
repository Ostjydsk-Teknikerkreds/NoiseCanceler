set(MODULE ApplicationTests)

add_executable(${MODULE}
    AllTests.cpp
)

target_link_libraries(${MODULE}
PUBLIC
    CppUTest
    CppUTestExt
    application::application
)

add_test(${MODULE} ${MODULE})