#include <stdint.h>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

#define VIEWPORT_WIDTH 1
#define VIEWPORT_HEIGHT 1
#define DISTANCE_CAMERA 1

#define SPHERE_NUMBER 3

typedef struct {
    int x;
    int y;
    int z;
} __sphere_center;

typedef struct {
    uint32_t red;
    uint32_t green;
    uint32_t blue;
} Color; 

#define BACKGROUND_COLOR (Color){0, 0, 0}

typedef struct {
    __sphere_center center;
    int radius;
    Color color;
} Sphere;

typedef struct {
    int x;
    int y;
    int z;
} Pos;


int writeToCanva(uint32_t *buffer, int x, int y, uint32_t color, int screenWidth, int screenHeight);
Pos canvaToViewPort(int x, int y);
void intersectRaySphere(Pos origin, Pos D, Sphere sphere, int* t1, int* t2);
Color traceRay(Pos origin, Pos D, int t_min, int t_max, Sphere spheres[SPHERE_NUMBER]);
