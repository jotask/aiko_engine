#pragma once

#include "shader_program.h"

namespace opengl
{

    class StaticShader : public ShaderProgram
    {
    public:
        StaticShader();
        ~StaticShader();

        void bindAttributes();
    };

}