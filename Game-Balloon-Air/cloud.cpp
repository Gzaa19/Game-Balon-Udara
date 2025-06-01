// cloud.cpp
#include "cloud.h"

CloudPart clouds[7][5]; // 7 awan, masing-masing 5 bagian

void initClouds() {
    srand(time(NULL));
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            clouds[i][j].offsetX = (float)(rand() % 100 - 50) / 100.0f;
            clouds[i][j].offsetY = (float)(rand() % 100) / 500.0f;
            clouds[i][j].offsetZ = (float)(rand() % 100 - 50) / 100.0f;
            clouds[i][j].size = 0.3f + (float)(rand() % 100) / 300.0f;
            clouds[i][j].speed = 0.05f + (float)(rand() % 100) / 1000.0f;
            clouds[i][j].phase = (float)(rand() % 628) / 100.0f;
        }
    }
}

void cloud() {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    float cloudMovementX = sin(t * 0.1) * 0.5f; 

    glColor3d(1.0, 1.0, 1.0);

    glPushMatrix();
        glTranslated(cloudMovementX, 10.0f, 0.0f);
        glutSolidSphere(0.5, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.6f + cloudMovementX, 10.2f, 0.1f);
        glutSolidSphere(0.4, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.6f + cloudMovementX, 10.2f, 0.1f);
        glutSolidSphere(0.4, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.3f + cloudMovementX, 10.4f, 0.2f);
        glutSolidSphere(0.3, 30, 30);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.3f + cloudMovementX, 10.4f, 0.2f);
        glutSolidSphere(0.3, 30, 30);
    glPopMatrix();
}
