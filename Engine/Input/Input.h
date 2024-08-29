#ifndef INPUT_H
#define INPUT_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Input {
public:
    explicit Input(GLFWwindow* glfwWindow);
    ~Input();

    void pollEvents();
    [[nodiscard]] bool isKeyPressed(int key) const;

private:
    GLFWwindow* glfwWindow;
};



#endif //INPUT_H
