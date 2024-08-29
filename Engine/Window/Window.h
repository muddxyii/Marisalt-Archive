#ifndef WINDOW_H
#define WINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <ostream>
#include <iostream>
#include <memory>


class Window {
public:
    Window(int width, int height, const char* title);
    ~Window();

    [[nodiscard]] GLFWwindow* getGLFWWindow() const;

    void setWindowSize(int width, int height) const;

    [[nodiscard]] bool shouldClose() const;
private:
    GLFWwindow* glfwWindow;
};



#endif //WINDOW_H
