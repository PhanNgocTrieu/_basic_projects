cmake_minimum_required(VERSION 3.16)
project(Game_Programming LANGUAGES CXX)

include_directories(src)
find_package(SFML 2.5.1 COMPONENTS window system graphics audio REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)