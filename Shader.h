#ifndef SHADER_H
#define SHADER_H

#include "Common.h"


typedef unsigned int ShaderID;

ReturnCode BuildShader(const char* vertexPath, const char* fragmentPath, unsigned* ID);

void Use(unsigned ID);

//void SetBool(const char* name, int value, unsigned ID);
void SetInt(const char* name, int value, unsigned ID);
void SetFloat(const char* name, float value, unsigned ID);
#endif