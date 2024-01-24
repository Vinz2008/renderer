#include "canva.h"
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <SDL2/SDL.h>


/*int dotProduct(Vector3 v1, Vector3 v2){
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

int convertPositions(int screenWidth, int screenHeight, int x, int y, int* xOut, int* yOut){
    *xOut = screenWidth/2 + x;
    *yOut = screenHeight/2 - y;
    return 0;
}

Vector3 canvaToViewPort(int x, int y){
    Vector3 posTemp;
    posTemp.x = x * VIEWPORT_WIDTH / SCREEN_WIDTH;
    posTemp.y = y * VIEWPORT_HEIGHT / SCREEN_HEIGHT;
    posTemp.z = DISTANCE_CAMERA;
    return posTemp;
}

void intersectRaySphere(Vector3 origin, Vector3 D, Sphere sphere, float* t1, float* t2){
    float radius = sphere.radius;
    Vector3 CO;
    CO.x = origin.x - sphere.center.x;
    CO.y = origin.y - sphere.center.y;
    CO.z = origin.z - sphere.center.z;
    int a = dotProduct(D, D);
    int b = 2 * dotProduct(CO, D);
    int c = dotProduct(CO, CO) - radius * radius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0){
        *t1 = INF;
        *t2 = INF;
    }
    *t1 = (-b + sqrt(discriminant)) / (2*a);
    *t2 = (-b - sqrt(discriminant)) / (2*a);
}

Color traceRay(Vector3 origin, Vector3 D, float t_min, float t_max, Sphere spheres[SPHERE_NUMBER]){
    float closest_t = INFINITY;
    Sphere* closest_sphere = NULL;
    Sphere sphere;
    for (int i = 0; i < SPHERE_NUMBER; i++){
        sphere = spheres[i];
        float t1, t2;
        intersectRaySphere(origin, D, sphere, &t1, &t2);
        if (t1 > t_min && t1 < t_max && t1 < closest_t){
            closest_t = t1;
            closest_sphere = &spheres[i];
        }
        if (t2 > t_min && t2 < t_max && t2 < closest_t){
            closest_t = t2;
            closest_sphere = &spheres[i];
        }
        if (closest_sphere == NULL){
            return BACKGROUND_COLOR;
        }
        return closest_sphere->color;
    }
}*/


int writeToCanva(SDL_Renderer *renderer, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int screenWidth, int screenHeight){
    int xTemp = x;
    int yTemp = y;
    //convertPositions(screenWidth, screenHeight, x, y, &xTemp, &yTemp);
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderDrawPoint(renderer, xTemp, yTemp);
    return 0;
}

/*uint32_t createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a){
    return r << 24 | g << 16 | b << 8 |  a;
}*/