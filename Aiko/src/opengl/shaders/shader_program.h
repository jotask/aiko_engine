#pragma once

#include <string>

#include <GL/glew.h>

namespace aiko
{

    class ShaderProgram
    {
    public:
        ShaderProgram(std::string vertex, std::string fragment);
        ~ShaderProgram();

        const GLuint getProgramId() const;

        void start() const;
        void stop() const;

        void endInit();

        virtual void bindAttributes() = 0;

        void bindAttribute(unsigned int attribute, const char* var);

        const GLuint m_programId;

        bool isFinishedSetUp;

    };

}