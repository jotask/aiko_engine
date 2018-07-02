#pragma once

#include <string>

#include <GL/glew.h>

namespace aiko
{
    class StaticShader;

    class ShaderProgram
    {
    public:
        ShaderProgram(std::string vertex, std::string fragment, StaticShader* something);
        ~ShaderProgram();

        const GLuint getProgramId() const;

        void start() const;
        void stop() const;

        virtual void bindAttributes() = 0;

        void bindAttribute(unsigned int attribute, const char* var);

        const GLuint m_programId;

    };

}