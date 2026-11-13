#pragma once

#include <print>
#include <string>
#include <utility>
#include <stdexcept>

class fsx::Utils {
    
public:

    Utils() = delete;

    template <typename... Args>
    static void log(std::format_string<Args...> fmt, Args&&... args) {
        std::println();
        std::println("[fsx-lib] {}", std::format(fmt, std::forward<Args>(args)...));
    }

    template <typename... Args>
    static void showError(std::format_string<Args...> fmt, Args&&... args) {
        std::println();
        std::println(stderr, "[fsx-lib] error: {}", std::format(fmt, std::forward<Args>(args)...));
    }

    template <typename... Args>
    static void showWarning(std::format_string<Args...> fmt, Args&&... args) {
        std::println();
        std::println(stderr, "[fsx-lib] warning: {}", std::format(fmt, std::forward<Args>(args)...));
    }

};