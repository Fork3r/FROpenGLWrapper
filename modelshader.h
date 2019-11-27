//
// Created by rsalogub on 27.11.19.
//

#ifndef FR_OPENGL_MODELSHADER_H
#define FR_OPENGL_MODELSHADER_H

#include "shader.h"
#include "texture.h"

namespace FROpenGLWrapper
{
    class MainShader : public Shader
    {
    public:
        MainShader(const std::string &vertexPath, const std::string &fragmentPath);

        void setTexture(const Texture &texture);
        void setModel(const FRMath::Matrix4<float> &model);
    };
}

#endif //FR_OPENGL_MODELSHADER_H
