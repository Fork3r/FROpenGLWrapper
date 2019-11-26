//
// Created by rsalogub on 26.11.19.
//

#ifndef FR_OPENGL_MODEL_H
#define FR_OPENGL_MODEL_H

#include <string>
#include <FRMath/vector2.h>

namespace FROpenGLWrapper
{
    class Model
    {
    public:
        Model& operator=(const Model&) = delete;
        Model(const Model&) = delete;

        Model(const std::string &texturePath, const FRMath::Vector2 &size);
    };
}

#endif //FR_OPENGL_MODEL_H
