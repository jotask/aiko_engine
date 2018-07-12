#pragma once

#include <vector>
#include <memory>

#include "models/raw_model.h"

namespace opengl
{

    class Loader
    {
    public:
        Loader();
        ~Loader();

        std::unique_ptr<RawModel> loadToVao(std::vector<GLfloat>& positions, std::vector<GLuint>& indices, std::vector<float>& uvs);

        std::unique_ptr<RawModel> loadTest();

        GLuint loadTexture(const std::string& filename);

    private:

        std::vector<GLuint> m_vaos;
        std::vector<GLuint> m_vbos;
        std::vector<GLuint> m_textures;

        GLuint createVao();

        void storeDataInAttributeList(int attributteNUmber, const unsigned int dataSize, std::vector<GLfloat>& data);

        void unbindVao();

        void bindIndicesVbo(std::vector<GLuint>& indices);


    };

}