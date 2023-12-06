enable_testing()
include(CTest)

add_compile_options(
    -DCPPUTEST
)

if(CMAKE_COMPILER_IS_GNUCXX)
#set(CODE_COVERAGE_VERBOSE FALSE)
# include(cmake/CodeCoverage.cmake)
#APPEND_COVERAGE_COMPILER_FLAGS()
#setup_target_for_coverage_lcov(
#    NAME coverage
#    EXECUTABLE ctest
    # EXCLUDE "${PROJECT_SOURCE_DIR}/src/dir1/*" "/path/to/my/src/dir2/*"
#    )
#setup_target_for_coverage_gcovr_text(
#    NAME coverage_text
#    EXECUTABLE ctest
    # EXCLUDE "${PROJECT_SOURCE_DIR}/src/dir1/*" "/path/to/my/src/dir2/*"
#    )
endif()