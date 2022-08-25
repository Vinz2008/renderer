#include <stdlib.h>
#include <limits.h>
#include <SDL2/SDL.h>
#include "libs/canva.h"


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_Surface *canvas = SDL_CreateRGBSurfaceWithFormat(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_PIXELFORMAT_RGBA8888);
    uint32_t *buffer = (uint32_t*) canvas->pixels;
    SDL_LockSurface(canvas);
    //writeToCanva(buffer, 0, 0, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), SCREEN_WIDTH, SCREEN_HEIGHT);
    //writeToCanva(buffer, -200, -200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), SCREEN_WIDTH, SCREEN_HEIGHT);
    //writeToCanva(buffer, 300, -200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), SCREEN_WIDTH, SCREEN_HEIGHT);

    Pos origin = {0, 0, 0};
    Sphere spheres[SPHERE_NUMBER] = { (Sphere){(__sphere_center){0, -1, 3}, 1, (Color){255, 0, 0}},
                        (Sphere){(__sphere_center){2, 0, 4}, 1, (Color){0, 0, 255}},
                        (Sphere){(__sphere_center){-2, 0, 4}, 1, (Color){0, 255, 0}}
                        };
    for (int x = -SCREEN_WIDTH/2; x < SCREEN_WIDTH/2;x++){
        for (int y = -SCREEN_HEIGHT/2; y < SCREEN_HEIGHT/2;y++){
            Pos D = canvaToViewPort(x, y);
            Color color; 
            color = traceRay(origin, D, 1, INT_MAX, spheres);
            printf("TEST\n");
            writeToCanva(buffer, x, y, SDL_MapRGB(canvas->format, color.red, color.green, color.blue), SCREEN_WIDTH, SCREEN_HEIGHT);
            
        }
    }
    SDL_UnlockSurface(canvas);
    int quit = 0;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = 1;
            }
        }

        SDL_BlitSurface(canvas, 0, window_surface, 0);
        SDL_UpdateWindowSurface(window);

        SDL_Delay(10);
    }

    SDL_Quit();

    return 0;

}