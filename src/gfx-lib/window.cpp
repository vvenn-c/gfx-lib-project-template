#include <SDL3/SDL.h>

#include "gfx.hpp"

void gfx::Window::open() {

    if (SDL_InitSubSystem(SDL_INIT_VIDEO)) {

        SDL_WindowFlags flags = SDL_WINDOW_VULKAN;
        if (resizable) flags = flags | SDL_WINDOW_RESIZABLE;

        windowObject_ = SDL_CreateWindow(title, width, height, flags);

    }

    if (!windowObject_)
        Utils::showError("failed to open SDL window");

    openWindows.push_back(*this);

}