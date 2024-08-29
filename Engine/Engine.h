#ifndef ENGINE_H
#define ENGINE_H

#include "Input/Input.h"
#include "Renderer/Renderer.h"
#include "Window/Window.h"

struct FPSTracker {
    double lastTime = 0.0;
    int frameCount = 0;
    int targetFPS = 60;
    bool vsyncEnabled = false;
};

class Engine {
public:
    Engine(int windowWidth, int windowHeight, const char* windowTitle);
    ~Engine();

    Window& getWindow();
    Renderer& getRenderer();
    Input& getInput();

    void setVSync(bool enable);
    void setTargetFPS(int fps);
    void capFPS() const;
    void updateFPS();
private:
    Window window;
    Renderer renderer;
    Input input;

    FPSTracker fpsTracker;
};

#endif //ENGINE_H
