#include "rawModel.h"

namespace opengl
{

    RawModel::RawModel(GLuint vao, size_t vertexCount)
    {
        m_vaoID = vao;
        m_vertexCount = vertexCount;
    }


    RawModel::~RawModel()
    {

    }

    GLint        RawModel::getVao()           const { return m_vaoID; }
    unsigned int RawModel::getVertexCount()   const { return m_vertexCount; }

}