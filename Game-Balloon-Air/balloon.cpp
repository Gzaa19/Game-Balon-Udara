// balloon.cpp
#include "balloon.h"

void balloon(){
    // Balon utama
    glColor3d(1.0, 0.3, 0.3);
    glPushMatrix();
        glTranslated(0,2,0);
        glScaled(0.5, 0.5, 0.5);
        glutSolidSphere(2,50,50);
    glPopMatrix();

    // Keranjang balon
	glColor3d(0.6, 0.4, 0.2);
	glPushMatrix();
	    glTranslated(0,0,0);
	    glScaled(0.5,0.5,0.5);
	    glutSolidCube(1);
	glPopMatrix();

    // Tali balon
    glLineWidth(2.0);
	glColor3d(0.6, 0.6, 0.6);
	glPushMatrix();
    glBegin(GL_LINES);
        glVertex3f(-0.25, 0.25, -0.25);
        glVertex3f(-0.15, 2, -0.15);
        glVertex3f(0.25, 0.25, -0.25);
        glVertex3f(0.15, 2, -0.15);
        glVertex3f(-0.25, 0.25, 0.25);
        glVertex3f(-0.15, 2, 0.15);
        glVertex3f(0.25, 0.25, 0.25);
        glVertex3f(0.15, 2, 0.15);
    glEnd();
	glPopMatrix();
	glLineWidth(1.0);
}

void drawShadowedBalloon() {
    GLfloat ground[4] = {0.0f, 1.0f, 0.0f, 0.15f}; // bidang tanah y=0.15 (sedikit di atas ground)
    
    // Update posisi cahaya berdasarkan waktu untuk efek dinamis
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    lightPos[0] = 8.0f + sin(t * 0.1f) * 2.0f; // Cahaya bergerak perlahan
    lightPos[1] = isNight ? 5.0f : 15.0f;       // Lebih rendah di malam hari
    lightPos[2] = 8.0f + cos(t * 0.1f) * 2.0f;
    
    shadowMatrix(ground, lightPos, shadowMat);

    // Gambar shadow di tanah
    glPushMatrix();
        glDisable(GL_LIGHTING);
        glDisable(GL_DEPTH_TEST); // Agar shadow tidak tertimpa objek lain
        
        // Posisi shadow di tanah
        glTranslated(0, 0.16f, 0); // Sedikit di atas tanah untuk menghindari z-fighting
        
        // Transformasi yang sama dengan balon
        glRotated(90,0,1,0);
        glRotated(5,0,0,1);
        glRotated(rotX,1,0,0);
        glRotated(rotY,0,1,0);
        glRotated(rotZ,0,0,1);
        glScaled(0.3,0.3,0.3);

        // Terapkan shadow matrix
        glMultMatrixf((GLfloat*)shadowMat);

        // Warna shadow berdasarkan mode siang/malam
        if(isNight) {
            glColor4f(0.0f, 0.0f, 0.05f, 0.8f); // Shadow lebih gelap di malam
        } else {
            glColor4f(0.2f, 0.2f, 0.2f, 0.6f);  // Shadow abu-abu di siang hari
        }
        
        // Gambar balon untuk shadow
        balloon();
        
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_LIGHTING);
    glPopMatrix();

    // Gambar balon asli (di udara)
    glPushMatrix();
        glTranslated(0,1,0);
        glRotated(90,0,1,0);
        glRotated(5,0,0,1);
        glRotated(rotX,1,0,0);
        glRotated(rotY,0,1,0);
        glRotated(rotZ,0,0,1);
        glScaled(0.3,0.3,0.3);
        balloon();
    glPopMatrix();
}
