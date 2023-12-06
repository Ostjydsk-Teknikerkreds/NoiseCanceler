set(MODULE InfrastructureTests)

add_executable(${MODULE}
    AllTests.cpp
)

target_link_libraries(${MODULE}
PUBLIC
    CppUTest
    CppUTestExt
    infrastructure::infrastructure
)

add_test(${MODULE} ${MODULE})