#include "gfx-lib/gfx.hpp"

// TODO:
// issue with dangling pointer in openWindows

void gfx::init() {

    gfx::Window window1;
    gfx::Window window2;

    window1.title = "pog";
    window1.open();

    window2.title = "poggers";
    window2.open();

    std::println("open windows:");
    for (auto *window : gfx::Window::openWindows)
        std::println(" |- {}", window->title);

    window1.title = "NOT pog";

    std::println("open windows:");
    for (auto *window : gfx::Window::openWindows)
        std::println(" |- {}", window->title);

}

void gfx::loop() {



}

void gfx::exit() {



}

int main() {

    gfx::run();

}