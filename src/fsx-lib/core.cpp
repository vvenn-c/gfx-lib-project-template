#include "fsx.hpp"

void fsx::Core::initSDL() {

    if (!SDL_Init(SDL_INIT_VIDEO))
        throw std::runtime_error("failed to initialize SDL");
    else Utils::log("SDL initialized");

}

void fsx::Core::initVulkan() {



}

void fsx::Core::mainLoop() {

    while (!fsx::shouldAppClose) {

        if (Window::openWindows.empty()) {

            Utils::log("all windows closed, terminating application..");
            fsx::shouldAppClose = true;

        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            for (auto *window : Window::openWindows)
                window->pollEvents(event);
        }

        fsx::loop();

        for (auto *window : Window::openWindows)
            window->applyProperties();

    }

}

void fsx::Core::cleanup() {

    

}