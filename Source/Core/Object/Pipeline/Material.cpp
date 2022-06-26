#include "Material.h"

#include <GL/glew.h>

SMaterial::SMaterial(std::string name, std::string shaderPath)
	: SObject(name)
{
	_Shader = new Shader(shaderPath);
}

SMaterial::~SMaterial()
{
	delete _Shader;
}

void SMaterial::Use()
{
	glUseProgram(_Shader->GetProgramID());
}

void SMaterial::Unuse()
{
	glUseProgram(0);
}

void SMaterial::SetUniform4f(std::string name, float f1, float f2, float f3, float f4)
{
	glUniform4f(glGetUniformLocation(_Shader->GetProgramID(), name.c_str()), f1, f2, f3, f4);
}

void SMaterial::SetUniform1i(std::string name, int i)
{
	glUniform1i(glGetUniformLocation(_Shader->GetProgramID(), name.c_str()), i);
}
