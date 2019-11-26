//
// Created by rsalogub on 26.11.19.
//

#include "renderer.h"

namespace FROpenGLWrapper
{
    void Renderer::addModel(Model *renderModel)
    {
        Models_.insert(renderModel);
    }

    void Renderer::removeModel(Model *renderModel)
    {
        auto it = Models_.find(renderModel);
        if (it != Models_.end()) {
            Models_.erase(it);
        }
    }
}