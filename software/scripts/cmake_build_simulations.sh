#! /bin/bash

dryrun=""
while getopts "d" options; do
    case "$options" in
        d)  dryrun="1";;
        ?)  printf "Usage: %s: [-d]\n" $0
            exit 2;;
    esac
done

build_output_dir=.cmake_build_simulations
threads=8

cmake_options=()
cmake_options+=(-DCMAKE_BUILD_TYPE:STRING=Debug)
cmake_options+=(-DCMAKE_VERBOSE_MAKEFILE:BOOL=FALSE)
cmake_options+=(-DCMD_BUILD_PLATFORM:STRING=simulations)

mkdir -p ${build_output_dir}
cd ${build_output_dir}
cmake ${cmake_options[@]} .. || exit $?
if [ -z "$dryrun" ]; then
    cmake --build . -- -j ${threads} || exit $?
fi
