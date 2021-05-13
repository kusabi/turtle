#version 330 core

layout(location = 0) in vec4 position;

out vec4 screen_position;

void main()
{
    screen_position = position / position.w;
    gl_Position = position;
}