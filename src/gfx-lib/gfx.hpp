#pragma once

namespace gfx {

    class Utils;
    class Window;
    class Core;
    class Shaders;
    class Primitives;
    class Camera;
    class UI;

    void init();
    void loop();
    void exit();

    inline bool shouldAppClose = false;
    inline int run();

};

#include "utils.hpp"
#include "window.hpp"
#include "core.hpp"

int gfx::run() {

    try {

        gfx::init();

            gfx::Core::initVulkan();
            gfx::Core::mainLoop(); // which calls gfx::loop() within it
            gfx::Core::cleanup();

        gfx::exit();

    } catch (const std::exception &e) {

        gfx::Utils::showError(e.what());
        return EXIT_FAILURE;

    } return EXIT_SUCCESS;

}