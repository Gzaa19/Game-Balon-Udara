// environment.cpp
#include "environment.h"

void environment(int n) {
    glColor3d(0.3, 0.7, 0.3);
    glPushMatrix();
        glTranslated(0, 0, 0);
        glScaled(EN_SIZE * 2, 0.3, EN_SIZE * 2);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
        float cloudOffsetX = sin(t * 0.1) * 1.0f;
        float cloudOffsetY = 0.2f;
        float cloudOffsetZ = 0.0f;

        glTranslated(torusPosX[n] + cloudOffsetX, cloudOffsetY, torusPosY[n] + cloudOffsetZ);
        cloud();

        updateAndDrawBirds(torusPosX[n] + cloudOffsetX, cloudOffsetY, torusPosY[n] + cloudOffsetZ);
    glPopMatrix();

    for(int i=-(EN_SIZE/2)+1; i<(EN_SIZE/2); i+=2) {
        for(int j=-(EN_SIZE/2)+1; j<(EN_SIZE/2); j+=2) {
            if(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]!=0) {
                glPushMatrix();
                    glTranslated(i, 0, j);
                    forest(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1], i, j);
                glPopMatrix();
            } else if(i>=-5 && i<=5) {
            } else {
                tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1]=(rand()%5)+1;
                glPushMatrix();
                    glTranslated(i, 0, j);
                    forest(tola[i+(EN_SIZE/2)+1][j+(EN_SIZE/2)+1], i, j);
                glPopMatrix();
            }
        }
    }
}
