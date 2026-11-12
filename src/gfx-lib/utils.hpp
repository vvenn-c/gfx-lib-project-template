#pragma once

#include <print>
#include <string>
#include <stdexcept>

class gfx::Utils {
    
public:

    Utils() = delete;

    static void log(std::string logString) {
        std::println("[gfx-lib] {}", logString);
    }

    static void showError(std::string errorString) {
        std::println(stderr, "[gfx-lib] error: {}", errorString);
    }

    static void showWarning(std::string warningString) {
        std::println(stderr, "[gfx-lib] warning: {}", warningString);
    }

};