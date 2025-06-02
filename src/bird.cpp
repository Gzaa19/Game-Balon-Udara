// bird.cpp
#include "bird.h"

Bird birds[NUM_BIRDS];

void initBirds() {
    srand(time(NULL));
    for (int i = 0; i < NUM_BIRDS; i++) {
        birds[i].startX = (float)(rand() % 10 - 5);
        birds[i].startY = 9.0f + (float)(rand() % 3);
        birds[i].startZ = (float)(rand() % 10 - 5);
        birds[i].speedX = 0.1f + (float)(rand() % 100) / 1000.0f; // Lebih lambat
        birds[i].speedY = 0.02f + (float)(rand() % 100) / 2000.0f;
        birds[i].speedZ = 0.05f + (float)(rand() % 100) / 1000.0f;
        birds[i].amplitude = 0.3f + (float)(rand() % 100) / 200.0f;
        birds[i].frequency = 0.8f + (float)(rand() % 100) / 100.0f;
        birds[i].phase = (float)(rand() % 628) / 100.0f;
        birds[i].size = 0.2f + (float)(rand() % 100) / 300.0f;

        if (i % 3 == 0) {
            birds[i].color[0] = 0.3f; birds[i].color[1] = 0.3f; birds[i].color[2] = 0.7f;
        } else if (i % 3 == 1) {
            birds[i].color[0] = 0.7f; birds[i].color[1] = 0.3f; birds[i].color[2] = 0.3f;
        } else {
            birds[i].color[0] = 0.3f; birds[i].color[1] = 0.6f; birds[i].color[2] = 0.3f;
        }
    }
}

void drawBird(float x, float y, float z, float size, float wingAngle, float r, float g, float b) {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = sin(t * 5.0) * 30.0;

    float dirX = cos(t);
    float dirZ = sin(t);

    glPushMatrix();
    glTranslatef(x, y, z);

    float angle = atan2(dirZ, dirX) * 180.0 / 3.1416;
    glRotatef(angle, 0, 1, 0);

    glScalef(size, size, size);

    glColor3f(r, g, b);
    glutSolidSphere(0.2, 10, 10);

    glColor3f(r + 0.1f, g + 0.1f, b + 0.1f);
    glPushMatrix();
    glTranslatef(0.15f, 0.05f, 0.0f);
    glutSolidSphere(0.1, 8, 8);
    glPopMatrix();

    glColor3f(1.0f, 0.7f, 0.0f);
    glPushMatrix();
    glTranslatef(0.25f, 0.05f, 0.0f);
    glRotatef(90, 0, 1, 0);
    glutSolidCone(0.05, 0.1, 8, 8);
    glPopMatrix();

    glColor3f(r - 0.1f, g - 0.1f, b - 0.1f);
    glPushMatrix();
    glTranslatef(0.0f, 0.05f, 0.1f);
    glRotatef(a, 1, 0, 0);
    glRotatef(45, 0, 1, 0);
    glScalef(0.4, 0.05, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, 0.05f, -0.1f);
    glRotatef(-a, 1, 0, 0);
    glRotatef(-45, 0, 1, 0);
    glScalef(0.4, 0.05, 0.2);
    glutSolidCube(1.0);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.2f, 0.0f, 0.0f);
    glRotatef(45, 0, 0, 1);
    glScalef(0.2, 0.05, 0.1);
    glutSolidCube(1.0);
    glPopMatrix();

    glPopMatrix();
}

void updateAndDrawBirds(float cloudX, float cloudY, float cloudZ) {
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

    for (int i = 0; i < NUM_BIRDS; i++) {
        float x = birds[i].startX + sin(t * birds[i].frequency + birds[i].phase) * birds[i].amplitude;
        float y = birds[i].startY + sin(t * birds[i].frequency * 0.5 + birds[i].phase) * (birds[i].amplitude * 0.3);
        float z = birds[i].startZ + cos(t * birds[i].frequency + birds[i].phase) * birds[i].amplitude;

        x += (t * birds[i].speedX);
        y += sin(t * birds[i].speedY);
        z += (t * birds[i].speedZ);

        if (x > 15 || x < -15 || z > 15 || z < -15) {
            x = birds[i].startX;
            z = birds[i].startZ;
        }

        drawBird(x + cloudX, y, z + cloudZ, birds[i].size, sin(t * 5.0) * 30.0,
                 birds[i].color[0], birds[i].color[1], birds[i].color[2]);
    }
}
