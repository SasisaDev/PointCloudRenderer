#pragma once

#include <string>
#include <fstream>
#include "../../Debug/Logger.h"

class Shader
{
protected:
	unsigned int vertShaderID;
	unsigned int fragShaderID;

	unsigned int programID;
public:
	Shader(std::string shaderName) { CompileShader(shaderName); }

	void CompileShader(std::string shaderName);

	static std::string ReadFile(std::string shaderName);

	unsigned int GetProgramID() { return programID; }
};