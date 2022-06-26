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

	~SMaterial();
public:

	unsigned int GetProgramID() { return _Shader->GetProgramID(); }

	void SetUniform1f(std::string name, float f);
	void SetUniform2f(std::string name, float f1, float f2);
	void SetUniform3f(std::string name, float f1, float f2, float f3);
	void SetUniform4f(std::string name, float f1, float f2, float f3, float f4);

	void SetUniform1i(std::string name, int i);
	void SetUniform2i(std::string name, int i1, int i2);
	void SetUniform3i(std::string name, int i1, int i2, int i3);
	void SetUniform3i(std::string name, int i1, int i2, int i3, int i4);

	void Use();
	void Unuse();
};