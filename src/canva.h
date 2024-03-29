#include <stdint.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900


/*
#define VIEWPORT_WIDTH 1
#define VIEWPORT_HEIGHT 1
#define DISTANCE_CAMERA 1

#define SPHERE_NUMBER 3
#define INF 100000

typedef struct vector3 {
  float x, y, z;
} Vector3;


typedef struct {
    uint32_t red;
    uint32_t green;
    uint32_t blue;
} Color; 

#define BACKGROUND_COLOR (Color){0, 0, 0}

typedef struct {
    Vector3 center;
    float radius;
    Color color;
} Sphere;*/




int writeToCanva(SDL_Renderer *renderer, int x, int y, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int screenWidth, int screenHeight);
//Vector3 canvaToViewPort(int x, int y);
//void intersectRaySphere(Vector3 origin, Vector3 D, Sphere sphere, float* t1, float* t2);
//Color traceRay(Vector3 origin, Vector3 D, float t_min, float t_max, Sphere spheres[SPHERE_NUMBER]);
//uint32_t createColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);