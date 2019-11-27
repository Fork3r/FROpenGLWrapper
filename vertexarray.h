//
// Created by rsalogub on 27.11.19.
//

#ifndef VERTEXARRAY_H
#define VERTEXARRAY_H

#include <set>

namespace FROpenGLWrapper
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        VertexArray& operator=(const VertexArray&) = delete;
        VertexArray(const VertexArray&) = delete;

        void bind();
        unsigned int appendToVertexBuffer(unsigned int count, const void * data, unsigned int size);
        void freeVertexBuffer(unsigned int index);
        static void generateElementBuffer(const void * data, unsigned int size);

    private:
        unsigned int id_ = 0;
        unsigned int vbo_ = 0;
        unsigned int stride_ = 0;
        unsigned int count_ = 0;
        unsigned int vertexBufferSize_ = 2048;
        std::set<unsigned int> emptyBufferIndex_;

        void generateVertexBuffer();
        void expandBuffer();
    };
}

#endif //VERTEXARRAY_H
