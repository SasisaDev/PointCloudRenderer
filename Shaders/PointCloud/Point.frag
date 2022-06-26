#version 430

in vec4 fragColor;
in vec2 uv;

uniform sampler2D tex;

void main()
{
    vec4 circle = texture(tex, uv);
    if(circle.a < 0.1)
        discard;
    gl_FragColor = vec4(1, 1, 1, 1);
}