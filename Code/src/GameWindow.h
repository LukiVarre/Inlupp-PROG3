#ifndef CODE_SYSTEM_H
#define CODE_SYSTEM_H

#include "SDL.h"
#include "iostream"

class GameWindow {
public:
    GameWindow(int width, int height);

    ~GameWindow();

    SDL_Window *getWindow() const;

    SDL_Renderer *getRenderer() const;


private:
    SDL_Window *gameWindow;
    SDL_Renderer *gameRenderer;
};

#endif //CODE_SYSTEM_H
