#include "gfx-lib/gfx.hpp"

gfx::Window window;
gfx::Window window2;

void gfx::init() {

    window.title = "pog";
    window.open();

    window2.title = "poggers";
    window2.open();

}

void gfx::loop() {



}

void gfx::exit() {



}

int main() {

    gfx::run();

}