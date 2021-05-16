#version 330 core

layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in float brightness;

out vec4 vertex_color;
out float vertex_brightness;

void main()
{
    gl_Position = position;
    vertex_color = color;
    vertex_brightness = brightness;
}