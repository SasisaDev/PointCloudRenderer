#version 330

layout (location = 1) in vec2 UV;

uniform sampler2D Texture;
uniform vec4 Tint;

void main()
{
    // 236, 186, 73
    gl_FragColor = Tint * texture(Texture, UV);
}