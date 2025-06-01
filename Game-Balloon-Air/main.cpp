// main.cpp
#include "globals.h"
#include "draw.h"
#include "text.h"
#include "bird.h"
#include "cloud.h"
#include "balloon.h"
#include "game.h"

using namespace std;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    double a = t*90.0;

    if(!rot) a=0;

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
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    float cameraY = 4.5f + sin(t * 0.3f) * 0.1f;
    float cameraZ = 10.0f + sin(t * 0.2f) * 0.2f;
    float lookAtY = 4.0f + sin(t * 0.25f) * 0.1f;

    gluLookAt(0.0, cameraY, cameraZ,
              0, lookAtY, 0,
              0, 1.0f, 0.0f);

    // Update posisi cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);

    if(START){
        glPushMatrix();
            glTranslated(0,0,0);
            glScaled(zoom,zoom,zoom);
            glRotated(a,0,1,0);
            draw();
        glPopMatrix();
        
        drawStrokeText("UP: U, DOWN: D, LEFT: L, RIGHT: R, MAIN MENU: M ", -8, 0, 0);
        drawStrokeText("Zoom In : z , Zoom Out : Z", -8, -0.5, 0);
        drawStrokeText("Night mode : n , Day mode : d", -8, -1.0, 0);
        drawStrokeText("TIME : ", 3, 0, 0);

        int tempTime = TIME;
        int mod, number=0;
        while(tempTime){
            mod = tempTime % 10;
            number = number*10 + mod;
            tempTime /= 10;
        }
        float tmp=0;
        while(number){
            mod = number % 10;
            drawStrokeChar(mod + 48, 4 + tmp, 0, 0);
            number /= 10;
            tmp += 0.2f;
        }

        if(TIME >= 60){
            drawStrokeText("FINISH!", -0.5, -0.25, 0.0);
        }
    }
    else{
        const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;

        glPushMatrix();
            glTranslated(3 + sin(t * 0.1) * 0.5, 7, -5);
            cloud();
        glPopMatrix();

        glPushMatrix();
            glTranslated(-4 + sin(t * 0.12) * 0.5, 8, -6);
            cloud();
        glPopMatrix();

        // Burung dikurangi, tampilkan 2 burung saja di menu utama
        drawBird(3 + sin(t * 0.3) * 1.0, 6, -4, 0.3, sin(t * 5.0) * 30.0, 0.3, 0.3, 0.7);
        drawBird(-2 + sin(t * 0.25) * 1.2, 7, -5, 0.2, sin(t * 4.8) * 30.0, 0.7, 0.3, 0.3);

        glPushMatrix();
            glTranslated(0, 1, 0);
            glRotated(a, 0, 1, 0);
            glScaled(1.5, 1.5, 1.5);
            balloon();
        glPopMatrix();

        drawStrokeText("Press S to Start", -1, -2, 0);
        drawStrokeText("Simulator Balon Udara di atas Hutan", -2, -0.8, 0);
    }

    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    float frac = 0.3f;
    float rotFrac = 1.0f;
    switch (key)
    {
        case 27:
        case 'q':
            exit(0);
            break;
        case 'r':
            rot = true;
            break;
        case 't':
            rot = false;
            break;
        case 'Z':
            zoom += 0.05f;
            break;
        case 'z':
            zoom -= 0.05f;
            break;
        case 'U':
            if(START) {
                tY -= frac;
                rotZ += rotFrac;
            }
            break;
        case 'D':
            if(START) {
                tY += frac;
                rotZ -= rotFrac;
            }
            break;
        case 'L':
            if(START) {
                tX += frac;
                rotX -= rotFrac * 3;
                rotY += rotFrac / 2;
            }
            break;
        case 'R':
            if(START) {
                tX -= frac;
                rotX += rotFrac * 3;
                rotY -= rotFrac / 2;
            }
            break;
        case 'S':
            if(!START) {
                START = true;
                gameStarted = true;
                // Catat waktu saat game dimulai
                startTime = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
                TIME = 0;  // Set timer ke 0
            }
            break;
        case 'M':
            resetGame();
            break;
        case 'n': 
            isNight = true;
            break;
        case 'd':
            isNight = false;
            break;
    }
    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(800, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

    glutCreateWindow("Simulator Balon Udara di atas Hutan");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    initBirds();
    initClouds();

    glClearColor(0.725,0.9,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

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
    
    // Enable blending untuk efek transparansi shadow
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glutMainLoop();

    return EXIT_SUCCESS;
}
