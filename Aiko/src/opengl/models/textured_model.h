#pragma once

#include <GL/glew.h>

#include "raw_model.h"
#include "../textures/texture.h"

namespace opengl
{

    class TexturedModel
    {
    public:
        TexturedModel(RawModel* model, Texture* texture);
        ~TexturedModel();

        RawModel* getModel() const;
        Texture* getTexture() const;

    private:
        RawModel *      m_model;
        Texture*        m_texture;
    };

}