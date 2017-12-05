//
// Created by lukas on 2017-12-05.
//

#ifndef CODE_SYSTEM_H
#define CODE_SYSTEM_H

#include "SDL.h"
namespace gameEngine {
    class Window {
    public:
        Window();
        ~Window();
        SDL_Renderer* getGameRenderer() const;


    private:
        SDL_Window* gameWindow;
        SDL_Renderer* gameRenderer;
    };
}

#endif //CODE_SYSTEM_H
