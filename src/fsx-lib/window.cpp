#include <algorithm>
#include <string>
#include <SDL3/SDL.h>

#include "fsx.hpp"

void fsx::Window::open() {

    if (std::ranges::contains(openWindows, this)) {

        Utils::showWarning(
            ".open() was called on window \"{}\", but it was already open. "
            "ignoring the function call.", title
        );
        
        return;

    }

    SDL_WindowFlags flags = SDL_WINDOW_VULKAN;
    if (resizable) flags = flags | SDL_WINDOW_RESIZABLE;
    if (fullscreen) flags = flags | SDL_WINDOW_FULLSCREEN;
    if (borderless) flags = flags | SDL_WINDOW_BORDERLESS;

    windowObject_ = SDL_CreateWindow(title, width, height, flags);

    if (!windowObject_)
        Utils::showWarning("failed to create SDL window object for window \"{}\".", title);
    else Utils::log("opened window \"{}\"", title);

    ID = static_cast<uint32_t>(SDL_GetWindowID(windowObject_));
    openWindows.push_back(this);

}

void fsx::Window::pollEvents(const SDL_Event event) {

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

void fsx::Window::applyProperties() {

    // TODO: only call this if it was changed. (perhaps by comparing to the swapchain size?)
    SDL_SetWindowTitle(windowObject_, title);
    SDL_SetWindowSize(windowObject_, width, height);

}

void fsx::Window::close() {

    SDL_DestroyWindow(windowObject_);
    std::erase(openWindows, this);

    Utils::log("closed window \"{}\"", title);

}

fsx::Window::~Window() {

    if (openWindows.size() > 0) {

        Utils::showWarning(
            "window \"{}\" was destroyed without .close() or user input. "
            "this can happen if the variable holding the window goes out of scope. "
            "make sure the window is not a local variable.", title
        );

        close();

    }

}