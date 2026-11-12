#include "gfx.hpp"

void gfx::Core::initSDL() {

    if (!SDL_Init(SDL_INIT_VIDEO))
        gfx::Utils::showError("SDL initialization failed");

}

void gfx::Core::initVulkan() {



}

void gfx::Core::mainLoop() {

    while (!gfx::shouldAppClose) {

        if (gfx::Window::openWindows.empty())
            gfx::shouldAppClose = true;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            for (auto *window : gfx::Window::openWindows)
                window->pollEvents(event);
        }

        gfx::loop();

        for (auto *window : gfx::Window::openWindows)
            window->applyProperties();

    }

}

void gfx::Core::cleanup() {

    

}