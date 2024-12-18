#include "SDLWindow.h"
#include "Cloth.h"

int main(int argc, char* argv[]) {
    int windowWidth = 640;
    int windowHeight = 480;
    SDLWindow window(windowWidth, windowHeight);

    Cloth cloth(10, 10, 20.0f, 0.98f);

    /*
    Cloth FlannelTweed = {
            .spacing =
            .dampingFactor =
    };

    Garment playerCape = new Garment(60, 180, FlannelTweed);
    playerCape.fixPoint(point, worldPosition);
    */

    const float deltaTime = 0.033f;

    bool running = true;

    while (running) {
        running = window.handleEvents();

        cloth.applyForces(deltaTime);
        cloth.integrateMotion(deltaTime, windowWidth, windowHeight);
        cloth.enforceConstraints(5);

        window.Render(cloth);

        SDL_Delay(16);
    }
    return 0;
}
