rm -rf build

mkdir build

cd build

cmake -G 'Unix Makefiles' -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=../raspi-toolchain.cmake ..
make -j$(nproc)

cd ..