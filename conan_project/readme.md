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