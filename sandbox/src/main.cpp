#include <fstream>
#include <iostream>
#include <sstream>

#include "Turtle.hpp"

using namespace std;
using namespace Turtle;

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

static unsigned int compileShader(unsigned int type, const std::string & source)
{
    unsigned int id = glCreateShader(type);
    const char * sec = source.c_str();
    glShaderSource(id, 1, &sec, nullptr);
    glCompileShader(id);

    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);
    if (result == GL_FALSE) {
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);

        char * message = (char *) alloca(length * sizeof(char));
        glGetShaderInfoLog(id, length, &length, message);

        cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << endl;
        cout << message << endl;

        glDeleteShader(id);
        return 0;
    }

    return id;
};

static unsigned int createShader(const std::string & vertexShader, const std::string & fragmentShader)
{
    unsigned int program = glCreateProgram();
    unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);

    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);
    glValidateProgram(program);

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

static unsigned int createShaderFromFiles(const std::string & vertexFile, const std::string & fragmentFile)
{
    ifstream vertex_file;
    vertex_file.open(vertexFile);
    stringstream vertex_file_stream;
    vertex_file_stream << vertex_file.rdbuf();
    string vertex_content = vertex_file_stream.str();

    ifstream fragment_file;
    fragment_file.open(fragmentFile);
    stringstream fragment_file_stream;
    fragment_file_stream << fragment_file.rdbuf();
    string fragment_content = fragment_file_stream.str();

    return createShader(vertex_content, fragment_content);
}

int main()
{
    GLFWwindow *window;

    // Setup the program
    if (!Program::init()) {
        return -1;
    }

    // Create the window and set the current context window
    window = glfwCreateWindow(800, 600, "OpenGL Playground", nullptr, nullptr);
    if (window == nullptr) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Setup OpenGL with GLAD
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Create a viewport
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Create the triangle buffer
    float positions[6] = {
        -1.0f, -1.0f,
        0.0f, 1.0f,
        1.0f, -1.0f
    };
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);

    // Build the shaders l
    unsigned int shader = createShaderFromFiles("resources/shaders/standard.vert", "resources/shaders/standard.frag");
    glUseProgram(shader);

    // Main gameplay loop
    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteProgram(shader);
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

