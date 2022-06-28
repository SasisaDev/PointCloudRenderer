#version 430

in vec4 fragColor;
in vec2 uv;

uniform sampler2D tex;

float CircleShape(float radius, vec2 position)
{
    float value = distance(position, vec2(0.1));
    return step(radius, value);
}

void main()
{
    vec2 pixelCoord = gl_FragCoord.xy;
    float CircleWidth = 0.1;
    float circle = CircleShape(CircleWidth, pixelCoord);
    vec4 color = vec4(circle, circle, circle, 1) * fragColor;
    gl_FragColor = color;
}