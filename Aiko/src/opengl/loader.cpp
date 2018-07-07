#include "loader.h"

#include <cassert>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <png.h>
#include <GL/glew.h>

#include <GL/glew.h>

namespace opengl
{

    Loader::Loader()
    {

    }

    Loader::~Loader()
    {
        for (const auto& vao : m_vaos) glDeleteVertexArrays(1, &vao);
        for (const auto& vbo : m_vbos) glDeleteBuffers(1, &vbo);
        for (const auto& text : m_textures) glDeleteTextures(1, &text);
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

    static unsigned char* load_image_new(const char* filename, int* w, int* h)
    {
        FILE* fp = fopen(filename, "rb");

        if (fp == NULL)
        {
            fprintf(stderr, "ERROR: cannot open texture file '%s'\n", filename);
            return NULL;
        }

        int x, y;

        png_structp readStruct;
        png_infop info;
        char header[8];
        unsigned char* buf;

        fread(header, 1, 8, fp);
        if (png_sig_cmp(header, 0, 8) != 0)
        {
            fprintf(stderr, "ERROR: file '%s' is not a PNG file\n", filename);
            fclose(fp);
            return NULL;
        }

        // We did not set error pointers or error handling codes (setjmp..)
        // If there're some problems in the PNG file, the application will be
        // killed (by OS).
        readStruct = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);

        info = png_create_info_struct(readStruct);

        png_set_read_fn(readStruct, fp, my_read);

        png_set_sig_bytes(readStruct, 8);

        png_read_info(readStruct, info);

        *w = png_get_image_width(readStruct, info);
        *h = png_get_image_height(readStruct, info);

        if (power_of_2(*w) == false || power_of_2(*h) == false)
        {
            fprintf(stderr, "WARNING: texture have non-power-of-2 dimensions (width or height)\n");
        }

        if (png_get_color_type(readStruct, info) != PNG_COLOR_TYPE_RGB_ALPHA
            || png_get_bit_depth(readStruct, info) != 8)
        {
            fprintf(stderr, "WARNING: color type or bit depth not as expected");
            png_destroy_read_struct(&readStruct, &info, NULL);
            return NULL;
        }

        buf = malloc(*w * *h * 4);
        unsigned char** rowPointers = malloc(sizeof(unsigned char*) * (*h));
        int i;
        // This causes the last row placed in the start of the buffer, 
        // as OpenGL's assumption.
        // i.e. OpenGL's texture driver assumes upside-down image be sent
        for (i = 0; i < (*h); i++)
        {
            rowPointers[(*h) - i - 1] = &buf[i * (*w) * 4];
        }

        png_read_image(readStruct, rowPointers);

        png_destroy_read_struct(&readStruct, &info, NULL);
        fclose(fp);
        free(rowPointers);
        return buf;
    }

    GLuint Loader::loadTexture(const std::string& filename)
    {

        // Create one OpenGL texture
        GLuint textureID;
        glGenTextures(1, &textureID);

        // "Bind" the newly created texture : all future texture functions will modify this texture
        glBindTexture(GL_TEXTURE_2D, textureID);

        // Give the image to OpenGL
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.get_width(), image.get_height(), 0, GL_BGR, GL_UNSIGNED_BYTE, );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

        m_textures.push_back(textureID);

        return textureID;


    }

}