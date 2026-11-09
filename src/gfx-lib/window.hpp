#include <vector>

#include <SDL3/SDL.h>

class gfx::Window {

public:

    const char* title = "";
    unsigned int width = 1080;
    unsigned int height = 720;
    unsigned int targetFps = 144;
    bool resizable = true;
    bool shouldClose = false;

    inline static std::vector<Window> openWindows;
    void open();
    
    float getFps() { return fps_; }

private:

    SDL_Window* windowObject_;
    float fps_;

};