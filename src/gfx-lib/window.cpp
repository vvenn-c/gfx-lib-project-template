#include <SDL3/SDL.h>

#include "gfx.hpp"

void gfx::Window::open() {

    SDL_WindowFlags flags = SDL_WINDOW_VULKAN;
    if (resizable) flags = flags | SDL_WINDOW_RESIZABLE;

    windowObject_ = SDL_CreateWindow(title, width, height, flags);

    if (!windowObject_)
        Utils::showError("failed to open SDL window");

    ID = static_cast<uint32_t>(SDL_GetWindowID(windowObject_));
    openWindows.push_back(this);

}

void gfx::Window::pollEvents(const SDL_Event event) {

    if (event.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED) {
        if (event.window.windowID == ID) {
            close();
        }
    }

}

void gfx::Window::applyProperties() {



}

void gfx::Window::close() {

    SDL_DestroyWindow(windowObject_);
    std::erase(openWindows, this);

}