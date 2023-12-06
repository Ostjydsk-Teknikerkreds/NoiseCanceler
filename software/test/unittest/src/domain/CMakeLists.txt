set(MODULE DomainTests)

add_executable(${MODULE}
    AllTests.cpp
)

target_link_libraries(${MODULE}
PUBLIC
    CppUTest
    CppUTestExt
    domain::domain
)

add_test(${MODULE} ${MODULE})