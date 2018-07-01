#pragma once

#include <GL/glew.h>

namespace opengl
{

    class RawModel
    {
    public:
        RawModel(GLuint vao, unsigned int vertexCount);
        ~RawModel();

        GLint        getVao()           const;
        unsigned int getVertexCount()   const;

    private:

        GLuint        m_vaoID;
        unsigned int  m_vertexCount;

    };

}