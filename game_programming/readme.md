# List commands of conan project
* [profile]: conan profile detect (--force) <br>
    This command would show the profile of operation system

* [install]: conan install . --output-folder=<folder_output> --build=missing [--settings=build_type=Debug]<br> 
    <!-- To build project with cmake and setting build-type to debug  -->
    This command would install conan independent package in folder <folder_ouput> and "--build=missing" would make directory when missing <folder_output>

* [Build]: Follow the instructions <br>
    - cd build <br> 
    - cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release <br>
    - cmake --build .

* [SMFL]: Install package
    [Dependencies]: libxkbfile-dev libxmuu-dev libxres-dev libxcb-render-util0-dev libxcb-xkb-dev libxcb-icccm4-dev libxcb-image0-dev libxcb-keysyms1-dev libxcb-randr0-dev libxcb-shape0-dev libxcb-sync-dev libxcb-xfixes0-dev libxcb-xinerama0-dev libxcb-dri3-dev libxcb-cursor-dev
    
    sudo apt-get install libx11-dev libx11-xcb-dev libfontenc-dev libice-dev libsm-dev libxau-dev libxaw7-dev libxcb-util-dev