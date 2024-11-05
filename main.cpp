#include <SDL.h>
#include <iostream>
#include "Cloth.h"

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    } else {
        std::cout << "SDL initialized successfully!" << std::endl;
    }

    // Create a new window
    SDL_Window *win = SDL_CreateWindow("ClothSimTest1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (win == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    } else {
        std::cout << "Window created successfully!" << std::endl;
    }

    // Create a Renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(win);
        SDL_Quit();
        return 1;
    }

    Cloth cloth(10,10,10.0f);
    cloth.initializeCloth(cloth, 10, 10, 10.0f);


    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_Delay(16); // Delay to cap the frame rate

        // Clear the screen with the background color
        SDL_RenderClear(renderer);

        // Set color for cloth particles and lines (for example, white)
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);



        // Present the updated renderer contents to the screen
        SDL_RenderPresent(renderer);

        // Reset the draw color to the background color for the next frame
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background

        // Delay to cap frame rate (optional)
        SDL_Delay(16);
    }

    SDL_DestroyWindow(win);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    return 0;
}
