#ifndef RENDERER_H
#define RENDERER_H

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer {
public:
    explicit Renderer(GLFWwindow* glfwWindow);
    ~Renderer();

    void clear();
    void present() const;
private:
    GLFWwindow* glfwWindow;
};



#endif //RENDERER_H
