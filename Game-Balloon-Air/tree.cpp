// tree.cpp
#include "tree.h"

void drawTreeShadow(float x, float y, float z, float height, int type) {
    GLfloat ground[4] = {0.0f, 1.0f, 0.0f, 0.16f};
    GLfloat treeShadowMat[4][4];
    shadowMatrix(ground, lightPos, treeShadowMat);
    
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glTranslatef(x, 0.17f, z); // Shadow di tanah
        glMultMatrixf((GLfloat*)treeShadowMat);
        
        // Warna shadow pohon
        if(isNight) {
            glColor4f(0.0f, 0.0f, 0.1f, 0.7f);
        } else {
            glColor4f(0.1f, 0.1f, 0.1f, 0.5f);
        }
        
        // Shadow batang
        glPushMatrix();
        glScalef(0.2f, height * 0.7f, 0.2f);
        glutSolidCube(1.0f);
        glPopMatrix();
        
        // Shadow daun (simplified)
        glPushMatrix();
        glTranslatef(0, height * 0.7f + 0.5f, 0);
        glutSolidSphere(1.0f, 8, 8);
        glPopMatrix();
        
        glEnable(GL_LIGHTING);
    glPopMatrix();
}

void drawTree(float x, float y, float z, float height, int type) {
    // Gambar shadow pohon terlebih dahulu
    drawTreeShadow(x, y, z, height, type);
    
    glColor3f(0.55f, 0.27f, 0.07f);
    glPushMatrix();
    glTranslatef(x, y, z);
    glScalef(0.2f, height * 0.7f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    if (type % 3 == 0) {
        glColor3f(0.0f, 0.5f, 0.0f);
        for (int i = 0; i < 3; i++) {
            float size = (3 - i) * 0.5f;
            float yOffset = height * 0.7f * 0.5f + i * 0.5f;

            glPushMatrix();
            glTranslatef(x, y + yOffset, z);
            glRotatef(-90, 1, 0, 0);
            glutSolidCone(size, size * 1.5f, 12, 12);
            glPopMatrix();
        }
    } else if (type % 3 == 1) {
        glColor3f(0.0f, 0.6f, 0.0f);
        glPushMatrix();
        glTranslatef(x, y + height * 0.7f + 0.7f, z);
        glutSolidSphere(1.0f, 16, 16);
        glPopMatrix();
    } else {
        glColor3f(0.0f, 0.4f, 0.0f);
        glPushMatrix();
        glTranslatef(x, y + height * 0.7f + 0.5f, z);
        glScalef(0.8f, 1.2f, 0.8f);
        glutSolidSphere(0.9f, 16, 16);
        glPopMatrix();
    }
}

void forest(int n, int R, int G) {
    float height = (n % 3) + 1.5f;
    drawTree(0.0f, 0.0f, 0.0f, height, n % 3);

    if (n > 1) {
        for (int i = 0; i < 3; i++) {
            float angle = i * 120.0f * (3.1416f / 180.0f);
            float distX = 0.8f * cos(angle);
            float distZ = 0.8f * sin(angle);
            drawTree(distX, 0.0f, distZ, height * 0.8f, (n + i) % 3);
        }
    }
}
