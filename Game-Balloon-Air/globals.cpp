// globals.cpp
#include "globals.h"

// Global variable definitions
float zoom = 4;
int tola[5000][5000];
float tX = 0, tY = 0, tZ = -8, rX = 0, rY = 0, rZ = 4;
float tZ1 = -20, tZ2 = -40, tZ3 = -60, tZ4 = -80, tZ5 = -100, tZ6 = -120;
float rotX = 0, rotY = 0, rotZ = 0;
float cosX = 0, cosY = 1, cosZ = 0;
float angle = 0;
float xEye = 0.0f, yEye = 5.0f, zEye = 30.0f;
float cenX = 0, cenY = 0, cenZ = 0, roll = 0;
float radius = 0;
float theta = 0, slope = 0;
float speed = 0.05f;
float angleBackFrac = 0.5;
int TIME = 0;
bool START = false;
bool rot = false;
bool isNight = false;
GLfloat shadowMat[4][4];
GLfloat lightPos[4] = {5.0f, 15.0f, 5.0f, 1.0f};

// Game state variables
int startTime = 0;
bool gameStarted = false;

// Posisi awan dan burung
float torusPosX[7] = {1,-2,3,-4,-2,0,2};
float torusPosY[7] = {2,3,10,6,7,4,1};
