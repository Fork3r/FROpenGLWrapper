//
// Created by rsalogub on 26.11.19.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <set>
#include "model.h"

namespace FROpenGLWrapper
{
    class Renderer
    {
    public:
        void addModel(Model *renderModel);
        void removeModel(Model *renderModel);
    private:
        std::set<Model*> Models_;

        Renderer() = default;
    };
}
#endif //RENDERER_H
