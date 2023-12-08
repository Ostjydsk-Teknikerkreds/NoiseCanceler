build_output_dir=build

cmake_options=()
#cmake_options+=(-DCMAKE_BUILD_TYPE:STRING=Debug)
#cmake_options+=(-DCMAKE_VERBOSE_MAKEFILE:BOOL=FALSE)
cmake_options+=(-DCMD_BUILD_PLATFORM:STRING=target)

mkdir -p ${build_output_dir}
cd ${build_output_dir}
cmake -G Ninja ${cmake_options[@]} ..
ninja