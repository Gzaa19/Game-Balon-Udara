// bird.h
#ifndef BIRD_H
#define BIRD_H

#include "globals.h"
#include <time.h>

// Struktur data burung
typedef struct {
    float startX, startY, startZ;
    float speedX, speedY, speedZ;
    float amplitude;
    float frequency;
    float phase;
    float size;
    float color[3];
} Bird;

extern Bird birds[NUM_BIRDS];

void initBirds();
void drawBird(float x, float y, float z, float size, float wingAngle, float r, float g, float b);
void updateAndDrawBirds(float cloudX, float cloudY, float cloudZ);

#endif // BIRD_H
