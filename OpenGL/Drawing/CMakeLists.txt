cmake_minimum_required(VERSION 3.16)
project(opengl_drawer)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

if (GLEW_FOUND)
    include_directories($(GLEW_INCLUDE_DIRS))
endif()

add_executable(${PROJECT_NAME} main.cpp )

target_link_libraries(${PROJECT_NAME} OpenGL::GL glfw GLEW::GLEW ) #${GLEW_LIBRARIES})