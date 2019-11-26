//
// Created by rsalogub on 26.11.19.
//

#ifndef FR_OPENGL_TEXTURE_H
#define FR_OPENGL_TEXTURE_H

#include <string>

namespace FROpenGLWrapper
{
    class Texture
    {
    public:
        Texture(const std::string &texturePath);
        ~Texture();

    private:
        uint id_ = 0;
        int unit_ = -1;
    };
}

#endif //FR_OPENGL_TEXTURE_H
