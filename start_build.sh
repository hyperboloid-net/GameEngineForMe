PWD=`pwd`
if [ -d "$PWD/build" ]; then
    echo "build dir is exist, start removing"
    rm -rf build
fi

mkdir build && cd build
cmake ..
make -j2


