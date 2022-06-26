#version 330

in vec2 fragUV;

uniform sampler2D Texture;
uniform vec4 Tint;

void main()
{
    gl_FragColor = Tint * texture(Texture, fragUV);
}