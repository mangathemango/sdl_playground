
/**
 * @file main.c
 * @brief Main entry point for the Operation Null Mind game
 * @author Mango
 * @date 2025-03-01
 */

#define SDL_MAIN_HANDLED 1

#include <windows.h>
#include <SDL_main.h>
#include <app.h>
#include <iostream>
#include <filesystem>
#include <vec3.h>

int main() {
    if (App_Start()) return 1;
    SDL_Event event;
    while (app.state.running) {
        if(App_PreUpdate()) return 1;
        while (SDL_PollEvent(&event)) if(App_Event_Handler(&event)) return 1;
        if(App_PostUpdate()) return 1; // Ensure this line is present to call App_PostUpdate
        if(App_Render()) return 1;
    }
    App_Quit();
    return 0;
}