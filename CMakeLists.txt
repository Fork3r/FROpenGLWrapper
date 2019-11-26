cmake_minimum_required(VERSION 3.13)
project(FROpenGLWrapper)

set(CMAKE_CXX_STANDARD 17)

set(header
        ${header}
        renderer.h
        model.h
        texture.h
        )

set(src
        ${src}
        renderer.cpp
        model.cpp
        texture.cpp
        )

add_executable(FRMath main.cpp ${header} ${src})