// text.cpp
#include "text.h"

void drawStrokeText(const char* str, float x, float y, float z)
{
    const char* c;
    glColor3f(isNight ? 0.8f : 0.2f, isNight ? 0.8f : 0.3f, isNight ? 1.0f : 0.5f);
    glPushMatrix();
    glTranslatef(x, y + 8, z);
    glScalef(0.002f, 0.002f, z);
    for (c = str; *c != '\0'; c++)
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    glPopMatrix();
}

void drawStrokeChar(char c,float x,float y,float z)
{
    glPushMatrix();
    glTranslatef(x, y+8,z);
    glScalef(0.002f,0.002f,z);
    glutStrokeCharacter(GLUT_STROKE_ROMAN , c);
    glPopMatrix();
}
