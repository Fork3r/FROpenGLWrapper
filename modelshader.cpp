//
// Created by rsalogub on 27.11.19.
//

#include "modelshader.h"

namespace MainShaderUniforms
{
    static constexpr char Texture[] = "texture";
    static constexpr char Model[] = "model";
}

namespace FROpenGLWrapper
{
    MainShader::MainShader(const std::string &vertexPath, const std::string &fragmentPath) : Shader(
            vertexPath, fragmentPath)
    {

    }

    void MainShader::setTexture(const Texture &texture)
    {
        setInt(MainShaderUniforms::Texture, texture.getUnit());
    }

    void MainShader::setModel(const FRMath::Matrix4<float> &model)
    {
        setMatrix4f(MainShaderUniforms::Model, model);
    }
}