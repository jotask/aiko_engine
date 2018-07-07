#pragma once

#include <GL/glew.h>

#include "models/raw_model.h"
#include "models/textured_model.h"

namespace opengl
{

    class Renderer
    {
    public:
        Renderer();
        ~Renderer();

        void prepare();

        void render(RawModel& model);

        void render(TexturedModel& model);

    };

}