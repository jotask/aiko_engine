#include "shader_program.h"

#include "shader_utils.h"
#include "static_shader.h"

#include <iostream>

namespace aiko
{

    ShaderProgram::ShaderProgram(std::string vertex, std::string fragment)
        : m_programId (ShaderUtils::loadShader(vertex, fragment))
    {
        glValidateProgram(m_programId);
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