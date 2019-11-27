//
// Created by rsalogub on 27.11.19.
//

#include "vertexarray.h"
#include <iostream>
#include <GL/glew.h>

namespace FROpenGLWrapper
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &id_);
        glBindVertexArray(id_);


        generateVertexBuffer();

    }

    void VertexArray::bind()
    {
        glBindVertexArray(id_);
    }

    void VertexArray::generateVertexBuffer()
    {
        std::cout << std::endl << __func__ << std::endl;
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glGenBuffers(1, &vbo_);

        glBindBuffer(GL_ARRAY_BUFFER, vbo_);
        glBufferData(GL_ARRAY_BUFFER, vertexBufferSize_, nullptr, GL_DYNAMIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // texture coord attribute
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
    }

    void VertexArray::expandBuffer()
    {
        std::cout << "Expanding vertex buffer" << std::endl;
        vertexBufferSize_ *= 2;
        GLuint vbo = 0;
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_COPY_READ_BUFFER, vbo_);

        glBindBuffer(GL_COPY_WRITE_BUFFER, vbo);
        glBufferData(GL_COPY_WRITE_BUFFER, vertexBufferSize_, nullptr, GL_DYNAMIC_DRAW);

        glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, stride_);
        glBindBuffer(GL_COPY_WRITE_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindBuffer(GL_COPY_READ_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glDeleteBuffers(1, &vbo_);
        vbo_ = vbo;
    }

    GLuint VertexArray::appendToVertexBuffer(const GLuint count, const GLvoid * data, const GLuint size)
    {
        if (!emptyBufferIndex_.empty()) {
            std::cout << "reusing buffer" << std::endl;
            auto it = emptyBufferIndex_.begin();
            GLuint index = *it;
            glNamedBufferSubData(vbo_, index * 20, size, data);
            emptyBufferIndex_.erase(it);
            return index;
        }
        while (true) {
            if (stride_ + size > vertexBufferSize_) {
                expandBuffer();
            } else {
                break;
            }
        }
        std::cout << "count " << count << " size " << size << std::endl;
        glNamedBufferSubData(vbo_, stride_, size, data);
        stride_ += size;
        count_ += count;
        return count_ - count;
    }

    void VertexArray::generateElementBuffer(const GLvoid *data, const GLuint size)
    {
        unsigned int EBO;
        glGenBuffers(1, &EBO);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &id_);
    }

    void VertexArray::freeVertexBuffer(GLuint index)
    {
        emptyBufferIndex_.insert(index);
    }

}