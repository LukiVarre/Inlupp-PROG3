#include "GameWindow.h"

#define FPS 60

GameWindow::GameWindow(int width, int height) {
    SDL_Window *gameWindow = nullptr;
    SDL_Renderer *gameRenderer = nullptr;
    SDL_Surface *background = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "Video Initialization Error: " << SDL_GetError() << std::endl;
    else {
        gameWindow = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
        gameRenderer = SDL_CreateRenderer(gameWindow, -1, 0);
        background = SDL_LoadBMP("..//Content//Backgrounds//bg.bmp");
        SDL_Texture *bgTexture = SDL_CreateTextureFromSurface(gameRenderer, background);
        if (gameWindow == NULL)
            std::cout << "Window Creation Error: " << SDL_GetError() << std::endl;
        else {
            bool goOn = true;
            const int tickInterval = 1000 / FPS;
            while (goOn) {
                Uint32 nextTick = SDL_GetTicks() + tickInterval;
                SDL_Event eve;
                while (SDL_PollEvent(&eve)) {
                    switch (eve.type) {
                        case SDL_QUIT:
                            goOn = false;
                            break;
                        case SDL_KEYDOWN:
                            switch (eve.key.keysym.sym) {
                                case SDLK_ESCAPE:
                                    goOn = false;
                                    break;
                            }
                            break;
                    }
                }
                SDL_UpdateWindowSurface(gameWindow);
                SDL_RenderClear(gameRenderer);
                SDL_RenderCopy(gameRenderer, bgTexture, NULL, NULL);
                SDL_RenderPresent(gameRenderer);

                int delay = nextTick - SDL_GetTicks();
                if (delay > 0)
                    SDL_Delay(delay);
            }
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

SDL_Renderer *GameWindow::getRenderer() const {
    return gameRenderer;
}