#include "gfx.hpp"

void gfx::Core::initSDL() {

    if (!SDL_Init(SDL_INIT_VIDEO))
        throw std::runtime_error("failed to initialize SDL");
    else Utils::log("SDL initialized");

}

void gfx::Core::initVulkan() {



}

void gfx::Core::mainLoop() {

    while (!gfx::shouldAppClose) {

        if (Window::openWindows.empty())
            gfx::shouldAppClose = true;

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            for (auto *window : Window::openWindows)
                window->pollEvents(event);
        }

        gfx::loop();

        for (auto *window : Window::openWindows)
            window->applyProperties();

    }

}

void gfx::Core::cleanup() {

    

}