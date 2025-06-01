// draw.cpp
#include "draw.h"

void draw(){
    double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    
    // Hitung waktu game berdasarkan waktu start
    if(gameStarted) {
        TIME = (int)(t - startTime);
    }
    
    // Batasi TIME maksimal 60 detik
    if(TIME > 60) {
        TIME = 60;
    }

    if(rotX>11)rotX=11;
    if(rotX<-11)rotX=-11;
    if(rotZ>10)rotZ=10;
    if(rotZ<-15)rotZ=-15;
	
	drawShadowedBalloon();

    if(tX>=4.1)tX=4.1;
    if(tX<=-4.1)tX=-4.1;
    if(tY>0.1)tY= 0.1;
    if(tY<-15)tY= -15;

    glPushMatrix();
        glTranslated(tX,tY,tZ);
        environment(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ1);
        environment(3);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ2);
        environment(1);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ3);
        environment(5);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ4);
        environment(4);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ5);
        environment(2);
    glPopMatrix();

    glPushMatrix();
        glTranslated(tX,tY,tZ6);
        environment(3);
    glPopMatrix();

    // Berhenti saat time = 60
    if(TIME < 60) {
        tZ += speed;
        tZ1 += speed;
        tZ2 += speed;
        tZ3 += speed;
        tZ4 += speed;
        tZ5 += speed;
        tZ6 += speed;

        if(tZ>=20)tZ=-110;
        if(tZ1>=20)tZ1=-110;
        if(tZ2>=20)tZ2=-110;
        if(tZ3>=20)tZ3=-110;
        if(tZ4>=20)tZ4=-110;
        if(tZ5>=20)tZ5=-110;
        if(tZ6>=20)tZ6=-110;
    }

    if(rotX>0)rotX-=angleBackFrac;
    if(rotX<0)rotX+=angleBackFrac;
    if(rotY>0)rotY-=angleBackFrac;
    if(rotY<0)rotY+=angleBackFrac;
    if(rotZ>0)rotZ-=angleBackFrac;
    if(rotZ<0)rotZ+=angleBackFrac;

    if(speed < 0.2 && TIME < 100) speed += 0.00005f;
}
