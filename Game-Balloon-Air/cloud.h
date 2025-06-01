// cloud.h
#ifndef CLOUD_H
#define CLOUD_H

#include "globals.h"
#include <time.h>

// Struktur data awan bagian
typedef struct {
    float offsetX, offsetY, offsetZ;
    float size;
    float speed;
    float phase;
} CloudPart;

extern CloudPart clouds[7][5]; // 7 awan, masing-masing 5 bagian

void initClouds();
void cloud();

#endif // CLOUD_H
