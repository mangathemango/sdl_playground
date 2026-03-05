#include <app.h>
#include <input.h>


/* 
*   [Quit] This function is called when the program is about to quit.

?   Updated by Darren on 07/03/2025
*/
int App_Quit() {
    SDL_DestroyTexture(app.resources.screenTexture);
    SDL_DestroyRenderer(app.resources.renderer);
    SDL_DestroyWindow(app.resources.window);
    SDL_Quit();
    return 0;
}