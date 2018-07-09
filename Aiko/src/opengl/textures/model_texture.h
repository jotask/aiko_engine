#pragma once

#include <GL/glew.h>

#include <vector>

namespace opengl
{

    class ModelTexture
    {
    public:
        ModelTexture(GLuint id);
        ~ModelTexture();

        const GLuint getId() const;

        static std::vector<float> textureCoords;

    private:
        const GLuint m_textureId;
    };

}