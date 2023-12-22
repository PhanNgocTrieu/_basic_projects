echo "[Start]"

# ~/Qt/6.5.2/macos/bin/qt-cmake CMakeLists.txt
COMPILER="/Users/tpn/Qt/6.5.2/macos/bin/qt-cmake "
FILE_PATH_CMAKE="../CMakeLists.txt"

# Run main application
# ~/Qt/6.5.2/macos/bin/qml ./test-app/main.qml

if ! [ -d "${PWD}/build" ]; then
    echo "Found"
    mkdir build
fi

cd build
$COMPILER "../CMakeLists.txt"
make

# DEFAULT="Users/tpn"
if [ -d "/Users/tpn/Qt/6.5.2" ]; then
    echo "Found"
fi

# Executed File: ./build/apptest-app.app/Contents/MacOS/apptest-app

echo "[End]"