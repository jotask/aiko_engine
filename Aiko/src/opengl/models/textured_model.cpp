#include "textured_model.h"

namespace opengl
{

    TexturedModel::TexturedModel(RawModel* model, ModelTexture* texture)
        : m_model(model)
        , m_texture(texture)
    {

    }

    TexturedModel::~TexturedModel()
    {

    }

    RawModel* TexturedModel::getModel() const
    {
        return m_model;
    }

    ModelTexture* TexturedModel::getTexture() const
    {
        return m_texture;
    }

}