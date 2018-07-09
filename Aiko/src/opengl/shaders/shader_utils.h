#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cassert>
#include <GL/glew.h>

namespace aiko
{

    class ShaderUtils
    {

    public:

        static std::string slurp(std::ifstream& in)
        {
            // thank you (: https://stackoverflow.com/a/116220/6872881
            return static_cast<std::stringstream const&>(std::stringstream() << in.rdbuf()).str();
        }

        static std::string loadFile(const std::string& f)
        {
            std::ifstream file(f);
            std::string out = slurp(file);
            file.close();
            return out;
        }

        static GLuint loadShader(const std::string&vertex, const std::string&fragment)
        {
            GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
            GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

            // Read shaders
            std::string vertShaderStr = loadFile(vertex);
            std::string fragShaderStr = loadFile(fragment);
            const char *vertShaderSrc = vertShaderStr.c_str();
            const char *fragShaderSrc = fragShaderStr.c_str();

            GLint result = GL_FALSE;
            int logLength;

            // Compile vertex shader
            glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
            glCompileShader(vertShader);

            // Check vertex shader
            glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
            glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
            std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
            glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
            if (vertShaderError.size() > 1) std::cout << "Compiling vertex shader :: " << &vertShaderError[0] << std::endl;

            // Compile fragment shader
            glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
            glCompileShader(fragShader);

            // Check fragment shader
            glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
            glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
            std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
            glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
            if (fragShaderError.size() > 1) std::cout << "Compiling fragment shader :: " << fragShaderError.size() << &fragShaderError[0] << std::endl;

            GLuint program = glCreateProgram();
            glAttachShader(program, vertShader);
            glAttachShader(program, fragShader);
            glLinkProgram(program);

            glGetProgramiv(program, GL_LINK_STATUS, &result);
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
            std::vector<char> programError((logLength > 1) ? logLength : 1);
            glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
            if(programError.size() > 1) std::cout << "Linking program :: " << &programError[0] << std::endl;

            glDeleteShader(vertShader);
            glDeleteShader(fragShader);

            return program;
        }

    private:
        ShaderUtils();
    };

}