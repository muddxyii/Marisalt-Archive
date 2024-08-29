#include "Input.h"

Input::Input(GLFWwindow* glfwWindow) : glfwWindow(glfwWindow) {};

Input::~Input() = default;

void Input::pollEvents() {
    glfwPollEvents();
}

bool Input::isKeyPressed(const int key) const {
    return glfwGetKey(glfwWindow, key) == GLFW_PRESS;
}
