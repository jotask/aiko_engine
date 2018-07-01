#include "rawModel.h"

namespace opengl
{

    RawModel::RawModel(GLuint vao, unsigned int vertexCount)
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