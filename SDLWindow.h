#ifndef CLOTHSIMCMAKE_SDLWINDOW_H
#define CLOTHSIMCMAKE_SDLWINDOW_H

#pragma once
#include <SDL.h>
#include <iostream>

class Cloth;

class SDLWindow {
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int windowWidth, windowHeight;

public:
    SDLWindow(int width, int height);
    ~SDLWindow();
    void Render(const Cloth& cloth);
    void Clear();
    bool handleEvents();
};




#endif //CLOTHSIMCMAKE_SDLWINDOW_H
