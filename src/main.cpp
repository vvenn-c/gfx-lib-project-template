#include "gfx-lib/gfx.hpp"

#include <print>

void gfx::init() {

    gfx::Window window;
    window.title = "pog window 1";
    window.open();

    gfx::Window window2;
    window2.title = "pog window 2";
    window2.open();

    std::println("windows open:");
    for (gfx::Window &window : gfx::Window::openWindows)
        std::println(" |- {}", window.title);

}

void gfx::loop() {



}

void gfx::exit() {



}

int main() {

    gfx::run();

}