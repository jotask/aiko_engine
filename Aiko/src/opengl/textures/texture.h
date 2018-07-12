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

    private:
        const GLuint m_textureId;
    };

}