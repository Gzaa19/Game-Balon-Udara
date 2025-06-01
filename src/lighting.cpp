// lighting.cpp
#include "lighting.h"

// Lighting constants
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

void setupLighting() {
    // Setup lighting yang lebih baik
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);

    // Lighting properties
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    // Material properties
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
}

void updateLighting() {
    // Update lighting berdasarkan mode siang/malam
    if(isNight) {
        glClearColor(0.05f, 0.05f, 0.15f, 1.0f);
        // Cahaya bulan - lebih redup dan kebiruan
        GLfloat night_ambient[] = {0.1f, 0.1f, 0.2f, 1.0f};
        GLfloat night_diffuse[] = {0.3f, 0.3f, 0.5f, 1.0f};
        GLfloat night_specular[] = {0.2f, 0.2f, 0.4f, 1.0f};
        glLightfv(GL_LIGHT0, GL_AMBIENT, night_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, night_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, night_specular);
    } else {
        glClearColor(0.725f, 0.9f, 1.0f, 1.0f);
        // Cahaya matahari - terang dan kekuningan
        GLfloat day_ambient[] = {0.3f, 0.3f, 0.2f, 1.0f};
        GLfloat day_diffuse[] = {1.0f, 0.9f, 0.7f, 1.0f};
        GLfloat day_specular[] = {1.0f, 1.0f, 1.0f, 1.0f};
        glLightfv(GL_LIGHT0, GL_AMBIENT, day_ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, day_diffuse);
        glLightfv(GL_LIGHT0, GL_SPECULAR, day_specular);
    }
    
    // Update posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
}
