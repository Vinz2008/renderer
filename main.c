#include <stdlib.h>
#include <SDL2/SDL.h>
#include "libs/writeToCanva.h"


int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, 0);
    SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_Surface *canvas = SDL_CreateRGBSurfaceWithFormat(0, 1600, 900, 32, SDL_PIXELFORMAT_RGBA8888);
    uint32_t *buffer = (uint32_t*) canvas->pixels;
    int row    = 0;
    int column = 0;
    int offset;
    uint32_t color;
    SDL_LockSurface(canvas);
    /*while (row < 900)
    {
        column = 0;
        while (column < 1600)
        {
            if (column % 25 == 0){
            offset = row * 1600 + column;
            printf("offset : %d", offset);
            color = SDL_MapRGBA(canvas->format, 255, 0, 0, 255);
            //writeToCanva(buffer, row, column, color, 1600, 900);
            buffer[offset] = color;
            }
            column++;
        }
        row++;
    }*/
    writeToCanva(buffer, 200, 200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), 1600, 900);
    writeToCanva(buffer, -200, -200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), 1600, 900);
    writeToCanva(buffer, 300, -200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), 1600, 900);
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