// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

#include <windows.h>
#include <GL/glut.h>
#include <bits/stdc++.h>
#include <stdlib.h>

#define rad (3.1416/180)
#define EN_SIZE 20
#define NUM_BIRDS 7

// Global variables
extern float zoom;
extern int tola[5000][5000];
extern float tX, tY, tZ, rX, rY, rZ;
extern float tZ1, tZ2, tZ3, tZ4, tZ5, tZ6;
extern float rotX, rotY, rotZ;
extern float cosX, cosY, cosZ;
extern float angle;
extern float xEye, yEye, zEye;
extern float cenX, cenY, cenZ, roll;
extern float radius;
extern float theta, slope;
extern float speed;
extern float angleBackFrac;
extern int TIME;
extern bool START;
extern bool rot;
extern bool isNight;
extern GLfloat shadowMat[4][4];
extern GLfloat lightPos[4];

// Game state variables
extern int startTime;
extern bool gameStarted;

// Posisi awan dan burung
extern float torusPosX[7];
extern float torusPosY[7];

#endif // GLOBALS_H
