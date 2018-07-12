#include "renderer.h"

#include <cassert>

namespace opengl
{

    Renderer::Renderer()
        : m_rendering(false)
    {

    }

    Renderer::~Renderer()
    {

    }

    void Renderer::prepare()
    {

        if (m_rendering == true)
        {
            assert(true);
            assert(false);
        }

        m_rendering = true;

        glClearColor(1, 0, 0, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        //// test
        if(true)
        {
            // this enables alpha

            glDisable(GL_DEPTH_TEST);

            glDepthMask(GL_FALSE);

            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        }
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
        glEnable(GL_TEXTURE_2D);

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

    void Renderer::end()
    {
        if (m_rendering == false)
        {
            assert(true);
            assert(false);
        }

        glEnable(GL_DEPTH_TEST);
        glDisable(GL_BLEND);
        glDepthMask(GL_TRUE);
        glEnable(GL_LIGHTING);

        m_rendering = false;

    }

}