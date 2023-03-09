#include <stdlib.h>
#include <limits.h>
#include <SDL2/SDL.h>
#include "libs/canva.h"


Color fix_color(Color color){
    Color fixed = color;
    if (fixed.red > 255)
        fixed.red = 255;
    if (fixed.blue > 255)
        fixed.blue = 255;
    if (fixed.green > 255)
        fixed.green = 255;
    return fixed;
}

int main() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = /*SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0)*/ NULL;
    SDL_Renderer* renderer = NULL;
    SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN, &window, &renderer);
    SDL_RenderSetScale(renderer, 2, 2);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    /*SDL_Surface *window_surface = SDL_GetWindowSurface(window);
    SDL_Surface *canvas = SDL_CreateRGBSurfaceWithFormat(0, SCREEN_WIDTH, SCREEN_HEIGHT, 32, SDL_PIXELFORMAT_RGBA8888);
    uint32_t *buffer = (uint32_t*) canvas->pixels;
    SDL_LockSurface(canvas);*/
    //writeToCanva(buffer, 0, 0, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), SCREEN_WIDTH, SCREEN_HEIGHT);
    //writeToCanva(buffer, -200, -200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), SCREEN_WIDTH, SCREEN_HEIGHT);
    //writeToCanva(buffer, 300, -200, SDL_MapRGBA(canvas->format, 255, 0, 0, 255), SCREEN_WIDTH, SCREEN_HEIGHT);
    Vector3 origin = {0, 0, 0};
    Sphere spheres[SPHERE_NUMBER] = { (Sphere){(Vector3){0, -1, 3}, 1, (Color){255, 0, 0}},
                        (Sphere){(Vector3){2, 0, 4}, 1, (Color){0, 0, 255}},
                        (Sphere){(Vector3){-2, 0, 4}, 1, (Color){0, 255, 0}}
                        };
    for (int x = -(SCREEN_WIDTH/2); x < SCREEN_WIDTH/2; ++x){
        for (int y = -SCREEN_HEIGHT/2; y < SCREEN_HEIGHT/2; ++y){
            Vector3 D = canvaToViewPort(x, y);
            Color color; 
            color = fix_color(traceRay(origin, D, 1, INF, spheres));
            //printf("TEST\n");
            SDL_SetRenderDrawColor(renderer, color.red, color.green, color.blue, 255);
            int screen_x = x  + SCREEN_WIDTH/2;
            int screen_y = SCREEN_HEIGHT/2 - y - 1;
            SDL_RenderDrawPoint(renderer, screen_x, screen_y);
            //writeToCanva(renderer, x, y, color.red, color.green, color.blue, 255, SCREEN_WIDTH, SCREEN_HEIGHT);
           // writeToCanva(buffer, x, y, SDL_MapRGB(canvas->format, color.red, color.green, color.blue), SCREEN_WIDTH, SCREEN_HEIGHT);
            
        }
    }
    //SDL_UnlockSurface(canvas);
    SDL_RenderPresent(renderer);
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

        //SDL_BlitSurface(canvas, 0, window_surface, 0);
        //SDL_UpdateWindowSurface(window);
        //SDL_RenderPresent(renderer);
        //SDL_Delay(10);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

}