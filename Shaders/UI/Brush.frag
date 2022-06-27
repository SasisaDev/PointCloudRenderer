#version 330

in vec2 fragUV;

layout(std430, binding = 3) buffer BrushSSBO
{
    vec4 Tint;
    mat4 Model;
};

uniform sampler2D Texture;

void main()
{
    //gl_FragColor = Tint * texture(Texture, fragUV);
    gl_FragColor = vec4(1, 1, 1, 1);
}