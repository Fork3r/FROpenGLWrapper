//
// Created by rsalogub on 26.11.19.
//

#ifndef FR_OPENGL_RENDERER_H
#define FR_OPENGL_RENDERER_H

#include <set>
#include <memory>
#include "model.h"
#include "shader.h"
#include "vertexarray.h"
#include "boost/signals2.hpp"

namespace FROpenGLWrapper
{
    class Renderer
    {
    public:
        static Renderer* getRenderer();
        void addModel(Model *renderModel);
        void removeModel(Model *renderModel);

    private:
        static Renderer* instance_;

        std::unique_ptr<VertexArray> vertexArray_;
        std::shared_ptr<Shader> shader_;
        std::set<Model*> Models_;

        Renderer() = default;
        void step(FRMath::timeType);
        boost::signals2::signal<void ()> signalDraw_;
    };
}
#endif //FR_OPENGL_RENDERER_H
