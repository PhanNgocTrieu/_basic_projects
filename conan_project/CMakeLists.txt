cmake_minimum_required(VERSION 3.15)
project(prasor_c)

find_package(ZLIB REQUIRED)
add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} ZLIB::ZLIB)