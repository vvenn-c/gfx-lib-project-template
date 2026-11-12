#include <vector>
#include <cstdint>
#include <SDL3/SDL.h>

class gfx::Window {

public:

    const char* title = "";
    uint32_t width = 1080;
    uint32_t height = 720;
    uint32_t targetFps = 144;
    bool resizable = true;
    uint32_t ID;

    void open();
    void close();
    inline static std::vector<Window*> openWindows;

    float getFps() { return fps_; }

protected: friend class Core;

    float fps_;
    SDL_Window* windowObject_;

    void pollEvents(const SDL_Event event);
    void applyProperties();

};