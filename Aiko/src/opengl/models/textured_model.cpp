#include "textured_model.h"

namespace opengl
{

    TexturedModel::TexturedModel(RawModel* model, Texture* texture)
        : m_model(model)
        , m_texture(texture)
    {

    }

    TexturedModel::~TexturedModel()
    {
        delete m_model;
        delete m_texture;
    }

    RawModel* TexturedModel::getModel() const
    {
        return m_model;
    }

    Texture* TexturedModel::getTexture() const
    {
        return m_texture;
    }

}