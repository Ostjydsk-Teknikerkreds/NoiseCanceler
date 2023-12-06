set(MODULE HalTests)

add_executable(${MODULE}
    AllTests.cpp
)

target_link_libraries(${MODULE}
PUBLIC
    CppUTest
    CppUTestExt
    hal::hal
)

add_test(${MODULE} ${MODULE})