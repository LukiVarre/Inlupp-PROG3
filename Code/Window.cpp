//
// Created by lukas on 2017-12-05.
//

#include "Window.h"
#include "SDL.h"

namespace gameEngine{

    Window::Window() {
        SDL_Init(SDL_INIT_EVERYTHING);
        gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        gameRenderer = SDL_CreateRenderer(gameWindow, -1, 0);
        SDL_Delay(5000);
    }

    Window::~Window() {
        SDL_DestroyWindow(gameWindow);
        SDL_DestroyRenderer(gameRenderer);
        SDL_Quit();
    }

    SDL_Renderer* Window::get_gameRenderer() const {
        return gameRenderer;
    }
}
