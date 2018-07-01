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

        RawModel* loadToVao(std::vector<GLfloat>& positions, std::vector<GLuint>& indices);

    private:

        std::vector<GLuint> m_vaos;
        std::vector<GLuint> m_vbos;

        GLuint createVao();

        void storeDataInAttributeList(int attributteNUmber, std::vector<GLfloat>& data);

        void unbindVao();

        void bindIndicesVbo(std::vector<GLuint>& indices);


    };

}