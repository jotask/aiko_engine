#include "shader_program.h"

#include "shader_utils.h"
#include "static_shader.h"

#include <iostream>

namespace aiko
{

    ShaderProgram::ShaderProgram(std::string vertex, std::string fragment, StaticShader* something)
        : m_programId (ShaderUtils::loadShader(vertex, fragment))
    {
        std::cout << "hello" << std::endl;
        glValidateProgram(m_programId);
        something->bindAttributes();
    }

    ShaderProgram::~ShaderProgram()
    {
        stop();
        glDeleteProgram(m_programId);
    }

    void ShaderProgram::start() const
    {
        glUseProgram(m_programId);
    }

    void ShaderProgram::stop() const
    {
        glUseProgram(0);
    }

    const GLuint ShaderProgram::getProgramId() const
    {
        return m_programId;
    }

    void ShaderProgram::bindAttribute(unsigned int attribute, const char* var)
    {
        glBindAttribLocation(m_programId, attribute, var);
    }

}