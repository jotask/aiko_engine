#pragma once

#include <GL/glew.h>
#include <memory>

#include "raw_model.h"
#include "../textures/texture.h"

namespace opengl
{

    class TexturedModel
    {
    public:
        TexturedModel(std::unique_ptr<RawModel>& model, std::unique_ptr<Texture>& texture);
        ~TexturedModel();

        RawModel* getModel() const;
        Texture* getTexture() const;

    private:

        std::unique_ptr<RawModel> m_model;
        std::unique_ptr<Texture> m_texture;

    };

}