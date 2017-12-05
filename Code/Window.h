//
// Created by lukas on 2017-12-05.
//

#ifndef INLUPP_PROG3_WINDOW_H
#define INLUPP_PROG3_WINDOW_H

#include "SDL.h"

namespace gameEngine {
    class Window {
    public:
        Window();
        ~Window();
        SDL_Renderer* get_gameRenderer() const;

    private:
        SDL_Window* gameWindow;
        SDL_Renderer* gameRenderer;
    };
}

#endif //INLUPP_PROG3_WINDOW_H
