#include "SDLWindow.h"
#include "Cloth.h"

SDLWindow::SDLWindow(int width, int height) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow("ClothSimTest!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (!renderer) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
}

SDLWindow::~SDLWindow() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


void SDLWindow::Render(const Cloth& cloth) {
    // Render particles and constraints from the cloth here
    for (const auto& particle : cloth.particles) {
        // Render each particle, for example:
        SDL_Rect rect;
        rect.x = static_cast<int>(particle.position.x);
        rect.y = static_cast<int>(particle.position.y);
        rect.w = rect.h = 5; // Small square for particle

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White color
        SDL_RenderFillRect(renderer, &rect);
    }

    // Render each constraint as a line (example)
    for (const auto& constraint : cloth.constraints) {
        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); // Light gray color
        SDL_RenderDrawLine(renderer,
                           static_cast<int>(constraint.p1->position.x),
                           static_cast<int>(constraint.p1->position.y),
                           static_cast<int>(constraint.p2->position.x),
                           static_cast<int>(constraint.p2->position.y));
    }
}


void SDLWindow::Clear() {
    SDL_RenderClear(renderer);
}

bool SDLWindow::handleEvents() {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            return false;
        }
    }
    return true;
}

