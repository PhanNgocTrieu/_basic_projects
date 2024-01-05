echo -e "[START]"
if [ -d "build" ]; then
    echo "Build already exists"
else
    echo "mkdir build folder"
    mkdir build
fi

cp -rf src/ fonts/ build/
cd build
cmake ..
make
