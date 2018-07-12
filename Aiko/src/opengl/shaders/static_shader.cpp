#include "static_shader.h"

#include <string>

namespace opengl
{

    static const std::string PATH = "C:\\Users\\Jose\\Code\\aiko_engine\\Aiko\\src\\opengl\\shaders\\";

    StaticShader::StaticShader()
        : ShaderProgram(PATH + "vertex.txt", PATH + "fragment.txt")
    {
        bindAttributes();
        ShaderProgram::endInit();
    }

    StaticShader::~StaticShader()
    {

    }

    void StaticShader::bindAttributes()
    {
        ShaderProgram::bindAttribute(0u, "position");
        ShaderProgram::bindAttribute(1u, "textureCoords");
    }

}