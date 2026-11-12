#include <SDL3/SDL.h>

#include "gfx.hpp"

void gfx::Window::open() {

    // TODO: don't open if pointer already exists in openWindows

    SDL_WindowFlags flags = SDL_WINDOW_VULKAN;
    if (resizable) flags = flags | SDL_WINDOW_RESIZABLE;
    if (fullscreen) flags = flags | SDL_WINDOW_FULLSCREEN;
    if (borderless) flags = flags | SDL_WINDOW_BORDERLESS;

    windowObject_ = SDL_CreateWindow(title, width, height, flags);

    if (!windowObject_)
        Utils::showWarning("failed to open SDL window");
    else Utils::log(std::format("opened window \"{}\"", title));

    ID = static_cast<uint32_t>(SDL_GetWindowID(windowObject_));
    openWindows.push_back(this);

}

void gfx::Window::pollEvents(const SDL_Event event) {

    if (event.window.windowID == ID) {

        if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED)
            close();

        if (event.type == SDL_EVENT_WINDOW_RESIZED) {

            int w, h;
            SDL_GetWindowSizeInPixels(windowObject_, &w, &h);
            width = static_cast<uint32_t>(w);
            height = static_cast<uint32_t>(h);

        }

    }

}

void gfx::Window::applyProperties() {



}

void gfx::Window::close() {

    SDL_DestroyWindow(windowObject_);
    std::erase(openWindows, this);

}

gfx::Window::~Window() {

    if (openWindows.size() > 0) {

        std::string warningString = 
        std::format("window \"{}\" was destroyed without .close() or user input. ", title);
        warningString += "this can happen if the variable holding the window goes out of scope. ";
        warningString += "make sure the window is not a local variable.";

        Utils::showWarning(warningString);
        close();

    }

}