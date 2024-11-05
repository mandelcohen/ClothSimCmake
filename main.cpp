#include <SDL.h>
#include <iostream>
#include "SDLWindow.h"
#include "Cloth.h"

int main(int argc, char* argv[]) {
    SDLWindow window(640, 480);
    Cloth cloth(10, 10, 20.0f); // Example grid size and spacing

    bool running = true;
    while (running) {
        running = window.handleEvents();
        window.Clear();
        window.Render(cloth); // Render cloth each frame
        SDL_Delay(16); // Cap frame rate
    }



    return 0;
}
