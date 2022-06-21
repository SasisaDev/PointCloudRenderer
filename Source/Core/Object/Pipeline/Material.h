#pragma once

#include "../Object.h"
#include "../../Renderer/Shader/Shader.h"

class SMaterial : public SObject
{
protected:
	Shader* _Shader;
public:
	SMaterial(std::string name) : SObject(name) { _Shader = nullptr; }
	SMaterial(std::string name, Shader* shader) : SObject(name) { _Shader = shader; }
	SMaterial(std::string name, std::string shaderPath);
public:
};