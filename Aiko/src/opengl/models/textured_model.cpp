#include "textured_model.h"

namespace opengl
{

    TexturedModel::TexturedModel(std::unique_ptr<RawModel>& model, std::unique_ptr<Texture>& texture)
        : m_model(std::move(model))
        , m_texture(std::move(texture))
    {

    }

    TexturedModel::~TexturedModel()
    {
    }

    RawModel* TexturedModel::getModel() const
    {
        return m_model.get();
    }

    Texture* TexturedModel::getTexture() const
    {
        return m_texture.get();
    }

}