#include "Engine.h"
#include <chrono>
#include <thread>

Engine::Engine(const int windowWidth, const int windowHeight, const char *windowTitle): window(windowWidth,
                                                                                               windowHeight, windowTitle), renderer(window.getGLFWWindow()), input(window.getGLFWWindow()) {
    setVSync(true);
}

Engine::~Engine() = default;

Window& Engine::getWindow() {
    return window;
}

Renderer & Engine::getRenderer() {
    return renderer;
}

Input & Engine::getInput() {
    return input;
}

void Engine::setVSync(const bool enable) {
    fpsTracker.vsyncEnabled = enable;
    glfwSwapInterval(fpsTracker.vsyncEnabled ? 1 : 0);
}

void Engine::setTargetFPS(const int fps) {
    fpsTracker.targetFPS = fps;
}

void Engine::capFPS() const {
    if (!fpsTracker.vsyncEnabled) {
        const double currentTime = glfwGetTime();
        const double frameTime = currentTime - fpsTracker.lastTime;
        const double targetFrameTime = 1.0 / fpsTracker.targetFPS;

        if (frameTime > targetFrameTime) {
            const double sleepTime = targetFrameTime - frameTime;
            std::this_thread::sleep_for(std::chrono::duration<double>(sleepTime));
        }
    }
}

void Engine::updateFPS() {
    const double currentTime = glfwGetTime();
    fpsTracker.frameCount++;
    if (currentTime - fpsTracker.lastTime >= 1.0) {
        std::cout << "FPS: " << fpsTracker.frameCount << std::endl;
        fpsTracker.frameCount = 0;
        fpsTracker.lastTime = currentTime;
    }
}
