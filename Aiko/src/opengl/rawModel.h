#pragma once

#include <GL/glew.h>

namespace opengl
{

    class RawModel
    {
    public:
        RawModel(GLuint vao, size_t vertexCount);
        ~RawModel();

        GLint        getVao()           const;
        unsigned int getVertexCount()   const;

    private:

        GLuint        m_vaoID;
        size_t        m_vertexCount;

    };

}