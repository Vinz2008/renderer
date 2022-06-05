#include <stdint.h>

int convertPositions(int screenWidth, int screenHeight, int x, int y, int* xOut, int* yOut){
    *xOut = screenWidth/2 + x;
    *yOut = screenHeight/2 - y;
    return 0;
}

int canvaToViewPort(int x, int y){
    
}


int writeToCanva(uint32_t *buffer, int x, int y, uint32_t color, int screenWidth, int screenHeight){
    int xTemp;
    int yTemp;
    convertPositions(screenWidth, screenHeight, x, y, &xTemp, &yTemp);
    uint32_t offset = yTemp * screenWidth + xTemp;
    buffer[offset] = color; 
    return 0;
}