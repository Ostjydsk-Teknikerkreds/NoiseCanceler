#! /bin/bash

dryrun=""
while getopts "d" options; do
    case "$options" in
        d)  dryrun="1";;
        ?)  printf "Usage: %s: [-d]\n" $0
            exit 2;;
    esac
done

build_output_dir=.cmake_build_unittests
toolchain_file=cmake/build_unittests.cmake
threads=8

cmake_options=()
cmake_options+=(-DCMAKE_BUILD_TYPE:STRING=Debug)
cmake_options+=(-DCMAKE_EXPORT_COMPILE_COMMANDS=1)
cmake_options+=(-DCMAKE_VERBOSE_MAKEFILE:BOOL=FALSE)
cmake_options+=(-DCMD_BUILD_PLATFORM:STRING=unittests)
cmake_options+=(-DCMAKE_TOOLCHAIN_FILE=${toolchain_file})

mkdir -p ${build_output_dir}
cd ${build_output_dir}
cmake ${cmake_options[@]} .. || exit $?
if [ -z "$dryrun" ]; then
    cmake --build . -- -j ${threads} || exit $?
#    cmake --build . --target coverage coverage_text || exit $?
fi

./../.cmake_build_unittests/test/unittest/unittest