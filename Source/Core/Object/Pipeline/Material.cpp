#include "Material.h"

SMaterial::SMaterial(std::string name, std::string shaderPath)
	: SObject(name)
{
	_Shader = new Shader(shaderPath);
}
