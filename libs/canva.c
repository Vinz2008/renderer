#include "canva.h"
#include <stdint.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>


int dotProduct(Pos pos1, Pos pos2){
    return pos1.x * pos2.x + pos1.y * pos2.y + pos1.z * pos2.z;
}

int convertPositions(int screenWidth, int screenHeight, int x, int y, int* xOut, int* yOut){
    *xOut = screenWidth/2 + x;
    *yOut = screenHeight/2 - y;
    return 0;
}

Pos canvaToViewPort(int x, int y){
    Pos posTemp;
    posTemp.x = x * VIEWPORT_WIDTH/SCREEN_WIDTH;
    posTemp.y = y * VIEWPORT_HEIGHT/SCREEN_HEIGHT;
    posTemp.z = DISTANCE_CAMERA;
    return posTemp;
}

void intersectRaySphere(Pos origin, Pos D, Sphere sphere, int* t1, int* t2){
    int radius = sphere.radius;
    Pos CO;
    CO.x = origin.x - sphere.center.x;
    CO.y = origin.y - sphere.center.y;
    CO.z = origin.z - sphere.center.z;
    int a = dotProduct(D, D);
    int b = 2 * dotProduct(CO, D);
    int c = dotProduct(CO, CO) - radius * radius;
    int discriminant = b * b - 4 * a * c;
    if (discriminant < 0){
        *t1 = INT_MAX;
        *t2 = INT_MAX;
    }
    *t1 = (-b + sqrt(discriminant)) / (2*a);
    *t2 = (-b - sqrt(discriminant)) / (2*a);
}

Color traceRay(Pos origin, Pos D, int t_min, int t_max, Sphere spheres[SPHERE_NUMBER]){
    int closest_t = INT_MAX;
    Sphere* closest_sphere = NULL;
    Sphere sphere;
    for (int i = 0; i < SPHERE_NUMBER; i++){
        sphere = spheres[i];
        int t1, t2;
        printf("TEST2\n");
        intersectRaySphere(origin, D, sphere, &t1, &t2);
        if (t1 > t_min && t1 < t_max && t1 < closest_t){
            closest_t = t1;
            closest_sphere->center = sphere.center;
            printf("TEST3\n");
            closest_sphere->color = sphere.color;
            closest_sphere->center = sphere.center;
        }
        if (t2 > t_min && t2 < t_max && t2 < closest_t){
            closest_t = t2;
            closest_sphere->center = sphere.center;
            closest_sphere->color = sphere.color;
            closest_sphere->center = sphere.center;
        }
        if (closest_sphere == NULL){
            return BACKGROUND_COLOR;
        }
        return closest_sphere->color;

    }

}


int writeToCanva(uint32_t *buffer, int x, int y, uint32_t color, int screenWidth, int screenHeight){
    int xTemp;
    int yTemp;
    convertPositions(screenWidth, screenHeight, x, y, &xTemp, &yTemp);
    uint32_t offset = yTemp * screenWidth + xTemp;
    buffer[offset] = color; 
    return 0;
}