set(MODULE ControllerTests)

add_executable(${MODULE}
    AllTests.cpp
)

target_link_libraries(${MODULE}
PUBLIC
    CppUTest
    CppUTestExt
    controller::controller
)

add_test(${MODULE} ${MODULE})