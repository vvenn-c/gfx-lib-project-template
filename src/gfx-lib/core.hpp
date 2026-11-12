class gfx::Core {

public:

    Core() = delete;

    static void initSDL();
    static void initVulkan();
    static void mainLoop();
    static void cleanup();

};