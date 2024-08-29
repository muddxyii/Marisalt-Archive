#include "Window.h"

Window::Window(const int width, const int height, const char *title) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    glfwWindow = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!glfwWindow) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        return;
    }

    glfwMakeContextCurrent(glfwWindow);

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return;
    }
}

Window::~Window() {
    if (glfwWindow) {
        glfwDestroyWindow(glfwWindow);
        glfwWindow = nullptr;
    }
    glfwTerminate();
}

GLFWwindow * Window::getGLFWWindow() const {
    return glfwWindow;
}

void Window::setWindowSize(const int width, const int height) const {
    glfwSetWindowSize(glfwWindow, width, height);
}

bool Window::shouldClose() const {
    return glfwWindowShouldClose(glfwWindow);
}
