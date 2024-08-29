#include "Engine/Engine.h"
#include "Engine/Window/Window.h"
#include "Engine/Renderer/Renderer.h"
#include "Engine/Input/Input.h"

int main() {
    Engine engine(1280, 720, "Marisalt: A Dark Fantasy Pirate RPG");

    while (!engine.getWindow().shouldClose()) {
        engine.getInput().pollEvents();
        if (engine.getInput().isKeyPressed(GLFW_KEY_ESCAPE)) {
            std::cout << "ESCAPE is pressed." << std::endl;
        }

        engine.getRenderer().clear();
        engine.getRenderer().present();

        engine.updateFPS();
        //engine.capFPS();
    }

    return 0;
}
