#pragma once

#include <GL/glew.h>

#include <vector>

namespace opengl
{

    class Texture
    {
    public:
        Texture(GLuint id);
        ~Texture();

        const GLuint getId() const;

        static std::vector<float> textureCoords;

    private:
        const GLuint m_textureId;
    };

}