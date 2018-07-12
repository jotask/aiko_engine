#include "renderer.h"

namespace opengl
{

    Renderer::Renderer()
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::prepare()
    {
        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);
    }

    void Renderer::render(RawModel& model)
    {
        glBindVertexArray(model.getVao());
        glEnableVertexAttribArray(0);

        // glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
        glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }

    void Renderer::render(TexturedModel& texturedModel)
    {
        // tell opengl which texture we want to render
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texturedModel.getTexture()->getId());

        RawModel& model = *texturedModel.getModel();
        glBindVertexArray(model.getVao());
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        // glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
        glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glBindVertexArray(0);
    }

}