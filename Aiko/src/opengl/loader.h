#pragma once

#include <vector>

#include "rawModel.h"

namespace opengl
{

    class Loader
    {
    public:
        Loader();
        ~Loader();

        RawModel* loadToVao(std::vector<float>& position);

        RawModel* createModel(std::vector<GLfloat> positions = {
            //  X     Y     Z           R     G     B
            1.0f, 1.0f, 0.0f,       1.0f, 0.0f, 0.0f, // vertex 0
            -1.0f, 1.0f, 0.0f,       0.0f, 1.0f, 0.0f, // vertex 1
            1.0f,-1.0f, 0.0f,       0.0f, 0.0f, 1.0f, // vertex 2
            1.0f,-1.0f, 0.0f,       0.0f, 0.0f, 1.0f, // vertex 3
            -1.0f, 1.0f, 0.0f,       0.0f, 1.0f, 0.0f, // vertex 4
            -1.0f,-1.0f, 0.0f,       1.0f, 0.0f, 0.0f, // vertex 5
            });

    private:

        std::vector<GLuint> m_vaos;
        std::vector<GLuint> m_vbos;

        GLuint createVao();

        void storeDataInAttributeList(int attributteNUmber, std::vector<float>& data);

        void unbindVao();


    };

}