#include "gfx.hpp"

void gfx::Core::initVulkan() {



}

void gfx::Core::mainLoop() {

    while (!gfx::shouldAppClose) {

        SDL_Event event;
        while (SDL_PollEvent(&event)) {

            if (event.type == SDL_EVENT_QUIT)
                gfx::shouldAppClose = true;

        }

        gfx::loop();

    }

}

void gfx::Core::cleanup() {

    

}