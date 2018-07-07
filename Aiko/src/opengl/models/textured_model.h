#pragma once

#include <GL/glew.h>

#include "raw_model.h"
#include "../textures/model_texture.h"

namespace opengl
{

    class TexturedModel
    {
    public:
        TexturedModel(RawModel* model, ModelTexture* texture);
        ~TexturedModel();

        RawModel* getModel() const;
        ModelTexture* getTexture() const;

    private:
        RawModel *      m_model;
        ModelTexture*   m_texture;
    };

}