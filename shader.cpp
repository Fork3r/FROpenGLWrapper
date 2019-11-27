//
// Created by rsalogub on 27.11.19.
//

#include <fstream>
#include <sstream>
#include <iostream>
#include <GL/glew.h>
#include "shader.h"

namespace FROpenGLWrapper
{
    Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
    {
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
        std::string vertexCode;
        std::string fragmentCode;
        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();
            vertexCode   = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch(std::ifstream::failure &e)
        {
            std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::flush;
        }
        compile(vertexCode, fragmentCode);
    }

    void Shader::compile(const std::string &vertexCode, const std::string &fragmentCode)
    {
        unsigned int vertex, fragment;
        int success;
        char infoLog[512];

        vertex = createShader(GL_VERTEX_SHADER, vertexCode.c_str());
        fragment = createShader(GL_FRAGMENT_SHADER, fragmentCode.c_str());
        id_ = glCreateProgram();
        glAttachShader(id_, vertex);
        glAttachShader(id_, fragment);
        glLinkProgram(id_);
        glGetProgramiv(id_, GL_LINK_STATUS, &success);
        if(!success)
        {
            glGetProgramInfoLog(id_, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        }

        glDeleteShader(vertex);
        glDeleteShader(fragment);
    }

    GLuint Shader::createShader(unsigned int type, const char *shaderCode)
    {
        int success;
        char infoLog[512];

        GLuint shader = glCreateShader(type);

        glShaderSource(shader, 1, &shaderCode, nullptr);
        glCompileShader(shader);
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if(!success)
        {
            glGetShaderInfoLog(shader, 512, nullptr, infoLog);
            std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") <<
            "VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
        }
        return shader;
    }

    int Shader::getUniformLocation(const std::string &name)
    {
        auto it = UniformLocations_.find(name);
        if (it == UniformLocations_.end()) {
            int location =  glGetUniformLocation(id_, name.c_str());
            UniformLocations_[name] = location;
            return location;
        } else {
            return it->second;
        }
    }
    
    void Shader::setBool(const std::string &name, bool value)
    {
        glUniform1i(getUniformLocation(name), static_cast<int>(value));
    }
    void Shader::setInt(const std::string &name, int value)
    {
        glUniform1i(getUniformLocation(name), value);
    }
    void Shader::setFloat(const std::string &name, float value)
    {
        glUniform1f(getUniformLocation(name), value);
    }

    void Shader::setVector2f(const std::string &name, const FRMath::Vector2<float> &vector2)
    {
        glUniform2f(getUniformLocation(name), vector2.getX(), vector2.getY());
    }

    void Shader::setVector3f(const std::string &name, const FRMath::Vector3<float> &vector3)
    {
        glUniform3f(getUniformLocation(name), vector3.getX(), vector3.getY(), vector3.getZ());
    }

    void Shader::setVector4f(const std::string &name, const FRMath::Vector4<float> &vector4)
    {
        glUniform4f(getUniformLocation(name), vector4.getX(), vector4.getY(), vector4.getZ(), vector4.getW());
    }

    void Shader::setMatrix4f(const std::string &name, const FRMath::Matrix4<float> &matrix4)
    {
        glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix4.getValues());
    }
}