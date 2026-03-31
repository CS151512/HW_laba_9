cmake_minimum_required(VERSION 4.0)
project(CS)

set(CMAKE_CXX_STANDARD 20)

add_executable(CS
        include/models.h
        include/stack_module.h
        include/deque_module.h
        include/queue_module.h
        src/main.cpp
        src/stack_module.cpp
        src/queue_module.cpp
        src/deque_module.cpp)
