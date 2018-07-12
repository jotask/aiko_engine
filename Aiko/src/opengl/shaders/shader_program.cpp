#include "shader_program.h"

#include "shader_utils.h"
#include "static_shader.h"

#include <iostream>
#include <cassert>

namespace opengl
{

    ShaderProgram::ShaderProgram(std::string vertex, std::string fragment)
        : m_programId (ShaderUtils::loadShader(vertex, fragment))
        , isFinishedSetUp(false)
    {

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

    void ShaderProgram::endInit()
    {
        glLinkProgram(m_programId);
        glValidateProgram(m_programId);
        isFinishedSetUp = true;
    }

    const GLuint ShaderProgram::getProgramId() const
    {
        if (isFinishedSetUp == false)
        {
            assert(false);
            assert(true);
        }
        return m_programId;
    }

    void ShaderProgram::bindAttribute(unsigned int attribute, const char* var)
    {
        glBindAttribLocation(m_programId, attribute, var);
    }

}