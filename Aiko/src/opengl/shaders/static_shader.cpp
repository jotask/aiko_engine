#include "static_shader.h"

#include <string>

namespace aiko
{

    StaticShader::StaticShader()
        : ShaderProgram("vertex.txt", "fragment.txt", this)
    {

    }

    StaticShader::~StaticShader()
    {

    }

    void StaticShader::bindAttributes()
    {
        ShaderProgram::bindAttribute(0u, "position");
    }

}