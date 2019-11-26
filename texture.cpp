//
// Created by rsalogub on 26.11.19.
//

#include "texture.h"
#include <GL/glew.h>
#include <iostream>
#include "3dparty/stb_image.h"

namespace FROpenGLWrapper
{
    Texture::Texture(const std::string &filepath)
    {
        glGenTextures(1, &id_);//std::cout << id_ << std::endl;
        glBindTexture(GL_TEXTURE_2D, id_);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_set_flip_vertically_on_load(true);
        int width, height, nrChannels;
        unsigned char *data = stbi_load(filepath.c_str(), &width, &height, &nrChannels, 0);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_2D, 0, (nrChannels == 3 ? GL_RGB : GL_RGBA) , width, height, 0, (nrChannels == 3 ? GL_RGB : GL_RGBA), GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
//            width_ = width;
//            height_ = height;
//            nrChannels_ = nrChannels;
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    Texture::~Texture()
    {
        std::cout << __func__;
        glDeleteTextures(1, &id_);
    }


//    void Texture::bind(const unsigned int unit)
//    {
//        unit_ = unit;
//        glActiveTexture(GL_TEXTURE0 + unit);
//        glBindTexture(GL_TEXTURE_2D, id_);
//    }

}