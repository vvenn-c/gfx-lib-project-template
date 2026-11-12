#include <vector>
#include <cstdint>
#include <SDL3/SDL.h>

class fsx::Window {

public:

    ~Window();

    const char* title = "";
    uint32_t width = 1080;
    uint32_t height = 720;
    uint32_t targetFps = 144;
    uint32_t ID;
    
    bool resizable = true;
    bool fullscreen = false;
    bool borderless = false;

    static inline std::vector<Window*> openWindows;

    void open();
    void close();

protected: friend class Core;

    SDL_Window* windowObject_;

    void pollEvents(const SDL_Event event);
    void applyProperties();

};