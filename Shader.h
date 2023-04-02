#ifndef SHADER_H
#define SHADER_H

#include "Common.h"


typedef unsigned int ShaderID;

ReturnCode BuildShader(const char* vertexPath, const char* fragmentPath);
char* read_file(const char* filename);
#endif