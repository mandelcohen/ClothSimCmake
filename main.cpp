#include <SDL.h>
#include <iostream>


struct Particle {
    glm::vec2 position;       // Current position
    glm::vec2 previousPosition; // For Verlet integration
    glm::vec2 acceleration;    // Acceleration due to gravity or other forces
    float inverseMass;         // Used to apply constraints (0 for pinned particles)
};


int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    } else {
        std::cout << "SDL initialized successfully!" << std::endl;
    }

    SDL_Window *win = SDL_CreateWindow("Hello SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (win == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    } else {
        std::cout << "Window created successfully!" << std::endl;
    }

    SDL_Event e;
    bool quit = false;
    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }
        SDL_Delay(16); // Delay to cap the frame rate
    }

    SDL_DestroyWindow(win);
    SDL_Quit();
    return 0;
}
