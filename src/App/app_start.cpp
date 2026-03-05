#include <app.h>
#include <random.h>
#include <input.h>

/*
*   [Start] This function is called at the start of the program.
?   It initializes everything needed for the program to run. Like the window, renderer, and later, the game.

?   Updated by Mango on 08/03/2025
*/
int App_Start() {
    RandomInit();
    Input_Init();
    // Initialize SDL and SDL_image
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    app.resources.window = SDL_CreateWindow(
        app.config.window_title,                                                // Set window title
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,                         // Centers the window
        app.config.window_width, app.config.window_height,                      // Set window size
        app.config.window_fullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0);      // Set fullscreen
    
    if (!app.resources.window) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return 1;
    }

    SDL_RaiseWindow(app.resources.window);                                          


    // Set up renderer
    app.resources.renderer = SDL_CreateRenderer(app.resources.window, -1,
        SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE);
    
    if (!app.resources.renderer) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return 1;
    }

    SDL_RenderSetLogicalSize(app.resources.renderer, app.config.screen_width, app.config.screen_height);
    SDL_SetRenderDrawBlendMode(app.resources.renderer, SDL_BLENDMODE_BLEND);

    SDL_ShowCursor(SDL_DISABLE);
    return 0;
}
