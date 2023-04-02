#include "Shader.h"
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


ReturnCode BuildShader(const char* vertexPath, const char* fragmentPath)
{
    // Reads Vertex Code
    char* vertexCode = NULL;
    if (getShaderCode(vertexPath, &vertexCode) != SUCCESS)
    {
        // propagate
        return FAILED;
    }

    //// Reads Fragment Code
    //char* FragmentCode = NULL;
    //if (getShaderCode(fragmentPath, &FragmentCode) != SUCCESS)
    //{
    //    // propagate
    //    return FAILED;
    //}
    //
    //unsigned int vertex, fragment;
    //int success;
    //char infoLog[512];
    //
    //// vertex Shader
    //vertex = glCreateShader(GL_VERTEX_SHADER);
    //glShaderSource(vertex, 1, &vertexCode, NULL);
    //glCompileShader(vertex);

}