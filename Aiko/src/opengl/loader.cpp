#include "loader.h"

#include <GL/glew.h>

#include <cassert>

namespace opengl
{

    Loader::Loader()
    {

    }

    Loader::~Loader()
    {
        for (const auto& vao : m_vaos) glDeleteVertexArrays(1, &vao);
        for (const auto& vbo : m_vbos) glDeleteBuffers(1, &vbo);
    }

    RawModel* Loader::loadToVao(std::vector<GLfloat>& positions, std::vector<GLuint>& indices)
    {
        GLuint vao;
        vao = createVao();

        bindIndicesVbo(indices);

        storeDataInAttributeList(0, positions);
        unbindVao();
        return new RawModel(vao, indices.size());
    }

    GLuint Loader::createVao()
    {
        GLuint vao;
        m_vaos.push_back(vao);
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        return vao;
    }

    void Loader::storeDataInAttributeList(int attributteNUmber, std::vector<float>& data)
    {
        GLuint vbo;
        m_vbos.push_back(vbo);
        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        //glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 6, vertexData, GL_STATIC_DRAW);
        glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 3 * data.size(), &data[0], GL_STATIC_DRAW);
        
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(attributteNUmber, 3, GL_FLOAT, GL_FALSE, 0, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);

    }

    void Loader::unbindVao()
    {
        glBindVertexArray(0);
    }


    void Loader::bindIndicesVbo(std::vector<GLuint>& indices)
    {
        GLuint vbo;
        glGenBuffers(1, &vbo);
        m_vbos.push_back(vbo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 1 * indices.size(), &indices[0], GL_STATIC_DRAW);
    }

    GLuint Loader::loadTexture(std::string& filename)
    {
        // Data read from the header of the BMP file
        unsigned char header[54]; // Each BMP file begins by a 54-bytes header
        unsigned int dataPos;     // Position in the file where the actual data begins
        unsigned int width, height;
        unsigned int imageSize;   // = width*height*3
                                  // Actual RGB data
        unsigned char * data;

        FILE * file = fopen(filename.c_str(), "rb");
        if (!file) { printf("Image could not be opened\n"); return 0; }

        // The first thing in the file is a 54 - bytes header.
        // It contains information such as “Is this file really a BMP file ? ”,
        // the size of the image, the number of bits per pixel, etc.So let’s read this header
        if (fread(header, 1, 54, file) != 54) { // If not 54 bytes read : problem
            printf("Not a correct BMP file\n");
            return false;
        }

        // So we have to check that the two first bytes are really ‘B’ and ‘M’ :
        if (header[0] != 'B' || header[1] != 'M') {
            printf("Not a correct BMP file\n");
            return 0;
        }

        //Now we can read the size of the image, the location of the data in the file, etc :
        // Read ints from the byte array
        dataPos = *(int*)&(header[0x0A]);
        imageSize = *(int*)&(header[0x22]);
        width = *(int*)&(header[0x12]);
        height = *(int*)&(header[0x16]);

        //We have to make up some info if it’s missing :
        // Some BMP files are misformatted, guess missing information
        if (imageSize == 0)    imageSize = width * height * 3; // 3 : one byte for each Red, Green and Blue component
        if (dataPos == 0)      dataPos = 54; // The BMP header is done that way

        // Now that we know the size of the image, we can allocate some memory to read the image into, and read :
        // Create a buffer
        data = new unsigned char[imageSize];

        // Read the actual data from the file into the buffer
        fread(data, 1, imageSize, file);

        //Everything is in memory now, the file can be closed
        fclose(file);

        // Create one OpenGL texture
        GLuint textureID;
        glGenTextures(1, &textureID);

        // "Bind" the newly created texture : all future texture functions will modify this texture
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Give the image to OpenGL
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        m_textures.push_back(textureID);

        return textureID;


    }

}