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

    private:

        std::vector<GLuint> m_vaos;
        std::vector<GLuint> m_vbos;

        GLuint createVao();

        void storeDataInAttributeList(int attributteNUmber, std::vector<float>& data);

        void unbindVao();


    };

}