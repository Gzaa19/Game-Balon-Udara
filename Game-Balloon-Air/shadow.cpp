// shadow.cpp
#include "shadow.h"

void shadowMatrix(GLfloat ground[4], GLfloat light[4], GLfloat shadowMat[4][4]) {
    GLfloat dot = ground[0]*light[0] + ground[1]*light[1] + ground[2]*light[2] + ground[3]*light[3];
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            shadowMat[i][j] = -light[i]*ground[j];
    shadowMat[0][0] += dot;
    shadowMat[1][1] += dot;
    shadowMat[2][2] += dot;
    shadowMat[3][3] += dot;
}
