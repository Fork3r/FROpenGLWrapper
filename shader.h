//
// Created by rsalogub on 27.11.19.
//

#ifndef FR_OPENGL_SHADER_H
#define FR_OPENGL_SHADER_H

#include <string>
#include <unordered_map>
#include <FRMath/vector2.h>
#include <FRMath/vector3.h>
#include <FRMath/vector4.h>
#include <FRMath/matrix4.h>

namespace FROpenGLWrapper
{
    class Shader
    {
    public:
        Shader(const std::string &vertexPath, const std::string &fragmentPath);

        void setBool(const std::string &name, bool value);
        void setInt(const std::string &name, int value);
        void setFloat(const std::string &name, float value);
        void setVector2f(const std::string &name, const FRMath::Vector2<float> &vector2);
        void setVector3f(const std::string &name, const FRMath::Vector3<float> &vector3);
        void setVector4f(const std::string &name, const FRMath::Vector4<float> &vector4);
        void setMatrix4f(const std::string &name, const FRMath::Matrix4<float> &matrix4);

    private:
        uint id_;
        std::unordered_map<std::string, int> UniformLocations_;

        void compile(const std::string &vertexCode, const std::string &fragmentCode);
        static uint createShader(unsigned int type, const char *shaderCode);

        int getUniformLocation(const std::string &name);
    };
}

#endif //FR_OPENGL_SHADER_H
