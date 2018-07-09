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

        static const float textureCoords[];

    private:
        const GLuint m_textureId;
    };

}