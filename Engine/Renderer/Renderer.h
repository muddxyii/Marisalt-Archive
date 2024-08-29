#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

// Basic vertex shader
    const std::string vertexShaderSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        void main() {
            gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
        }
    )";

// Basic fragment shader
const std::string fragmentShaderSource = R"(
        #version 330 core
        out vec4 FragColor;

        void main() {
            FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Red color
        }
    )";

class Renderer {
public:
    explicit Renderer(GLFWwindow* glfwWindow);
    ~Renderer();

    void clear();
    void present() const;
private:
    GLFWwindow* glfwWindow;
    GLuint shaderProgram;

    GLuint compileShader(GLenum shaderType, const std::string& shaderSource);
    GLuint createShaderProgram(const std::string& vertexSource, const std::string& fragmentSource);
};



#endif //RENDERER_H
