#pragma once

#include "shader_program.h"

namespace aiko
{

    class StaticShader : public ShaderProgram
    {
    public:
        StaticShader();
        ~StaticShader();

        void bindAttributes();
    };

}