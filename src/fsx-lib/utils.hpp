#pragma once

#include <print>
#include <string>
#include <stdexcept>

class fsx::Utils {
    
public:

    Utils() = delete;

    static void log(std::string logString) {
        std::println("[fsx-lib] {}", logString);
    }

    static void showError(std::string errorString) {
        std::println(stderr, "[fsx-lib] error: {}", errorString);
    }

    static void showWarning(std::string warningString) {
        std::println(stderr, "[fsx-lib] warning: {}", warningString);
    }

};