cmake_minimum_required(VERSION 3.10)
project(github_request)

include_directories(Protocols)

set(SRC Protocols/Socket.h
        Protocols/Socket.cpp
)
add_executable(github_requestor main.cpp ${SRC})

# (github_requestor std=c++11 -Wall)