#pragma once

#include <GL/glew.h>

namespace opengl
{

    class ModelTexture
    {
    public:
        ModelTexture(GLuint id);
        ~ModelTexture();

        const GLuint getId() const;

    private:
        const GLuint m_textureId;
    };

}