#include "Material.h"

#include <GL/glew.h>

SMaterial::SMaterial(std::string name, std::string shaderPath)
	: SObject(name)
{
	_Shader = new Shader(shaderPath);
}

void SMaterial::Use()
{
	glUseProgram(_Shader->GetProgramID());
}
