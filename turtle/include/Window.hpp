#ifndef TURTLE_PROJECT_WINDOW_HPP
#define TURTLE_PROJECT_WINDOW_HPP

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Turtle
{
    class Window
    {
        public:
            Window(int width, int height, const std::string & title);
        private:
            int width;
            int height;
            std::string title;
    };
}

#endif
