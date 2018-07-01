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

    RawModel* Loader::loadToVao(std::vector<float>& positions)
    {
        // vao and vbo handle
        GLuint vao;
        vao = createVao();

        storeDataInAttributeList(0, positions);

        unbindVao();
        return new RawModel(vao, positions.size() / 3);
    }

    RawModel* Loader::createModel(std::vector<GLfloat> positions)
    {
        // vao and vbo handle
        GLuint vao, vbo;

        // generate and bind the vao
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // generate and bind the buffer object
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        /*
        // data for a fullscreen quad
        GLfloat vertexData[] = {
            //  X     Y     Z           R     G     B
            1.0f, 1.0f, 0.0f,       1.0f, 0.0f, 0.0f, // vertex 0
            -1.0f, 1.0f, 0.0f,       0.0f, 1.0f, 0.0f, // vertex 1
            1.0f,-1.0f, 0.0f,       0.0f, 0.0f, 1.0f, // vertex 2
            1.0f,-1.0f, 0.0f,       0.0f, 0.0f, 1.0f, // vertex 3
            -1.0f, 1.0f, 0.0f,       0.0f, 1.0f, 0.0f, // vertex 4
            -1.0f,-1.0f, 0.0f,       1.0f, 0.0f, 0.0f, // vertex 5
        }; // 6 vertices with 6 components (floats) each
        */

           // fill with data
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 6, &positions[0], GL_STATIC_DRAW);

        // set up generic attrib pointers
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (char*)0 + 0 * sizeof(GLfloat));

        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (char*)0 + 3 * sizeof(GLfloat));

        return new RawModel(vao, 6);
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

}