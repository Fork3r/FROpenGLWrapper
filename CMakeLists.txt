cmake_minimum_required(VERSION 3.13)
project(FROpenGLWrapper)

set(CMAKE_CXX_STANDARD 17)

set(header
        ${header}
        ${FR_OPENGL_WARPPER_PATH}/renderer.h
        ${FR_OPENGL_WARPPER_PATH}/model.h
        ${FR_OPENGL_WARPPER_PATH}/texture.h
        ${FR_OPENGL_WARPPER_PATH}/3dparty/stb_image.h
        )

set(src
        ${src}
        ${FR_OPENGL_WARPPER_PATH}/renderer.cpp
        ${FR_OPENGL_WARPPER_PATH}/model.cpp
        ${FR_OPENGL_WARPPER_PATH}/texture.cpp
        ${FR_OPENGL_WARPPER_PATH}/3dparty/stb_image.cpp
        )

set(libraries
        ${libraries}
        GL
        GLEW
        )
#add_executable(FRMath main.cpp ${header} ${src})