#include "Shader.h"
#include <malloc.h>
#include <stdio.h>
#include <glad/glad.h>


ReturnCode getShaderCode(const char* shaderPath, char** code)
{
    FILE* textfile = fopen(shaderPath, "r");
    if (textfile == NULL)
    {
        // log to err File
        return FAILED;
    }

    // get the number of bytes from shaderPath so we can read it in one go
    fseek(textfile, 0L, SEEK_END);
    const long numbytes = ftell(textfile);
    fseek(textfile, 0L, SEEK_SET);

    // alloc enough memory for the entire shader source code
    *code = (char*)malloc(numbytes + 1);
    if (*code == NULL) {
        // log to err File
        fclose(textfile);
        return FAILED;
    }
    
    int read_size = fread(*code, 1, numbytes, textfile);
    (*code)[read_size] = '\0';
    fclose(textfile);

    return SUCCESS;
}


ReturnCode BuildShader(const char* vertexPath, const char* fragmentPath, unsigned* ID)
{
    // Reads Vertex Code
    char* vertexCode = NULL;
    if (getShaderCode(vertexPath, &vertexCode) != SUCCESS)
    {
        // propagate
        return FAILED;
    }

    // Reads Fragment Code
    char* fagmentCode = NULL;
    if (getShaderCode(fragmentPath, &fagmentCode) != SUCCESS)
    {
        // propagate
        return FAILED;
    }
    
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexCode, NULL);
    glCompileShader(vertex);

    // print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s", infoLog);
    };

    // fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fagmentCode, NULL);
    glCompileShader(fragment);

    // print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s", infoLog);
    };

    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    // print linking errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        printf("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n%s", infoLog);
    }

    // delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(vertex);
    glDeleteShader(fragment);

    free(vertexCode);
    free(fagmentCode);
}

void Use(unsigned ID)
{
    glUseProgram(ID);
}

void SetBool(const char* name, unsigned ID, int value)
{
    glUniform1i(glGetUniformLocation(ID, name), value);
}

void SetFloat(const char* name, float value, unsigned ID)
{
    glUniform1f(glGetUniformLocation(ID, name), value);
}