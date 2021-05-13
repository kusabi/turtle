#version 330 core

in vec4 gl_FragCoord ;
out vec4 color;

void main()
{
    vec2 screenSpace = normalize(abs(gl_FragCoord.xy));
    vec2 inverted = vec2(0.5, 1) - screenSpace;
    color = vec4(inverted.xy, 1, 1);
}