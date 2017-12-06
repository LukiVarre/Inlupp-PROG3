#include "GameWindow.h"

GameWindow::GameWindow() {
    SDL_Window *gameWindow = nullptr;
    SDL_Renderer *gameRenderer = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "Video Initialization Error: " << SDL_GetError() << std::endl;
    else {
        gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
                                      SDL_WINDOW_SHOWN);
        gameRenderer = SDL_CreateRenderer(gameWindow, -1, 0);
        SDL_SetRenderDrawColor(gameRenderer, 0, 250, 0, 255);
        if (gameWindow == NULL)
            std::cout << "Window Creation Error: " << SDL_GetError() << std::endl;
        else {
            SDL_UpdateWindowSurface(gameWindow);
            SDL_Delay(4000);
        }
    }
}

GameWindow::~GameWindow() {
    SDL_DestroyWindow(gameWindow);
    SDL_DestroyRenderer(gameRenderer);
    SDL_Quit();
}

SDL_Window *GameWindow::getWindow() const {
    return gameWindow;
}

SDL_Renderer *GameWindow::getGameRenderer() const {
    return gameRenderer;
}


