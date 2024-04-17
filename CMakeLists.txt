cmake_minimum_required(VERSION 3.27)
project(testari)

set(CMAKE_CXX_STANDARD 17)

add_executable(testari main.cpp
        ProjectCpps/SharedData.cpp
        ProjectHeaders/SharedData.h
        ProjectCpps/ScreenIcon.cpp
        ProjectHeaders/ScreenIcon.h
        ProjectCpps/Bird.cpp
        ProjectHeaders/Bird.h
        ProjectCpps/Snake.cpp
        ProjectHeaders/Snake.h
        ProjectCpps/Metal.cpp
        ProjectHeaders/Metal.h
        ProjectCpps/UserInput.cpp
        ProjectHeaders/UserInput.h
        ProjectHeaders/InvalidInputException.h
)
