#version 430

layout (location = 0) in vec3 aPos;

void main()
{
	gl_Position = vec4(aPos, 1);
}