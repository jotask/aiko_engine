#include "loader.h"

#include <GL/glew.h>

#include <cassert>

namespace opengl
{

    Loader::Loader()
    {

    }

    Loader::~Loader()
    {
        for (const auto& vao : m_vaos) glDeleteVertexArrays(1, &vao);
        for (const auto& vbo : m_vbos) glDeleteBuffers(1, &vbo);
    }

    RawModel* Loader::loadToVao(std::vector<GLfloat>& positions, std::vector<GLuint>& indices)
    {
        GLuint vao;
        vao = createVao();

        bindIndicesVbo(indices);

        storeDataInAttributeList(0, positions);
        unbindVao();
        return new RawModel(vao, indices.size());
    }

    GLuint Loader::createVao()
    {
        GLuint vao;
        m_vaos.push_back(vao);
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        return vao;
    }

    void Loader::storeDataInAttributeList(int attributteNUmber, std::vector<float>& data)
    {
        GLuint vbo;
        m_vbos.push_back(vbo);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        //glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 6, vertexData, GL_STATIC_DRAW);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * data.size(), &data[0], GL_STATIC_DRAW);
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(attributteNUmber, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    }

    void Loader::unbindVao()
    {
        glBindVertexArray(0);
    }


    void Loader::bindIndicesVbo(std::vector<GLuint>& indices)
    {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        m_vbos.push_back(vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 1 * indices.size(), &indices[0], GL_STATIC_DRAW);
    }

}