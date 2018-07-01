#pragma once

#include <GL/glew.h>

#include "rawModel.h"

namespace opengl
{

    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void prepare();

        void render(RawModel& model);

    };

}