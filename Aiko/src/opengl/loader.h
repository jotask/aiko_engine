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

        GLuint loadTexture(std::string& filename);

    private:

        std::vector<GLuint> m_vaos;
        std::vector<GLuint> m_vbos;
        std::vector<GLuint> m_textures;

        GLuint createVao();

        void storeDataInAttributeList(int attributteNUmber, std::vector<GLfloat>& data);

        void unbindVao();

        void bindIndicesVbo(std::vector<GLuint>& indices);


    };

}