// game.cpp
#include "game.h"

void resetGame() {
    // Reset semua variabel ke kondisi awal
    TIME = 0;
    START = false;
    gameStarted = false;  // Reset flag game
    startTime = 0;       // Reset start time
    
    // Reset posisi dan rotasi balon
    tX = 0;
    tY = 0;
    tZ = -8;
    rX = 0;
    rY = 0;
    rZ = 4;
    
    // Reset posisi environment layers
    tZ1 = -20;
    tZ2 = -40;
    tZ3 = -60;
    tZ4 = -80;
    tZ5 = -100;
    tZ6 = -120;
    
    // Reset rotasi balon
    rotX = 0;
    rotY = 0;
    rotZ = 0;
    
    // Reset kecepatan
    speed = 0.05f;
    
    // Reset zoom
    zoom = 4;
    
    // Reset mode malam/siang ke default (siang)
    isNight = false;
    
    // Reinisialisasi burung dan awan untuk variasi
    initBirds();
    initClouds();
}
