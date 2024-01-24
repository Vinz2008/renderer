#include <stdlib.h>
#include <limits.h>
#include <SDL2/SDL.h>
#include "canva.h"
#include "raytracer.h"


/*Color fix_color(Color color){
    Color fixed = color;
    if (fixed.red > 255)
        fixed.red = 255;
    if (fixed.blue > 255)
        fixed.blue = 255;
    if (fixed.green > 255)
        fixed.green = 255;
    return fixed;
}*/

int main(int argc, char** argv){
    /*SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);*/



    raytrace();

    /*SDL_RenderPresent(renderer);
    int quit = 0;
    SDL_Event event;
    while (!quit){
        while (SDL_PollEvent(&event)){
            if (event.type == SDL_QUIT){
                quit = 1;
            }
        }
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();*/

    return 0;

}