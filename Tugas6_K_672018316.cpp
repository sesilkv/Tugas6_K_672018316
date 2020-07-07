#include <windows.h>
#include <GL/glut.h>

//deklarasi
void init(void);
void display(void);
void keyb(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran (int, int);
void mouseMotion(int x, int y);

//z mendekati positif, jauh negatif
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth; //transparan

void init(void){
    glClearColor(0.1, 0.5, 0.68, 0.7);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
  //  gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    if(is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

    //tiang atas kanan
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.7, 0.3);
        glVertex3f(-1.0, 43.0, 39.5);
        glVertex3f(-1.0, 55.0, 39.5);
        glVertex3f(3.0, 55.0, 39.5);
        glVertex3f(3.0, 43.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 43.0, 36);
        glVertex3f(-1.0, 55.0, 36);
        glVertex3f(3.0, 55.0, 36);
        glVertex3f(3.0, 43.0, 36);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 43.0, 39.5);
        glVertex3f(-1.0, 55.0, 39.5);
        glVertex3f(-1.0, 55.0, 36.0);
        glVertex3f(-1.0, 43.0, 36.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(3.0, 43.0, 39.5);
        glVertex3f(3.0, 55.0, 39.5);
        glVertex3f(3.0, 55.0, 36.0);
        glVertex3f(3.0, 43.0, 36.0);
    glEnd();

    //tiang atas kiri
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.7, 0.3);
        glVertex3f(-45.0, 43.0, 39.5);
        glVertex3f(-45.0, 55.0, 39.5);
        glVertex3f(-41.0, 55.0, 39.5);
        glVertex3f(-41.0, 43.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 43.0, 36);
        glVertex3f(-45.0, 55.0, 36);
        glVertex3f(-41.0, 55.0, 36);
        glVertex3f(-41.0, 43.0, 36);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-41.0, 43.0, 39.5);
        glVertex3f(-41.0, 55.0, 39.5);
        glVertex3f(-41.0, 55.0, 36.0);
        glVertex3f(-41.0, 43.0, 36.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 43.0, 39.5);
        glVertex3f(-45.0, 55.0, 39.5);
        glVertex3f(-45.0, 55.0, 36.0);
        glVertex3f(-45.0, 43.0, 36.0);
    glEnd();

    //depan atas krem
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.85, 0.5);
        glVertex3f(-41.0, 43.0, 38.0);
        glVertex3f(-41.0, 55.0, 38.0);
        glVertex3f(-1.0, 55.0, 38.0);
        glVertex3f(-1.0, 43.0, 38.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.8, 0.6);
        glVertex3f(-35.0, 29.5, 38.015);
        glVertex3f(-35.0, 37.0, 38.015);
        glVertex3f(-7.0, 37.0, 38.015);
        glVertex3f(-7.0, 29.5, 38.015);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.75, 0.5);
        glVertex3f(-37.0, 27.5, 38.01);
        glVertex3f(-37.0, 39.0, 38.01);
        glVertex3f(-5.0, 39.0, 38.01);
        glVertex3f(-5.0, 27.5, 38.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-33.0, 34.75, 38.017);
        glVertex3f(-33.0, 35.75, 38.017);
        glVertex3f(-9.0, 35.75, 38.017);
        glVertex3f(-9.0, 34.75, 38.017);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-33.0, 33.25, 38.017);
        glVertex3f(-33.0, 34.25, 38.017);
        glVertex3f(-9.0, 34.25, 38.017);
        glVertex3f(-9.0, 33.25, 38.017);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-33.0, 31.75, 38.017);
        glVertex3f(-33.0, 32.75, 38.017);
        glVertex3f(-9.0, 32.75, 38.017);
        glVertex3f(-9.0, 31.75, 38.017);
    glEnd();


    glBegin(GL_POLYGON);
        glVertex3f(-35.0, 45.5, 38.01);
        glVertex3f(-35.0, 53.0, 38.01);
        glVertex3f(-32.0, 53.0, 38.01);
        glVertex3f(-32.0, 45.5, 38.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-23.0, 45.5, 38.01);
        glVertex3f(-23.0, 53.0, 38.01);
        glVertex3f(-20.0, 53.0, 38.01);
        glVertex3f(-20.0, 45.5, 38.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-11.0, 45.5, 38.01);
        glVertex3f(-11.0, 53.0, 38.01);
        glVertex3f(-8.0, 53.0, 38.01);
        glVertex3f(-8.0, 45.5, 38.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(10.0, 45.5, 10.01);
        glVertex3f(10.0, 53.0, 10.01);
        glVertex3f(13.0, 53.0, 10.01);
        glVertex3f(13.0, 45.5, 10.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(22.0, 45.5, 10.01);
        glVertex3f(22.0, 53.0, 10.01);
        glVertex3f(25.0, 53.0, 10.01);
        glVertex3f(25.0, 45.5, 10.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(34.0, 45.5, 10.01);
        glVertex3f(34.0, 53.0, 10.01);
        glVertex3f(37.0, 53.0, 10.01);
        glVertex3f(37.0, 45.5, 10.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(34.0, 31.5, 10.01);
        glVertex3f(34.0, 39.0, 10.01);
        glVertex3f(37.0, 39.0, 10.01);
        glVertex3f(37.0, 31.5, 10.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(22.0, 31.5, 10.01);
        glVertex3f(22.0, 39.0, 10.01);
        glVertex3f(25.0, 39.0, 10.01);
        glVertex3f(25.0, 31.5, 10.01);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(10.0, 31.5, 10.01);
        glVertex3f(10.0, 39.0, 10.01);
        glVertex3f(13.0, 39.0, 10.01);
        glVertex3f(13.0, 31.5, 10.01);
    glEnd();

    //atas krem1
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.65);
        glVertex3f(-45.0, 23.0, 45.0);
        glVertex3f(10.0, 23.0, 45.0);
        glVertex3f(10.0, 23.0, 10.0);
        glVertex3f(-45.0, 23.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(8.0, 23.0, 20.0);
        glVertex3f(45.0, 23.0, 20.0);
        glVertex3f(45.0, 23.0, 10.0);
        glVertex3f(8.0, 23.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(45.0, 23.0, 30.0);
        glVertex3f(40.0, 23.0, 30.0);
        glVertex3f(40.0, 23.0, 10.0);
        glVertex3f(45.0, 23.0, 10.0);
    glEnd();

    //atas krem2
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.65);
        glVertex3f(-45.0, 43.0, 43.0);
        glVertex3f(6.0, 43.0, 43.0);
        glVertex3f(6.0, 43.0, 10.0);
        glVertex3f(-45.0, 43.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(6.0, 43.0, 15.0);
        glVertex3f(45.0, 43.0, 15.0);
        glVertex3f(45.0, 43.0, 10.0);
        glVertex3f(6.0, 43.0, 10.0);
    glEnd();

    //samping krem tengah
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.85, 0.5);
        glVertex3f(3.0, 43.0, 36.0);
        glVertex3f(3.0, 23.0, 36.0);
        glVertex3f(3.0, 23.0, 10.0);
        glVertex3f(3.0, 43.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 43.0, 36.0);
        glVertex3f(-45.0, 23.0, 36.0);
        glVertex3f(-45.0, 23.0, 10.0);
        glVertex3f(-45.0, 43.0, 10.0);
    glEnd();

    //samping krem atas
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.85, 0.5);
        glVertex3f(3.0, 55.0, 36.0);
        glVertex3f(3.0, 43.0, 36.0);
        glVertex3f(3.0, 43.0, 10.0);
        glVertex3f(3.0, 55.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 55.0, 36.0);
        glVertex3f(-45.0, 43.0, 36.0);
        glVertex3f(-45.0, 43.0, 10.0);
        glVertex3f(-45.0, 55.0, 10.0);
    glEnd();

    //depan tengah krem
    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.85, 0.5);
        glVertex3f(-45.0, 23.0, 10.0);
        glVertex3f(-45.0, 55.0, 10.0);
        glVertex3f(45.0, 55.0, 10.0);
        glVertex3f(45.0, 23.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-45.0, 23.0, 9.9);
        glVertex3f(-45.0, 55.0, 9.9);
        glVertex3f(45.0, 55.0, 9.9);
        glVertex3f(45.0, 23.0, 9.9);
    glEnd();


    //depan abuabu
    glBegin(GL_POLYGON);
        glColor4f(0.55, 0.55, 0.5, 0.55);
        glVertex3f(-41.0, 23.0, 38.0);
        glVertex3f(-41.0, 43.0, 38.0);
        glVertex3f(-1.0, 43.0, 38.0);
        glVertex3f(-1.0, 23.0, 38.0);
    glEnd();

    //tiang tengah kanan
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.7, 0.3);
        glVertex3f(-1.0, 23.0, 39.5);
        glVertex3f(-1.0, 43.0, 39.5);
        glVertex3f(3.0, 43.0, 39.5);
        glVertex3f(3.0, 23.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 23.0, 36);
        glVertex3f(-1.0, 43.0, 36);
        glVertex3f(3.0, 43.0, 36);
        glVertex3f(3.0, 23.0, 36);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 23.0, 39.5);
        glVertex3f(-1.0, 43.0, 39.5);
        glVertex3f(-1.0, 43.0, 36.0);
        glVertex3f(-1.0, 23.0, 36.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(3.0, 23.0, 39.5);
        glVertex3f(3.0, 43.0, 39.5);
        glVertex3f(3.0, 43.0, 36.0);
        glVertex3f(3.0, 23.0, 36.0);
    glEnd();

    //tiang tengah kiri
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.7, 0.3);
        glVertex3f(-45.0, 23.0, 39.5);
        glVertex3f(-45.0, 43.0, 39.5);
        glVertex3f(-41.0, 43.0, 39.5);
        glVertex3f(-41.0, 23.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 23.0, 36);
        glVertex3f(-45.0, 43.0, 36);
        glVertex3f(-41.0, 43.0, 36);
        glVertex3f(-41.0, 23.0, 36);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-41.0, 23.0, 39.5);
        glVertex3f(-41.0, 43.0, 39.5);
        glVertex3f(-41.0, 43.0, 36.0);
        glVertex3f(-41.0, 23.0, 36.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 23.0, 39.5);
        glVertex3f(-45.0, 43.0, 39.5);
        glVertex3f(-45.0, 43.0, 36.0);
        glVertex3f(-45.0, 23.0, 36.0);
    glEnd();

    //kaca jendela1
    glBegin(GL_QUADS);
        glColor3f(0.05, 0.05, 0.0);
        glVertex3f(-41.5, -8.5, 10.1);
        glVertex3f(-41.5, 10.0, 10.1);
        glVertex3f(-37.5, 10.0, 10.1);
        glVertex3f(-37.5, -8.5, 10.1);
    glEnd();

    //jendela1
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-43.0, -10.0, 10.0);
        glVertex3f(-43.0, 11.5, 10.0);
        glVertex3f(-36.0, 11.5, 10.0);
        glVertex3f(-36.0, -10.0, 10.0);
    glEnd();

    //kaca jendela2
    glBegin(GL_QUADS);
        glColor3f(0.05, 0.05, 0.0);
        glVertex3f(-6.5, -8.5, 10.1);
        glVertex3f(-6.5, 10.0, 10.1);
        glVertex3f(-2.5, 10.0, 10.1);
        glVertex3f(-2.5, -8.5, 10.1);
    glEnd();

    //jendela2
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-8.0, -10.0, 10.0);
        glVertex3f(-8.0, 11.5, 10.0);
        glVertex3f(-1.0, 11.5, 10.0);
        glVertex3f(-1.0, -10.0, 10.0);
    glEnd();

    //kaca jendela3
    glBegin(GL_QUADS);
        glColor3f(0.05, 0.05, 0.0);
        glVertex3f(8.5, -9.5, 10.1);
        glVertex3f(8.5, 9.5, 10.1);
        glVertex3f(14.5, 9.5, 10.1);
        glVertex3f(14.5, -9.5, 10.1);
    glEnd();

    //jendela3
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(7.0, -12.0, 10.0);
        glVertex3f(7.0, 11.5, 10.0);
        glVertex3f(16.0, 11.5, 10.0);
        glVertex3f(16.0, -12.0, 10.0);
    glEnd();

    //hiasan
    glBegin(GL_QUADS);
        glColor3f(0.3, 0.05, 0.0);
        glVertex3f(19.5, -5.0, 10.0);
        glVertex3f(19.5, 11.5, 10.0);
        glVertex3f(28.5, 11.5, 10.0);
        glVertex3f(28.5, -5.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(1.0, 0.8, 0.9);
        glVertex3f(20.5, -4.0, 10.05);
        glVertex3f(20.5, 10.5, 10.05);
        glVertex3f(27.5, 10.5, 10.05);
        glVertex3f(27.5, -4.0, 10.05);
    glEnd();

    //kaca jendela4
    glBegin(GL_QUADS);
        glColor3f(0.05, 0.05, 0.0);
        glVertex3f(33.5, -9.5, 10.1);
        glVertex3f(33.5, 9.5, 10.1);
        glVertex3f(39.5, 9.5, 10.1);
        glVertex3f(39.5, -9.5, 10.1);
    glEnd();

    //jendela4
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(32.0, -12.0, 10.0);
        glVertex3f(32.0, 11.5, 10.0);
        glVertex3f(41.0, 11.5, 10.0);
        glVertex3f(41.0, -12.0, 10.0);
    glEnd();

    //bolongan1
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-41.0, 19.0, 10.0);
        glVertex3f(-41.0, 15.5, 10.0);
        glVertex3f(-38.0, 15.5, 10.0);
        glVertex3f(-38.0, 19.0, 10.0);
    glEnd();

    //bol1
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-45.0, 19.0, 10.0);
        glVertex3f(-45.0, 15.5, 10.0);
        glVertex3f(-41.0, 15.5, 10.0);
        glVertex3f(-41.0, 19.0, 10.0);
    glEnd();

    //bol2
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-38.0, 19.0, 10.0);
        glVertex3f(-38.0, 15.5, 10.0);
        glVertex3f(-32.0, 15.5, 10.0);
        glVertex3f(-32.0, 19.0, 10.0);
    glEnd();

    //bol3
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-29.0, 19.0, 10.0);
        glVertex3f(-29.0, 15.5, 10.0);
        glVertex3f(-23.5, 15.5, 10.0);
        glVertex3f(-23.5, 19.0, 10.0);
    glEnd();

    //bolongan2
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-32.0, 19.0, 10.0);
        glVertex3f(-32.0, 15.5, 10.0);
        glVertex3f(-29.0, 15.5, 10.0);
        glVertex3f(-29.0, 19.0, 10.0);
    glEnd();

    //bol4
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-20.5, 19.0, 10.0);
        glVertex3f(-20.5, 15.5, 10.0);
        glVertex3f(-15.0, 15.5, 10.0);
        glVertex3f(-15.0, 19.0, 10.0);
    glEnd();

    //bolongan3
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-23.5, 19.0, 10.0);
        glVertex3f(-23.5, 15.5, 10.0);
        glVertex3f(-20.5, 15.5, 10.0);
        glVertex3f(-20.5, 19.0, 10.0);
    glEnd();

    //bolongan4
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-15.0, 19.0, 10.0);
        glVertex3f(-15.0, 15.5, 10.0);
        glVertex3f(-12.0, 15.5, 10.0);
        glVertex3f(-12.0, 19.0, 10.0);
    glEnd();

    //bol5
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-12.0, 19.0, 10.0);
        glVertex3f(-12.0, 15.5, 10.0);
        glVertex3f(-6.0, 15.5, 10.0);
        glVertex3f(-6.0, 19.0, 10.0);
    glEnd();

    //bolongan5
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-6.0, 19.0, 10.0);
        glVertex3f(-6.0, 15.5, 10.0);
        glVertex3f(-3.0, 15.5, 10.0);
        glVertex3f(-3.0, 19.0, 10.0);
    glEnd();

    //bol6
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-3.0, 19.0, 10.0);
        glVertex3f(-3.0, 15.5, 10.0);
        glVertex3f(10.0, 15.5, 10.0);
        glVertex3f(10.0, 19.0, 10.0);
    glEnd();

    //bolongan6
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(10.0, 19.0, 10.0);
        glVertex3f(10.0, 15.5, 10.0);
        glVertex3f(13.0, 15.5, 10.0);
        glVertex3f(13.0, 19.0, 10.0);
    glEnd();

    //bol7
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(13.0, 19.0, 10.0);
        glVertex3f(13.0, 15.5, 10.0);
        glVertex3f(35.0, 15.5, 10.0);
        glVertex3f(35.0, 19.0, 10.0);
    glEnd();

    //bolongan7
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(35.0, 19.0, 10.0);
        glVertex3f(35.0, 15.5, 10.0);
        glVertex3f(38.0, 15.5, 10.0);
        glVertex3f(38.0, 19.0, 10.0);
    glEnd();

    //bol8
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(38.0, 19.0, 10.0);
        glVertex3f(38.0, 15.5, 10.0);
        glVertex3f(45.0, 15.5, 10.0);
        glVertex3f(45.0, 19.0, 10.0);
    glEnd();

    //depan ijo atas
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-45.0, 19.0, 10.0);
        glVertex3f(-45.0, 23.0, 10.0);
        glVertex3f(45.0, 23.0, 10.0);
        glVertex3f(45.0, 19.0, 10.0);
    glEnd();

    //depan ijo atas2
    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 11.5, 10.0);
        glVertex3f(-45.0, 15.5, 10.0);
        glVertex3f(45.0, 15.5, 10.0);
        glVertex3f(45.0, 11.5, 10.0);
    glEnd();

    //depan ijo tengah1
    glBegin(GL_POLYGON);
        glVertex3f(-45.0, -12.0, 10.0);
        glVertex3f(-45.0,11.5, 10.0);
        glVertex3f(-43.0,11.5, 10.0);
        glVertex3f(-43.0, -12.0, 10.0);
    glEnd();

    //depan ijo tengah2
    glBegin(GL_POLYGON);
        glVertex3f(-36.0, -12.0, 10.0);
        glVertex3f(-36.0, 11.5, 10.0);
        glVertex3f(-33.0, 11.5, 10.0);
        glVertex3f(-33.0, -12.0, 10.0);
    glEnd();

     //depan ijo tengah3
    glBegin(GL_POLYGON);
        glVertex3f(-11.0, -12.0, 10.0);
        glVertex3f(-11.0, 11.5, 10.0);
        glVertex3f(-8.0, 11.5, 10.0);
        glVertex3f(-8.0, -12.0, 10.0);
    glEnd();

    //depan ijo tengah4
    glBegin(GL_POLYGON);
        glVertex3f(-1.0, -12.0, 10.0);
        glVertex3f(-1.0, 11.5, 10.0);
        glVertex3f(7.0, 11.5, 10.0);
        glVertex3f(7.0, -12.0, 10.0);
    glEnd();

    //depan ijo tengah5
    glBegin(GL_POLYGON);
        glVertex3f(16.0, -12.0, 10.0);
        glVertex3f(16.0, 11.5, 10.0);
        glVertex3f(19.5, 11.5, 10.0);
        glVertex3f(19.5, -12.0, 10.0);
    glEnd();

    //depan ijo tengah6
    glBegin(GL_POLYGON);
        glVertex3f(28.5, -12.0, 10.0);
        glVertex3f(28.5, 11.5, 10.0);
        glVertex3f(32.0, 11.5, 10.0);
        glVertex3f(32.0, -12.0, 10.0);
    glEnd();

    //depan ijo tengah7
    glBegin(GL_POLYGON);
        glVertex3f(41.0, -12.0, 10.0);
        glVertex3f(41.0, 11.5, 10.0);
        glVertex3f(45.0, 11.5, 10.0);
        glVertex3f(45.0, -12.0, 10.0);
    glEnd();

    //depan ijo bawah1
    glBegin(GL_POLYGON);
        glVertex3f(-43.0, -12.0, 10.0);
        glVertex3f(-43.0, -10, 10.0);
        glVertex3f(-36.0, -10, 10.0);
        glVertex3f(-36.0, -12.0, 10.0);
    glEnd();

    //depan ijo bawah2
    glBegin(GL_POLYGON);
        glVertex3f(-8.0, -12.0, 10.0);
        glVertex3f(-8.0, -10, 10.0);
        glVertex3f(-1.0, -10, 10.0);
        glVertex3f(-1.0, -12.0, 10.0);
    glEnd();

    //depan ijo bawah3
    glBegin(GL_POLYGON);
        glVertex3f(19.5, -12.0, 10.0);
        glVertex3f(19.5, -5.0, 10.0);
        glVertex3f(28.5, -5.0, 10.0);
        glVertex3f(28.5, -12.0, 10.0);
    glEnd();

    //depan bawah
    glBegin(GL_POLYGON);
        glVertex3f(-45.0, -15.0, 10.0);
        glVertex3f(-45.0, -12.0, 10.0);
        glVertex3f(45.0, -12.0, 10.0);
        glVertex3f(45.0, -15.0, 10.0);
    glEnd();

    //atas tiang
    glBegin(GL_POLYGON);
        glColor3f(0.3, 0.7, 0.3);
        glVertex3f(-45, 20.0, 39.5);
        glVertex3f(-45, 23.0, 39.5);
        glVertex3f(3.0, 23.0, 39.5);
        glVertex3f(3.0, 20.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(3.0, 23.0, 39.5);
        glVertex3f(3.0, 20.0, 39.5);
        glVertex3f(3.0, 20.0, 10.0);
        glVertex3f(3.0, 23.0, 10.0);
    glEnd();

    //tiang bawah kanan
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.7, 0.3);
        glVertex3f(-1.0, -12.0, 39.5);
        glVertex3f(-1.0, 20.0, 39.5);
        glVertex3f(3.0, 20.0, 39.5);
        glVertex3f(3.0, -12.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, 23.0, 36);
        glVertex3f(-1.0, -12.0, 36);
        glVertex3f(3.0, -12.0, 36);
        glVertex3f(3.0, 23.0, 36);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-1.0, -12.0, 39.5);
        glVertex3f(-1.0, 23.0, 39.5);
        glVertex3f(-1.0, 23.0, 36.0);
        glVertex3f(-1.0, -12.0, 36.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(3.0, -12.0, 39.5);
        glVertex3f(3.0, 23.0, 39.5);
        glVertex3f(3.0, 23.0, 36.0);
        glVertex3f(3.0, -12.0, 36.0);
    glEnd();

    //tiang bawah kiri
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.7, 0.3);
        glVertex3f(-45.0, -12.0, 39.5);
        glVertex3f(-45.0, 20.0, 39.5);
        glVertex3f(-41.0, 20.0, 39.5);
        glVertex3f(-41.0, -12.0, 39.5);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, -12.0, 36);
        glVertex3f(-45.0, 23.0, 36);
        glVertex3f(-41.0, 23.0, 36);
        glVertex3f(-41.0, -12.0, 36);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-41.0, -12.0, 39.5);
        glVertex3f(-41.0, 23.0, 39.5);
        glVertex3f(-41.0, 23.0, 36.0);
        glVertex3f(-41.0, -12.0, 36.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-45.0, -12.0, 39.5);
        glVertex3f(-45.0, 23.0, 39.5);
        glVertex3f(-45.0, 23.0, 36.0);
        glVertex3f(-45.0, -12.0, 36.0);
    glEnd();

    //kaca pintu
    glBegin(GL_QUADS);
        glColor3f(0.05, 0.05, 0.0);
        glVertex3f(-26.0, -2.0, 10.0);
        glVertex3f(-26.0, 8.5, 10.0);
        glVertex3f(-24.0, 8.5, 10.0);
        glVertex3f(-24.0, -2.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-20.0, -2.0, 10.0);
        glVertex3f(-20.0, 8.5, 10.0);
        glVertex3f(-18.0, 8.5, 10.0);
        glVertex3f(-18.0, -2.0, 10.0);
    glEnd();

    //pegangan pintu
    glBegin(GL_QUADS);
        glColor3f(0.9, 0.8, 1.0);
        glVertex3f(-21.4, -2.0, 10.5);
        glVertex3f(-21.4, 4.0, 10.5);
        glVertex3f(-21.0, 4.0, 10.5);
        glVertex3f(-21.0, -2.0, 10.5);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.9, 0.8, 1.0);
        glVertex3f(-22.8, -2.0, 10.5);
        glVertex3f(-22.8, 4.0, 10.5);
        glVertex3f(-22.4, 4.0, 10.5);
        glVertex3f(-22.4, -2.0, 10.5);
    glEnd();

    //pintu
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.15, 0.0);
        glVertex3f(-31.0, -12.0, 10.0);
        glVertex3f(-31.0, 9.5, 10.0);
        glVertex3f(-13.0, 9.5, 10.0);
        glVertex3f(-13.0, -12.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.5, 0.05, 0.0);
        glVertex3f(-33.0, -12.0, 10.0);
        glVertex3f(-33.0, 9.5, 10.0);
        glVertex3f(-31.0, 9.5, 10.0);
        glVertex3f(-31.0, -12.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-13.0, -12.0, 10.0);
        glVertex3f(-13.0, 9.5, 10.0);
        glVertex3f(-11.0, 9.5, 10.0);
        glVertex3f(-11.0, -12.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(-33.0, 9.5, 10.0);
        glVertex3f(-33.0, 11.5, 10.0);
        glVertex3f(-11.0, 11.5, 10.0);
        glVertex3f(-11.0, 9.5, 10.0);
    glEnd();

    //teras
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.775, 0.1);
        glVertex3f(-45.0, -12.0, 40.5);
        glVertex3f(4.5, -12.0, 40.5);
        glVertex3f(4.5, -12.0, 10.0);
        glVertex3f(-45.0, -12.0, 10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 0.8, 0.2);
        glVertex3f(-45.0, -15.0, 40.5);
        glVertex3f(-45.0, -12.0, 40.5);
        glVertex3f(4.5, -12.0, 39.0);
        glVertex3f(4.5, -15.0, 39.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(4.5, -12.0, 40.5);
        glVertex3f(4.5, -15.0, 40.5);
        glVertex3f(4.5, -15.0, 10.0);
        glVertex3f(4.5, -12.0, 10.0);
    glEnd();

     //turunan
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.15, 0.0);
        glVertex3f(-28.0, -15.0, 46);
        glVertex3f(-10.0, -15.0, 46);
        glVertex3f(-10.0, -12.0, 40.5);
        glVertex3f(-28.0, -12.0, 40.5);
    glEnd();

    //kiri ijo
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.82, 0.0);
        glVertex3f(-45.1, 55.0, 39.5);
        glVertex3f(-45.1, -15.0, 39.5);
        glVertex3f(-45.1, -15.0, -155.0);
        glVertex3f(-45.1, 55.0, -155.0);
    glEnd();

    //kiri abu
    glBegin(GL_POLYGON);
        glColor4f(0.7, 0.82, 0.7, 0.75);
        glVertex3f(-45.1, 6.0, 60.0);
        glVertex3f(-45.1, -15.0, 60.0);
        glVertex3f(-45.1, -15.0, 39.5);
        glVertex3f(-45.1, 6.0, 39.5);
    glEnd();

    //kiri ijo2
    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.8, 0.3);
        glVertex3f(-45.1, 9.0, 60.0);
        glVertex3f(-45.1, 6.0, 60.0);
        glVertex3f(-45.1, 6.0, 39.5);
        glVertex3f(-45.1, 9.0, 39.5);
    glEnd();

    //kanan
    glBegin(GL_POLYGON);
        glColor4f(0.9, 1.0, 1.0, 1.0);
        glVertex3f(44.9, -12.0, 10.0);
        glVertex3f(44.9, -15.0, 10.0);
        glVertex3f(44.9, -15.0, -50.0);
        glVertex3f(44.9, -12.0, -50.0);
    glEnd();

    //kanan ijo
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.82, 0.0);
        glVertex3f(45.0, 55.0, 30.0);
        glVertex3f(45.0, -15.0, 30.0);
        glVertex3f(45.0, -15.0, -155.0);
        glVertex3f(45.0, 55.0, -155.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(45.0, 13.0, 30.0);
        glVertex3f(45.0, 13.0, 37.0);
        glVertex3f(45.0, 5.0, 38.0);
        glVertex3f(45.0, -15.0, 38.0);
        glVertex3f(45.0, -15.0, 30.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(45.0, 5.0, 38.0);
        glVertex3f(45.0, 5.0, 55.0);
        glVertex3f(45.0, -15.0, 55.0);
        glVertex3f(45.0, -15.0, 38.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(45.0, 7.5, 55.0);
        glVertex3f(45.0, 7.5, 60.0);
        glVertex3f(45.0, -15.0, 60.0);
        glVertex3f(45.0, -15.0, 55.0);
    glEnd();

    //bawah
    glBegin(GL_QUADS);
        glColor4f(0.5, 0.65, 0.6, 1.0);
        glVertex3f(-45.0, -15.0, 60.0);
        glVertex3f(45.0, -15.0, 60.0);
        glVertex3f(45.0, -15.0, -155.0);
        glVertex3f(-45.0, -15.0, -155.0);
    glEnd();

    //lantai rumah
    glBegin(GL_QUADS);
        glColor4f(0.9, 1.0, 1.0, 1.0);
        glVertex3f(-45.0, -12.0, 10.0);
        glVertex3f(45.0, -12.0, 10.0);
        glVertex3f(45.0, -12.0, -110.0);
        glVertex3f(-45.0, -12.0, -110.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(0.0, -12.0, -110.0);
        glVertex3f(45.0, -12.0, -110.0);
        glVertex3f(45.0, -12.0, -155.0);
        glVertex3f(0.0, -12.0, -155.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.82, 0.0);
        glVertex3f(-45.1, -15.0, -155.0);
        glVertex3f(-45.1, 55.0, -155.0);
        glVertex3f(45.0, 55.0, -155.0);
        glVertex3f(45.0, -15.0, -155.0);
    glEnd();

    //sekat
    glBegin(GL_POLYGON);
        glColor3f(0.9, 0.9, 0.0);
        glVertex3f(-45.0, -15.0, -110.0);
        glVertex3f(-45.0, 55.0, -110.0);
        glVertex3f(0.0, 55.0, -110.0);
        glVertex3f(0.0, -15.0, -110.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(22.0, -15.0, -110.0);
        glVertex3f(22.0, 55.0, -110.0);
        glVertex3f(45.0, 55.0, -110.0);
        glVertex3f(45.0, -15.0, -110.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(0.0, 35.0, -110.0);
        glVertex3f(0.0, 55.0, -110.0);
        glVertex3f(22.0, 55.0, -110.0);
        glVertex3f(22.0, 35.0, -110.0);
    glEnd();

    //atap datar ijo
    glBegin(GL_QUADS);
        glColor3f(0.0, 0.9, 0.0);
        glVertex3f(-45.0, 55.0, 10.0);
        glVertex3f(45.0, 55.0, 10.0);
        glVertex3f(45.0, 55.0, -110.0);
        glVertex3f(-45.0, 55.0, -110.0);
    glEnd();

    //atap krem
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.9, 0.65);
        glVertex3f(-45.0, 55.0, 40.0);
        glVertex3f(3.0, 55.0, 40.0);
        glVertex3f(3.0, 55.0, 10.0);
        glVertex3f(-45.0, 55.0, 10.0);
    glEnd();

    //ijo tambahan
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.82, 0.0);
        glVertex3f(45.0, 80.0, -110.0);
        glVertex3f(45.0, 55.0, -110.0);
        glVertex3f(45.0, 55.0, -155.0);
        glVertex3f(45.0, 80.0, -155.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.5, 0.1, 0.0);
        glVertex3f(0.0, 55.0, -110.0);
        glVertex3f(45.0, 80.0, -110.0);
        glVertex3f(45.0, 80.0, -155.0);
        glVertex3f(0.0, 55.0, -155.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(0.0, 55.0, -110.0);
        glVertex3f(45.0, 55.0, -110.0);
        glVertex3f(45.0, 80.0, -110.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.82, 0.0);
        glVertex3f(0.0, 55.0, -155.0);
        glVertex3f(45.0, 55.0, -155.0);
        glVertex3f(45.0, 80.0, -155.0);
    glEnd();

    //atap miring kiri coklat
    glBegin(GL_QUADS);
        glColor3f(0.5, 0.1, 0.0);
        glVertex3f(-45.0, 55.0, 10.0);
        glVertex3f(0.0, 80.0, 10.0);
        glVertex3f(0.0, 80.0, -110.0);
        glVertex3f(-45.0, 55.0, -110.0);
    glEnd();

    //atap miring kanan coklat
    glBegin(GL_QUADS);
        glVertex3f(0.0, 80.0, 10.0);
        glVertex3f(45.0, 55.0, 10.0);
        glVertex3f(45.0, 55.0, -110.0);
        glVertex3f(0.0, 80.0, -110.0);
    glEnd();

    //depan
    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 55.0, 10.0);
        glVertex3f(45.0, 55.0, 10.0);
        glVertex3f(0.0, 80.0, 10.0);
    glEnd();

    //belakang
    glBegin(GL_POLYGON);
        glVertex3f(-45.0, 55.0, -110.0);
        glVertex3f(45.0, 55.0, -110.0);
        glVertex3f(0.0, 80.0, -110.0);
    glEnd();

    //kanopi
    glBegin(GL_QUADS);
        glColor4f(0.5, 0.55, 0.6, 1.0);
        glVertex3f(2.0, 23.1, 60.0);
        glVertex3f(45.0, 23.1, 60.0);
        glVertex3f(45.0, 23.1, 10.0);
        glVertex3f(2.0, 23.1, 10.0);
    glEnd();

    //tiang kanopi kanan
    glBegin(GL_POLYGON);
        glColor3f(0.3, 0.0, 0.0);
        glVertex3f(42.0, -15.0, 59.0);
        glVertex3f(43.0, -15.0, 59.0);
        glVertex3f(43.0, 23.1, 59.0);
        glVertex3f(42.0, 23.1, 59.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(42.0, -15.0, 58.0);
        glVertex3f(43.0, -15.0, 58.0);
        glVertex3f(43.0, 23.1, 58.0);
        glVertex3f(42.0, 23.1, 58.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(43.0, -15.0, 59.0);
        glVertex3f(43.0, 23.1, 59.0);
        glVertex3f(43.0, 23.1, 58.0);
        glVertex3f(43.0, -15.0, 58.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(42.0, -15.0, 59.0);
        glVertex3f(42.0, 23.1, 59.0);
        glVertex3f(42.0, 23.1, 58.0);
        glVertex3f(42.0, -15.0, 58.0);
    glEnd();

    //tiang kanopi kiri
    glBegin(GL_POLYGON);
        glVertex3f(4.0, -15.0, 59);
        glVertex3f(5.0, -15.0, 59);
        glVertex3f(5.0, 23.1, 59);
        glVertex3f(4.0, 23.1, 59);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(4.0, -15.0, 58.0);
        glVertex3f(5.0, -15.0, 58.0);
        glVertex3f(5.0, 23.1, 58.0);
        glVertex3f(4.0, 23.1, 58.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(5.0, -15.0, 59.0);
        glVertex3f(5.0, 23.1, 59.0);
        glVertex3f(5.0, 23.1, 58.0);
        glVertex3f(5.0, -15.0, 58.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(4.0, -15.0, 59.0);
        glVertex3f(4.0, 23.1, 59.0);
        glVertex3f(4.0, 23.1, 58.0);
        glVertex3f(4.0, -15.0, 58.0);
    glEnd();

    //tv
    glBegin(GL_POLYGON);
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(-35.0, 13.0, -109.9);
        glVertex3f(-12.0, 13.0, -109.9);
        glVertex3f(-12.0, 30.5, -109.9);
        glVertex3f(-35.0, 30.5, -109.9);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.01, 0.01, 0.25);
        glVertex3f(-33.0, 15.0, -109.89);
        glVertex3f(-14.2, 15.0, -109.89);
        glVertex3f(-14.2, 28.5, -109.89);
        glVertex3f(-33.0, 28.5, -109.89);
    glEnd();

    glLineWidth(1.0);
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-31.0, 25.0, -109.88);
        glVertex3f(-25.0, 25.0, -109.88);
        glVertex3f(-25.0, 23.5, -109.88);
        glVertex3f(-27.5, 23.5, -109.88);
        glVertex3f(-27.5, 18.0, -109.88);
        glVertex3f(-29.0, 18.0, -109.88);
        glVertex3f(-29.0, 23.5, -109.88);
        glVertex3f(-31.0, 23.5, -109.88);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glVertex3f(-23.0, 25.0, -109.88);
        glVertex3f(-21.5, 25.0, -109.88);
        glVertex3f(-20.0, 19.5, -109.88);
        glVertex3f(-18.5, 25.0, -109.88);
        glVertex3f(-17.0, 25.0, -109.88);
        glVertex3f(-18.5, 18.0, -109.88);
        glVertex3f(-21.0, 18.0, -109.88);
    glEnd();

    //lemari
    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.15, 0.0);
        glVertex3f(44.5, 30.0, -80.0);
        glVertex3f(44.5, -11.9, -80.0);
        glVertex3f(44.5, -11.9, -103.0);
        glVertex3f(44.5, 30.0, -103.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(32.5, 30.0, -80.0);
        glVertex3f(32.5, -11.9, -80.0);
        glVertex3f(32.5, -11.9, -103.0);
        glVertex3f(32.5, 30.0, -103.0);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(32.5, -11.9, -103);
        glVertex3f(44.5, -11.9, -103);
        glVertex3f(44.5, 30.0, -103);
        glVertex3f(32.5, 30.0, -103);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(32.5, -11.9, -80);
        glVertex3f(44.5, -11.9, -80);
        glVertex3f(44.5, 30.0, -80);
        glVertex3f(32.5, 30.0, -80);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(32.2, 30.0, -78.0);
        glVertex3f(44.8, 30.0, -78.0);
        glVertex3f(44.8, 30.0, -105.0);
        glVertex3f(32.2, 30.0, -105.0);
    glEnd();

    glBegin(GL_QUADS);
        glVertex3f(32.2, -11.9, -78.0);
        glVertex3f(44.8, -11.9, -78.0);
        glVertex3f(44.8, -11.9, -105.0);
        glVertex3f(32.2, -11.9, -105.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.5, 0.0, 0.0);
        glVertex3f(32.49, 30.0, -91.0);
        glVertex3f(32.49, -11.9, -91.0);
        glVertex3f(32.49, -11.9, -92.0);
        glVertex3f(32.49, 30.0, -92.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.8);
        glVertex3f(32.49, 10.0, -93.0);
        glVertex3f(32.49, 0.9, -93.0);
        glVertex3f(32.49, 0.9, -93.5);
        glVertex3f(32.49, 10.0, -93.5);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 0.8);
        glVertex3f(32.49, 10.0, -90.5);
        glVertex3f(32.49, 0.9, -90.5);
        glVertex3f(32.49, 0.9, -90.0);
        glVertex3f(32.49, 10.0, -90.0);
    glEnd();

    //meja
    glColor3f(0.5, 0.15, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-37.5, 5.0, -102.9);
        glVertex3f(-8.5, 5.0, -102.9);
        glVertex3f(-8.5, 5.0, -109.9);
        glVertex3f(-37.5, 5.0, -109.9);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-37.5, -2.0, -109.9);
        glVertex3f(-8.5, -2.0, -109.9);
        glVertex3f(-8.5, 5.0, -109.9);
        glVertex3f(-37.5, 5.0, -109.9);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-37.5, -2.0, -102.9);
        glVertex3f(-8.5, -2.0, -102.9);
        glVertex3f(-8.5, 5.0, -102.9);
        glVertex3f(-37.5, 5.0, -102.9);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-8.5, 5.0, -102.9);
        glVertex3f(-8.5, -2.0, -102.9);
        glVertex3f(-8.5, -2.0, -109.9);
        glVertex3f(-8.5, 5.0, -109.9);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-37.5, 5.0, -102.9);
        glVertex3f(-37.5, -2.0, -102.9);
        glVertex3f(-37.5, -2.0, -109.9);
        glVertex3f(-37.5, 5.0, -109.9);
    glEnd();


    //kaki meja

    glBegin(GL_POLYGON);
        glVertex3f(-10.5, -11.9, -101.8);
        glVertex3f(-8.5, -11.9, -101.8);
        glVertex3f(-8.5, 5.0, -101.8);
        glVertex3f(-10.5, 5.0, -101.8);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-10.5, -11.9, -109.8);
        glVertex3f(-8.5, -11.9, -109.8);
        glVertex3f(-8.5, 5.0, -109.8);
        glVertex3f(-10.5, 5.0, -109.8);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-37.5, -11.9, -101.8);
        glVertex3f(-35.5, -11.9, -101.8);
        glVertex3f(-35.5, 5.0, -101.8);
        glVertex3f(-37.5, 5.0, -101.8);
    glEnd();

    glBegin(GL_POLYGON);
        glVertex3f(-37.5, -11.9, -109.8);
        glVertex3f(-35.5, -11.9, -109.8);
        glVertex3f(-35.5, 5.0, -109.8);
        glVertex3f(-37.5, 5.0, -109.8);
    glEnd();

    //karpet
    glBegin(GL_QUADS);
        glColor3f(0.2, 0.6, 0.5);
        glVertex3f(-35.0, -11.9, 0.0);
        glVertex3f(21.0, -11.9, 0.0);
        glVertex3f(21.0, -11.9, -70.0);
        glVertex3f(-35.0, -11.9, -70.0);
    glEnd();

    glBegin(GL_QUADS);
        glColor3f(0.2, 0.2, 0.5);
        glVertex3f(-30.0, -11.89, -5.0);
        glVertex3f(16.0, -11.89, -5.0);
        glVertex3f(16.0, -11.89, -65.0);
        glVertex3f(-30.0, -11.89, -65.0);
    glEnd();

    //kursi
    glBegin(GL_QUADS);
        glColor3f(0.1, 0.7, 0.6);
        glVertex3f(27.5, -2.9, 0.0);
        glVertex3f(38.0, -2.9, 0.0);
        glVertex3f(38.0, -2.9, -10.0);
        glVertex3f(27.5, -2.9, -10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2, 0.75, 0.7);
        glVertex3f(35.9, -11.9, 0.0);
        glVertex3f(38.0, -11.9, 0.0);
        glVertex3f(38.0, -2.9, 0.0);
        glVertex3f(35.9, -2.9, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.2, 0.75, 0.7);
        glVertex3f(27.5, -11.9, 0.0);
        glVertex3f(29.6, -11.9, 0.0);
        glVertex3f(29.6, -2.9, 0.0);
        glVertex3f(27.5, -2.9, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1, 0.7, 0.65);
        glVertex3f(27.5, -2.9, -10.0);
        glVertex3f(38.0, -2.9, -10.0);
        glVertex3f(38.0, 5.9, -10.0);
        glVertex3f(27.5, 5.9, -10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1, 0.7, 0.65);
        glVertex3f(35.9, -11.9, -10.0);
        glVertex3f(38.0, -11.9, -10.0);
        glVertex3f(38.0, -2.9, -10.0);
        glVertex3f(35.9, -2.9, -10.0);
    glEnd();

    glBegin(GL_POLYGON);
        glColor3f(0.1, 0.7, 0.65);
        glVertex3f(27.5, -11.9, -10.0);
        glVertex3f(29.6, -11.9, -10.0);
        glVertex3f(29.6, -2.9, -10.0);
        glVertex3f(27.5, -2.9, -10.0);
    glEnd();

    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyb(unsigned char key, int x, int y){
    switch (key){
        case '5'://menghilangkan tembok depan
            if (is_depth){
                is_depth = 0;
                glDisable(GL_DEPTH_TEST);
            }else{
                is_depth = 1;
                glEnable(GL_DEPTH_TEST);
            }
    }
    display();
}

void ukuran(int lebar, int tinggi){
    if(tinggi == 0) tinggi = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(72.0, lebar / tinggi, 5.0, 1000.0);
    glTranslatef(0.0, -13.0, -170.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(950, 775);
    glutInitWindowPosition(250, 10);
    glutCreateWindow("Sesilia Kirana Vaniamosa - 672018316");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyb);
    glutReshapeFunc(ukuran);//atur ukuran box
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);//gerak gerak
    glutIdleFunc(idle);//gerak bebas
    glutIdleFunc(display);
    glutMainLoop();
    return 0;
}
