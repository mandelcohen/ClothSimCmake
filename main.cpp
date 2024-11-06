#include "SDLWindow.h"
#include "Cloth.h"

int main(int argc, char* argv[]) {
    SDLWindow window(640, 480);
    Cloth cloth(10, 10, 20.0f, 0.99f);

    const float deltaTime = 0.033f;

    bool running = true;

    while (running) {
        running = window.handleEvents();

        cloth.applyForces(deltaTime);
        cloth.integrateMotion(deltaTime);
        cloth.enforceConstraints(3);

        window.Render(cloth);

        SDL_Delay(16); // Cap frame rate
    }

    return 0;
}
