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

	void SetUniform1f(float f);
	void SetUniform2f(float f1, float f2);
	void SetUniform3f(float f1, float f2, float f3);
	void SetUniform3f(float f1, float f2, float f3, float f4);

	void SetUniform1i(int f);
	void SetUniform2i(int f1, int f2);
	void SetUniform3i(int f1, int f2, int f3);
	void SetUniform3i(int f1, int f2, int f3, int f4);

	void Use();
};