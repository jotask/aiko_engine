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
        RawModel& model = *texturedModel.getModel();
        glBindVertexArray(model.getVao());
        glEnableVertexAttribArray(0);

        // glDrawArrays(GL_TRIANGLES, 0, model.getVertexCount());
        glDrawElements(GL_TRIANGLES, model.getVertexCount(), GL_UNSIGNED_INT, 0);

        glDisableVertexAttribArray(0);
        glBindVertexArray(0);
    }

}