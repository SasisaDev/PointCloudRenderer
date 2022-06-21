#include "Shader.h"

#include <GL/glew.h>

void Shader::CompileShader(std::string shaderName)
{
	std::string vertShaderPath = shaderName + ".vert";
	std::string fragShaderPath = shaderName + ".frag";

	std::string vertShaderCodeStr = Shader::ReadFile(vertShaderPath);
	std::string fragShaderCodeStr = Shader::ReadFile(fragShaderPath);

	const char* vertShaderCode = vertShaderCodeStr.c_str();
	const char* fragShaderCode = fragShaderCodeStr.c_str();

	vertShaderID = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShaderID, 1, &vertShaderCode, NULL);
	glCompileShader(vertShaderID);

	GLint vertex_compiled;
	glGetShaderiv(vertShaderID, GL_COMPILE_STATUS, &vertex_compiled);
	if (vertex_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[2048];
		glGetShaderInfoLog(vertShaderID, 2048, &log_length, message);

		Logger::Log(message);
	}

	fragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShaderID, 1, &fragShaderCode, NULL);
	glCompileShader(fragShaderID);

	GLint fragment_compiled;
	glGetShaderiv(fragShaderID, GL_COMPILE_STATUS, &fragment_compiled);
	if (fragment_compiled != GL_TRUE)
	{
		GLsizei log_length = 0;
		GLchar message[2048];
		glGetShaderInfoLog(fragShaderID, 2048, &log_length, message);

		Logger::Log(message);
	}

	programID = glCreateProgram();

	glAttachShader(programID, vertShaderID);
	glAttachShader(programID, fragShaderID);
	glLinkProgram(programID);

	GLint program_linked;
	glGetProgramiv(programID, GL_LINK_STATUS, &program_linked);
	if (program_linked != GL_TRUE)
	{
		Logger::Log("Failed linking shader: \"" + shaderName + "\"");
		GLsizei log_length = 0;
		GLchar message[1024];
		glGetProgramInfoLog(programID, 1024, &log_length, message);
		Logger::Log(message);
		return;
	}
	
	Logger::Log("Linked shader: \"" + shaderName + "\"");
}

std::string Shader::ReadFile(std::string shaderName)
{
	std::ifstream file(shaderName);

	if (file.is_open())
	{
		std::stringstream ss;
		std::string line;
		while (getline(file, line))
		{
			ss << line << "\n";
		}
		
		file.close();
		return ss.str();
	}
	return "";
}
