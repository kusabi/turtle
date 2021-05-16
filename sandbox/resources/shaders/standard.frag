#version 330 core

in vec4 vertex_color;
in float vertex_brightness;
out vec4 color;

void main()
{
    color = vertex_color;// * vertex_brightness;
}