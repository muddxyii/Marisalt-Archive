//
// Created by muddxyii on 8/28/24.
//

#include "Renderer.h"

Renderer::Renderer(GLFWwindow *glfwWindow) : glfwWindow(glfwWindow) {}


Renderer::~Renderer() = default;

void Renderer::clear() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::present() const {
    glfwSwapBuffers(glfwWindow);
}
