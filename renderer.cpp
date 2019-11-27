//
// Created by rsalogub on 26.11.19.
//

#include "renderer.h"

namespace FROpenGLWrapper
{
    Renderer* Renderer::instance_ = nullptr;

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

    Renderer *Renderer::getRenderer()
    {
        if (instance_ == nullptr)
        {
            instance_ = new Renderer();
        }
        return instance_;
    }
}