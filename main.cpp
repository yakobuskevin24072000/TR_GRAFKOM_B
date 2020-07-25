#include <windows.h>
#include <gl/glut.h>
#include <math.h>


void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int,int);
void mouse(int button, int state, int x, int y);
void MouseMove(int x, int y);

using namespace std;
const float BOX_SIZE = 7.0f;
float _angle = 0;
void init(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);

typedef struct{
	bool leftButton;
	bool rightButton;
	int x;
	int y;
} MouseState;
MouseState mouseState = {false, false, 0, 0 };

float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;


void init(void)
{
    glClearColor(0.0,0.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void)
{

    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
    glClear(GL_COLOR_BUFFER_BIT);

    //depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,1.0,0.0);
    glVertex3f(-30.0,10.0,-20.0);
    glVertex3f(-30.0,10.0,20.0);
    glVertex3f(30.0,10.0,20.0);
    glVertex3f(30.0,10.0,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(-30.0,10.1,-20.0);
    glVertex3f(-30.0,10.1,20.0);
    glVertex3f(-25.0,10.1,20.0);
    glVertex3f(-25.0,10.1,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(-20.0,10.1,-20.0);
    glVertex3f(-20.0,10.1,20.0);
    glVertex3f(-15.0,10.1,20.0);
    glVertex3f(-15.0,10.1,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(-10.0,10.1,-20.0);
    glVertex3f(-10.0,10.1,20.0);
    glVertex3f(-5.0,10.1,20.0);
    glVertex3f(-5.0,10.1,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(0.0,10.1,-20.0);
    glVertex3f(0.0,10.1,20.0);
    glVertex3f(5.0,10.1,20.0);
    glVertex3f(5.0,10.1,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(10.0,10.1,-20.0);
    glVertex3f(10.0,10.1,20.0);
    glVertex3f(15.0,10.1,20.0);
    glVertex3f(15.0,10.1,-20.0);
    glEnd();

   glBegin(GL_QUADS);
    glColor3f(0.0,0.7,0.0);
    glVertex3f(20.0,10.1,-20.0);
    glVertex3f(20.0,10.1,20.0);
    glVertex3f(25.0,10.1,20.0);
    glVertex3f(25.0,10.1,-20.0);
    glEnd();

    //TRIBUN
    glBegin(GL_QUADS);
   glColor3f(1.0,0.0,0.0);
    glVertex3f(-45.0,35.0,-35.0);
    glVertex3f(-30.0,15.0,-20.0);
    glVertex3f(30.0,15.0,-20.0);
    glVertex3f(45.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
   glColor3f(1.0,0.0,0.0);
    glVertex3f(-45.0,35.0,35.0);
    glVertex3f(-30.0,15.0,20.0);
    glVertex3f(30.0,15.0,20.0);
    glVertex3f(45.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,0.0,0.0);
    glVertex3f(45.0,35.0,-35.0);
    glVertex3f(45.0,35.0,35.0);
    glVertex3f(30.0,15.0,20.0);
    glVertex3f(30.0,15.0,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,0.0,0.0);
    glVertex3f(-45.0,35.0,-35.0);
    glVertex3f(-45.0,35.0,35.0);
    glVertex3f(-30.0,15.0,20.0);
    glVertex3f(-30.0,15.0,-20.0);
    glEnd();

    glBegin(GL_QUADS);
   glColor3f(0.5,0.5,0.5);
    glVertex3f(-45.0,15.0,-20.0);
    glVertex3f(-45.0,10.0,-20.0);
    glVertex3f(45.0,10.0,-20.0);
    glVertex3f(45.0,15.0,-20.0);
    glEnd();

    glBegin(GL_QUADS);
   glColor3f(0.5,0.5,0.5);
    glVertex3f(-45.0,15.0,20.0);
    glVertex3f(-45.0,10.0,20.0);
    glVertex3f(45.0,10.0,20.0);
    glVertex3f(45.0,15.0,20.0);
    glEnd();


    glBegin(GL_QUADS);
  glColor3f(0.5,0.5,0.5);
    glVertex3f(30.0,15.0,-20.0);
    glVertex3f(30.0,15.0,20.0);
    glVertex3f(30.0,10.0,20.0);
    glVertex3f(30.0,10.0,-20.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.5,0.5);
    glVertex3f(-30.0,15.0,-20.0);
    glVertex3f(-30.0,15.0,20.0);
    glVertex3f(-30.0,10.0,20.0);
    glVertex3f(-30.0,10.0,-20.0);
    glEnd();

    //TEMBOK TRIBUN

    glBegin(GL_QUADS);
   glColor3f(0.7,0.0,0.0);
    glVertex3f(-45.0,35.0,-35.0);
    glVertex3f(-45.0,10.0,-35.0);
    glVertex3f(45.0,10.0,-35.0);
    glVertex3f(45.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.7,0.0,0.0);
    glVertex3f(-45.0,35.0,35.0);
    glVertex3f(-45.0,10.0,35.0);
    glVertex3f(45.0,10.0,35.0);
    glVertex3f(45.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
   glColor3f(0.7,0.0,0.0);
    glVertex3f(45.0,35.0,-35.0);
    glVertex3f(45.0,35.0,35.0);
    glVertex3f(45.0,10.0,35.0);
    glVertex3f(45.0,10.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.7,0.0,0.0);
    glVertex3f(-45.0,35.0,-35.0);
    glVertex3f(-45.0,35.0,35.0);
    glVertex3f(-45.0,10.0,35.0);
    glVertex3f(-45.0,10.0,-35.0);
    glEnd();
    //garis tembok

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-35.0,33.0,40.0);
    glVertex3f(-35.0,28.0,40.0);
    glVertex3f(-20.0,28.0,40.0);
    glVertex3f(-20.0,33.0,40.0);
    glEnd();
     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-35.0,33.0,35.0);
    glVertex3f(-35.0,33.0,40.0);
    glVertex3f(-20.0,33.0,40.0);
    glVertex3f(-20.0,33.0,35.0);
    glEnd();
    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-35.0,28.0,35.0);
    glVertex3f(-35.0,28.0,40.0);
    glVertex3f(-20.0,28.0,40.0);
    glVertex3f(-20.0,28.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-35.0,25.0,35.1);
    glVertex3f(-35.0,20.0,35.1);
    glVertex3f(-20.0,20.0,35.1);
    glVertex3f(-20.0,25.0,35.1);
    glEnd();

   glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-35.0,18.0,35.1);
    glVertex3f(-35.0,14.0,35.1);
    glVertex3f(-20.0,14.0,35.1);
    glVertex3f(-20.0,18.0,35.1);
    glEnd();


     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(35.0,33.0,40.0);
    glVertex3f(35.0,28.0,40.0);
    glVertex3f(20.0,28.0,40.0);
    glVertex3f(20.0,33.0,40.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(35.0,33.0,35.0);
    glVertex3f(35.0,33.0,40.0);
    glVertex3f(20.0,33.0,40.0);
    glVertex3f(20.0,33.0,35.0);
    glEnd();
    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(35.0,28.0,35.0);
    glVertex3f(35.0,28.0,40.0);
    glVertex3f(20.0,28.0,40.0);
    glVertex3f(20.0,28.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(35.0,25.0,35.1);
    glVertex3f(35.0,20.0,35.1);
    glVertex3f(20.0,20.0,35.1);
    glVertex3f(20.0,25.0,35.1);
    glEnd();

   glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(35.0,18.0,35.1);
    glVertex3f(35.0,14.0,35.1);
    glVertex3f(20.0,14.0,35.1);
    glVertex3f(20.0,18.0,35.1);
    glEnd();

    //TEMBOK DEPAN TRIBUN
    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,45.0);
    glVertex3f(-45.0,10.0,45.0);
    glVertex3f(-35.0,10.0,45.0);
    glVertex3f(-35.0,35.0,45.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,45.0);
    glVertex3f(-45.0,10.0,45.0);
    glVertex3f(-45.0,10.0,35.0);
    glVertex3f(-45.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-35.0,35.0,45.0);
    glVertex3f(-35.0,10.0,45.0);
    glVertex3f(-35.0,10.0,35.0);
    glVertex3f(-35.0,35.0,35.0);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,10.0,45.0);
    glVertex3f(-35.0,10.0,45.0);
    glVertex3f(-35.0,10.0,35.0);
    glVertex3f(-45.0,10.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,45.0);
    glVertex3f(45.0,10.0,45.0);
    glVertex3f(35.0,10.0,45.0);
    glVertex3f(35.0,35.0,45.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,45.0);
    glVertex3f(45.0,10.0,45.0);
    glVertex3f(45.0,10.0,35.0);
    glVertex3f(45.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(35.0,35.0,45.0);
    glVertex3f(35.0,10.0,45.0);
    glVertex3f(35.0,10.0,35.0);
    glVertex3f(35.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,10.0,45.0);
    glVertex3f(35.0,10.0,45.0);
    glVertex3f(35.0,10.0,35.0);
    glVertex3f(45.0,10.0,35.0);
    glEnd();


    //tembok tengah

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(20.0,35.0,45.0);
    glVertex3f(20.0,10.0,45.0);
    glVertex3f(10.0,10.0,45.0);
    glVertex3f(10.0,35.0,45.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(20.0,35.0,45.0);
    glVertex3f(20.0,10.0,45.0);
    glVertex3f(20.0,10.0,35.0);
    glVertex3f(20.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(10.0,35.0,45.0);
    glVertex3f(10.0,10.0,45.0);
    glVertex3f(10.0,10.0,35.0);
    glVertex3f(10.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(20.0,10.0,45.0);
    glVertex3f(10.0,10.0,45.0);
    glVertex3f(10.0,10.0,35.0);
    glVertex3f(20.0,10.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-20.0,35.0,45.0);
    glVertex3f(-20.0,10.0,45.0);
    glVertex3f(-10.0,10.0,45.0);
    glVertex3f(-10.0,35.0,45.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-20.0,35.0,45.0);
    glVertex3f(-20.0,10.0,45.0);
    glVertex3f(-20.0,10.0,35.0);
    glVertex3f(-20.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-10.0,35.0,45.0);
    glVertex3f(-10.0,10.0,45.0);
    glVertex3f(-10.0,10.0,35.0);
    glVertex3f(-10.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-20.0,10.0,45.0);
    glVertex3f(-10.0,10.0,45.0);
    glVertex3f(-10.0,10.0,35.0);
    glVertex3f(-20.0,10.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.0,0.0,0.0);
    glVertex3f(20.0,35.0,35.1);
    glVertex3f(20.0,10.0,35.1);
    glVertex3f(-20.0,10.0,35.1);
    glVertex3f(-20.0,35.0,35.1);
    glEnd();



    //tembok belakang tribun

     glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,-45.0);
    glVertex3f(-45.0,10.0,-45.0);
    glVertex3f(-35.0,10.0,-45.0);
    glVertex3f(-35.0,35.0,-45.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,-45.0);
    glVertex3f(-45.0,10.0,-45.0);
    glVertex3f(-45.0,10.0,-35.0);
    glVertex3f(-45.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-35.0,35.0,-45.0);
    glVertex3f(-35.0,10.0,-45.0);
    glVertex3f(-35.0,10.0,-35.0);
    glVertex3f(-35.0,35.0,-35.0);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,10.0,-45.0);
    glVertex3f(-35.0,10.0,-45.0);
    glVertex3f(-35.0,10.0,-35.0);
    glVertex3f(-45.0,10.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,-45.0);
    glVertex3f(45.0,10.0,-45.0);
    glVertex3f(35.0,10.0,-45.0);
    glVertex3f(35.0,35.0,-45.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,-45.0);
    glVertex3f(45.0,10.0,-45.0);
    glVertex3f(45.0,10.0,-35.0);
    glVertex3f(45.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(35.0,35.0,-45.0);
    glVertex3f(35.0,10.0,-45.0);
    glVertex3f(35.0,10.0,-35.0);
    glVertex3f(35.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,10.0,-45.0);
    glVertex3f(35.0,10.0,-45.0);
    glVertex3f(35.0,10.0,-35.0);
    glVertex3f(45.0,10.0,-35.0);
    glEnd();

    //tembok tribun kanan


    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(55.0,35.0,-35.0);
    glVertex3f(55.0,10.0,-35.0);
    glVertex3f(55.0,10.0,35.0);
    glVertex3f(55.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,35.0);
    glVertex3f(45.0,10.0,35.0);
    glVertex3f(55.0,10.0,35.0);
    glVertex3f(55.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,-35.0);
    glVertex3f(45.0,10.0,-35.0);
    glVertex3f(55.0,10.0,-35.0);
    glVertex3f(55.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,10.0,-35.0);
    glVertex3f(45.0,10.0,35.0);
    glVertex3f(55.0,10.0,35.0);
    glVertex3f(55.0,10.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(45.0,35.0,-35.0);
    glVertex3f(45.0,35.0,35.0);
    glVertex3f(55.0,35.0,35.0);
    glVertex3f(55.0,35.0,-35.0);
    glEnd();

    //garis tembok kanan

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,35.0,35.1);
    glVertex3f(45.0,30.0,35.1);
    glVertex3f(55.0,30.0,35.1);
    glVertex3f(55.0,35.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,28.0,35.1);
    glVertex3f(45.0,23.0,35.1);
    glVertex3f(55.0,23.0,35.1);
    glVertex3f(55.0,28.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,21.0,35.1);
    glVertex3f(45.0,16.0,35.1);
    glVertex3f(55.0,16.0,35.1);
    glVertex3f(55.0,21.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,14.0,35.1);
    glVertex3f(45.0,10.0,35.1);
    glVertex3f(55.0,10.0,35.1);
    glVertex3f(55.0,14.0,35.1);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,35.0,-35.1);
    glVertex3f(45.0,30.0,-35.1);
    glVertex3f(55.0,30.0,-35.1);
    glVertex3f(55.0,35.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,28.0,-35.1);
    glVertex3f(45.0,23.0,-35.1);
    glVertex3f(55.0,23.0,-35.1);
    glVertex3f(55.0,28.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,21.0,-35.1);
    glVertex3f(45.0,16.0,-35.1);
    glVertex3f(55.0,16.0,-35.1);
    glVertex3f(55.0,21.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,14.0,-35.1);
    glVertex3f(45.0,10.0,-35.1);
    glVertex3f(55.0,10.0,-35.1);
    glVertex3f(55.0,14.0,-35.1);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(60.0,33.0,35.1);
    glVertex3f(60.0,28.0,35.1);
    glVertex3f(60.0,28.0,-35.1);
    glVertex3f(60.0,33.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(60.0,33.0,35.1);
    glVertex3f(60.0,28.0,35.1);
    glVertex3f(55.0,28.0,35.1);
    glVertex3f(55.0,33.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(60.0,33.0,-35.1);
    glVertex3f(60.0,28.0,-35.1);
    glVertex3f(55.0,28.0,-35.1);
    glVertex3f(55.0,33.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(60.0,33.0,-35.1);
    glVertex3f(60.0,33.0,35.1);
    glVertex3f(55.0,33.0,35.1);
    glVertex3f(55.0,33.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(60.0,28.0,-35.1);
    glVertex3f(60.0,28.0,35.1);
    glVertex3f(55.0,28.0,35.1);
    glVertex3f(55.0,28.0,-35.1);
    glEnd();

    //tembok kiri tribun

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-55.0,35.0,-35.0);
    glVertex3f(-55.0,10.0,-35.0);
    glVertex3f(-55.0,10.0,35.0);
    glVertex3f(-55.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,35.0);
    glVertex3f(-45.0,10.0,35.0);
    glVertex3f(-55.0,10.0,35.0);
    glVertex3f(-55.0,35.0,35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,-35.0);
    glVertex3f(-45.0,10.0,-35.0);
    glVertex3f(-55.0,10.0,-35.0);
    glVertex3f(-55.0,35.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,10.0,-35.0);
    glVertex3f(-45.0,10.0,35.0);
    glVertex3f(-55.0,10.0,35.0);
    glVertex3f(-55.0,10.0,-35.0);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(0.5,0.0,0.0);
    glVertex3f(-45.0,35.0,-35.0);
    glVertex3f(-45.0,35.0,35.0);
    glVertex3f(-55.0,35.0,35.0);
    glVertex3f(-55.0,35.0,-35.0);
    glEnd();

    //garis tembok kiri

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.0,35.1);
    glVertex3f(-45.0,30.0,35.1);
    glVertex3f(-55.0,30.0,35.1);
    glVertex3f(-55.0,35.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,28.0,35.1);
    glVertex3f(-45.0,23.0,35.1);
    glVertex3f(-55.0,23.0,35.1);
    glVertex3f(-55.0,28.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,21.0,35.1);
    glVertex3f(-45.0,16.0,35.1);
    glVertex3f(-55.0,16.0,35.1);
    glVertex3f(-55.0,21.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,14.0,35.1);
    glVertex3f(-45.0,10.0,35.1);
    glVertex3f(-55.0,10.0,35.1);
    glVertex3f(-55.0,14.0,35.1);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.0,-35.1);
    glVertex3f(-45.0,30.0,-35.1);
    glVertex3f(-55.0,30.0,-35.1);
    glVertex3f(-55.0,35.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,28.0,-35.1);
    glVertex3f(-45.0,23.0,-35.1);
    glVertex3f(-55.0,23.0,-35.1);
    glVertex3f(-55.0,28.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,21.0,-35.1);
    glVertex3f(-45.0,16.0,-35.1);
    glVertex3f(-55.0,16.0,-35.1);
    glVertex3f(-55.0,21.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,14.0,-35.1);
    glVertex3f(-45.0,10.0,-35.1);
    glVertex3f(-55.0,10.0,-35.1);
    glVertex3f(-55.0,14.0,-35.1);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-60.0,33.0,35.1);
    glVertex3f(-60.0,28.0,35.1);
    glVertex3f(-60.0,28.0,-35.1);
    glVertex3f(-60.0,33.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-60.0,33.0,35.1);
    glVertex3f(-60.0,28.0,35.1);
    glVertex3f(-55.0,28.0,35.1);
    glVertex3f(-55.0,33.0,35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-60.0,33.0,-35.1);
    glVertex3f(-60.0,28.0,-35.1);
    glVertex3f(-55.0,28.0,-35.1);
    glVertex3f(-55.0,33.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-60.0,33.0,-35.1);
    glVertex3f(-60.0,33.0,35.1);
    glVertex3f(-55.0,33.0,35.1);
    glVertex3f(-55.0,33.0,-35.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-60.0,28.0,-35.1);
    glVertex3f(-60.0,28.0,35.1);
    glVertex3f(-55.0,28.0,35.1);
    glVertex3f(-55.0,28.0,-35.1);
    glEnd();
    //garis tengah tribun kiri
    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,-25.1);
    glVertex3f(-55.1,25.0,-30.1);
    glVertex3f(-55.1,15.0,-30.1);
    glVertex3f(-55.1,15.0,-25.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,-23.1);
    glVertex3f(-55.1,25.0,-18.1);
    glVertex3f(-55.1,15.0,-18.1);
    glVertex3f(-55.1,15.0,-23.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,-16.1);
    glVertex3f(-55.1,25.0,-11.1);
    glVertex3f(-55.1,15.0,-11.1);
    glVertex3f(-55.1,15.0,-16.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,-9.1);
    glVertex3f(-55.1,25.0,-4.1);
    glVertex3f(-55.1,15.0,-4.1);
    glVertex3f(-55.1,15.0,-9.1);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,-2.1);
    glVertex3f(-55.1,25.0,3.1);
    glVertex3f(-55.1,15.0,3.1);
    glVertex3f(-55.1,15.0,-2.1);
    glEnd();


     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,5.1);
    glVertex3f(-55.1,25.0,10.1);
    glVertex3f(-55.1,15.0,10.1);
    glVertex3f(-55.1,15.0,5.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,12.1);
    glVertex3f(-55.1,25.0,17.1);
    glVertex3f(-55.1,15.0,17.1);
    glVertex3f(-55.1,15.0,12.1);
    glEnd();

      glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.1,25.0,19.1);
    glVertex3f(-55.1,25.0,24.1);
    glVertex3f(-55.1,15.0,24.1);
    glVertex3f(-55.1,15.0,19.1);
    glEnd();

    //GARIS TENGAH TRIBUN KANAN

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,-25.1);
    glVertex3f(55.1,25.0,-30.1);
    glVertex3f(55.1,15.0,-30.1);
    glVertex3f(55.1,15.0,-25.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,-23.1);
    glVertex3f(55.1,25.0,-18.1);
    glVertex3f(55.1,15.0,-18.1);
    glVertex3f(55.1,15.0,-23.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,-16.1);
    glVertex3f(55.1,25.0,-11.1);
    glVertex3f(55.1,15.0,-11.1);
    glVertex3f(55.1,15.0,-16.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,-9.1);
    glVertex3f(55.1,25.0,-4.1);
    glVertex3f(55.1,15.0,-4.1);
    glVertex3f(55.1,15.0,-9.1);
    glEnd();

     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,-2.1);
    glVertex3f(55.1,25.0,3.1);
    glVertex3f(55.1,15.0,3.1);
    glVertex3f(55.1,15.0,-2.1);
    glEnd();


     glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,5.1);
    glVertex3f(55.1,25.0,10.1);
    glVertex3f(55.1,15.0,10.1);
    glVertex3f(55.1,15.0,5.1);
    glEnd();

    glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,12.1);
    glVertex3f(55.1,25.0,17.1);
    glVertex3f(55.1,15.0,17.1);
    glVertex3f(55.1,15.0,12.1);
    glEnd();

      glBegin(GL_QUADS);
  glColor3f(1.0,1.0,1.0);
    glVertex3f(55.1,25.0,19.1);
    glVertex3f(55.1,25.0,24.1);
    glVertex3f(55.1,15.0,24.1);
    glVertex3f(55.1,15.0,19.1);
    glEnd();

    //JALAN KANAN
     glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(33.9,17.0,-19.0);
    glVertex3f(33.9,17.0,-16.0);
    glVertex3f(29.9,10.0,-16.0);
    glVertex3f(29.9,10.0,-19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(33.9,17.0,-9.0);
    glVertex3f(33.9,17.0,-6.0);
    glVertex3f(29.9,10.0,-6.0);
    glVertex3f(29.9,10.0,-9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(33.9,17.0,6.0);
    glVertex3f(33.9,17.0,9.0);
    glVertex3f(29.9,10.0,9.0);
    glVertex3f(29.9,10.0,6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(33.9,17.0,16.0);
    glVertex3f(33.9,17.0,19.0);
    glVertex3f(29.9,10.0,19.0);
    glVertex3f(29.9,10.0,16.0);
    glEnd();

    //PINTU KIRI

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-34.9,19.0,-20.0);
    glVertex3f(-34.9,19.0,-15.0);
    glVertex3f(-33.9,17.0,-15.0);
    glVertex3f(-33.9,17.0,-20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-34.9,19.0,-10.0);
    glVertex3f(-34.9,19.0,-5.0);
    glVertex3f(-33.9,17.0,-5.0);
    glVertex3f(-33.9,17.0,-10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-34.9,19.0,5.0);
    glVertex3f(-34.9,19.0,10.0);
    glVertex3f(-33.9,17.0,10.0);
    glVertex3f(-33.9,17.0,5.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-34.9,19.0,15.0);
    glVertex3f(-34.9,19.0,20.0);
    glVertex3f(-33.9,17.0,20.0);
    glVertex3f(-33.9,17.0,15.0);
    glEnd();

    //JALAN KIRI

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-33.9,17.0,-19.0);
    glVertex3f(-33.9,17.0,-16.0);
    glVertex3f(-29.9,10.0,-16.0);
    glVertex3f(-29.9,10.0,-19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-33.9,17.0,-9.0);
    glVertex3f(-33.9,17.0,-6.0);
    glVertex3f(-29.9,10.0,-6.0);
    glVertex3f(-29.9,10.0,-9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-33.9,17.0,6.0);
    glVertex3f(-33.9,17.0,9.0);
    glVertex3f(-29.9,10.0,9.0);
    glVertex3f(-29.9,10.0,6.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-33.9,17.0,16.0);
    glVertex3f(-33.9,17.0,19.0);
    glVertex3f(-29.9,10.0,19.0);
    glVertex3f(-29.9,10.0,16.0);
    glEnd();

    //gawang kiri

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-25.0,17.1,-5.0);
    glVertex3f(-25.0,17.1,5.0);
    glVertex3f(-25.0,10.1,5.0);
    glVertex3f(-25.0,10.1,-5.0);
    glEnd();
    //gawang kanan
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(25.0,17.1,-5.0);
    glVertex3f(25.0,17.1,5.0);
    glVertex3f(25.0,10.1,5.0);
    glVertex3f(25.0,10.1,-5.0);
    glEnd();

    //garis aut
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(25.0,10.1,-18.0);
    glVertex3f(25.0,10.1,18.0);
    glVertex3f(-25.0,10.1,18.0);
    glVertex3f(-25.0,10.1,-18.0);
    glEnd();

    //kotak pinalty kiri
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-20.0,10.2,-8.0);
    glVertex3f(-20.0,10.2,8.0);
    glVertex3f(-25.0,10.2,8.0);
    glVertex3f(-25.0,10.2,-8.0);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-13.0,10.2,-15.0);
    glVertex3f(-13.0,10.2,15.0);
    glVertex3f(-25.0,10.2,15.0);
    glVertex3f(-25.0,10.2,-15.0);
    glEnd();

    //kotak pinalty kanan
    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(20.0,10.2,-8.0);
    glVertex3f(20.0,10.2,8.0);
    glVertex3f(25.0,10.2,8.0);
    glVertex3f(25.0,10.2,-8.0);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(13.0,10.2,-15.0);
    glVertex3f(13.0,10.2,15.0);
    glVertex3f(25.0,10.2,15.0);
    glVertex3f(25.0,10.2,-15.0);
    glEnd();

    //ATAP

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.1,45.1);
    glVertex3f(-45.0,50.0,45.1);
    glVertex3f(45.0,50.0,45.1);
    glVertex3f(45.0,35.1,45.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.1,45.1);
    glVertex3f(-45.0,50.0,45.1);
    glVertex3f(-45.0,50.0,35.1);
    glVertex3f(-45.0,35.1,35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,35.1,45.1);
    glVertex3f(45.0,50.0,45.1);
    glVertex3f(45.0,50.0,35.1);
    glVertex3f(45.0,35.1,35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,50.1,20.1);
    glVertex3f(-45.0,50.1,45.1);
    glVertex3f(45.0,50.1,45.1);
    glVertex3f(45.0,50.1,20.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.1,35.1);
    glVertex3f(-45.0,35.1,45.1);
    glVertex3f(45.0,35.1,45.1);
    glVertex3f(45.0,35.1,35.1);
    glEnd();

    //ATAPBELAKANG
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.1,-45.1);
    glVertex3f(-45.0,50.0,-45.1);
    glVertex3f(45.0,50.0,-45.1);
    glVertex3f(45.0,35.1,-45.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.1,-45.1);
    glVertex3f(-45.0,50.0,-45.1);
    glVertex3f(-45.0,50.0,-35.1);
    glVertex3f(-45.0,35.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(45.0,35.1,-45.1);
    glVertex3f(45.0,50.0,-45.1);
    glVertex3f(45.0,50.0,-35.1);
    glVertex3f(45.0,35.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,50.1,-20.1);
    glVertex3f(-45.0,50.1,-45.1);
    glVertex3f(45.0,50.1,-45.1);
    glVertex3f(45.0,50.1,-20.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-45.0,35.1,-35.1);
    glVertex3f(-45.0,35.1,-45.1);
    glVertex3f(45.0,35.1,-45.1);
    glVertex3f(45.0,35.1,-35.1);
    glEnd();

    //ATAP SAMPING


    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.0,35.1,-35.1);
    glVertex3f(-55.0,45.0,-35.1);
    glVertex3f(-55.0,45.0,35.1);
    glVertex3f(-55.0,35.1,35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.0,35.1,-35.1);
    glVertex3f(-55.0,35.0,35.1);
    glVertex3f(-45.0,35.0,35.1);
    glVertex3f(-45.0,35.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.0,45.1,-35.1);
    glVertex3f(-55.0,45.0,35.1);
    glVertex3f(-35.0,45.0,35.1);
    glVertex3f(-35.0,45.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.0,45.1,-35.1);
    glVertex3f(-55.0,35.1,-35.1);
    glVertex3f(-45.0,35.1,-35.1);
    glVertex3f(-45.0,45.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-55.0,45.1,35.1);
    glVertex3f(-55.0,35.1,35.1);
    glVertex3f(-45.0,35.1,35.1);
    glVertex3f(-45.0,45.1,35.1);
    glEnd();

    //atap kanan

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(55.0,35.1,-35.1);
    glVertex3f(55.0,45.0,-35.1);
    glVertex3f(55.0,45.0,35.1);
    glVertex3f(55.0,35.1,35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(55.0,35.1,-35.1);
    glVertex3f(55.0,35.0,35.1);
    glVertex3f(45.0,35.0,35.1);
    glVertex3f(45.0,35.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(55.0,45.1,-35.1);
    glVertex3f(55.0,45.0,35.1);
    glVertex3f(35.0,45.0,35.1);
    glVertex3f(35.0,45.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(55.0,45.1,-35.1);
    glVertex3f(55.0,35.1,-35.1);
    glVertex3f(45.0,35.1,-35.1);
    glVertex3f(45.0,45.1,-35.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(55.0,45.1,35.1);
    glVertex3f(55.0,35.1,35.1);
    glVertex3f(45.0,35.1,35.1);
    glVertex3f(45.0,45.1,35.1);
    glEnd();







    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-50.0,45.0,-35.0);
    glVertex3f(-50.0,55.0,-20.0);
    glVertex3f(-50.0,55.0,20.0);
    glVertex3f(-50.0,45.0,35.0);
    glEnd();


    //TIANG DEEPAN

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-45.0,50.0,35.0);
    glVertex3f(-30.0,60.0,35.0);
    glVertex3f(30.0,60.0,35.0);
    glVertex3f(45.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-45.0,50.0,40.0);
    glVertex3f(-30.0,60.0,40.0);
    glVertex3f(30.0,60.0,40.0);
    glVertex3f(45.0,50.0,40.0);
    glEnd();

     glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-30.0,60.0,35.0);
    glVertex3f(-30.0,50.0,35.0);
    glVertex3f(-25.0,60.0,35.0);
    glVertex3f(-25.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-25.0,60.0,35.0);
    glVertex3f(-25.0,50.0,35.0);
    glVertex3f(-20.0,60.0,35.0);
    glVertex3f(-20.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-20.0,60.0,35.0);
    glVertex3f(-20.0,50.0,35.0);
    glVertex3f(-15.0,60.0,35.0);
    glVertex3f(-15.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-15.0,60.0,35.0);
    glVertex3f(-15.0,50.0,35.0);
    glVertex3f(-10.0,60.0,35.0);
    glVertex3f(-10.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-10.0,60.0,35.0);
    glVertex3f(-10.0,50.0,35.0);
    glVertex3f(-5.0,60.0,35.0);
    glVertex3f(-5.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-5.0,60.0,35.0);
    glVertex3f(-5.0,50.0,35.0);
    glVertex3f(0.0,60.0,35.0);
    glVertex3f(0.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,60.0,35.0);
    glVertex3f(0.0,50.0,35.0);
    glVertex3f(5.0,60.0,35.0);
    glVertex3f(5.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(5.0,60.0,35.0);
    glVertex3f(5.0,50.0,35.0);
    glVertex3f(10.0,60.0,35.0);
    glVertex3f(10.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(10.0,60.0,35.0);
    glVertex3f(10.0,50.0,35.0);
    glVertex3f(15.0,60.0,35.0);
    glVertex3f(15.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(15.0,60.0,35.0);
    glVertex3f(15.0,50.0,35.0);
    glVertex3f(20.0,60.0,35.0);
    glVertex3f(20.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(20.0,60.0,35.0);
    glVertex3f(20.0,50.0,35.0);
    glVertex3f(25.0,60.0,35.0);
    glVertex3f(25.0,50.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(25.0,60.0,35.0);
    glVertex3f(25.0,50.0,35.0);
    glVertex3f(30.0,60.0,35.0);
    glVertex3f(30.0,50.0,35.0);
    glEnd();

    //
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-30.0,60.0,40.0);
    glVertex3f(-30.0,50.0,40.0);
    glVertex3f(-25.0,60.0,40.0);
    glVertex3f(-25.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-25.0,60.0,40.0);
    glVertex3f(-25.0,50.0,40.0);
    glVertex3f(-20.0,60.0,40.0);
    glVertex3f(-20.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-20.0,60.0,40.0);
    glVertex3f(-20.0,50.0,40.0);
    glVertex3f(-15.0,60.0,40.0);
    glVertex3f(-15.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-15.0,60.0,40.0);
    glVertex3f(-15.0,50.0,40.0);
    glVertex3f(-10.0,60.0,40.0);
    glVertex3f(-10.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-10.0,60.0,40.0);
    glVertex3f(-10.0,50.0,40.0);
    glVertex3f(-5.0,60.0,40.0);
    glVertex3f(-5.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-5.0,60.0,40.0);
    glVertex3f(-5.0,50.0,40.0);
    glVertex3f(0.0,60.0,40.0);
    glVertex3f(0.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,60.0,40.0);
    glVertex3f(0.0,50.0,40.0);
    glVertex3f(5.0,60.0,40.0);
    glVertex3f(5.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(5.0,60.0,40.0);
    glVertex3f(5.0,50.0,40.0);
    glVertex3f(10.0,60.0,40.0);
    glVertex3f(10.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(10.0,60.0,40.0);
    glVertex3f(10.0,50.0,40.0);
    glVertex3f(15.0,60.0,40.0);
    glVertex3f(15.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(15.0,60.0,40.0);
    glVertex3f(15.0,50.0,40.0);
    glVertex3f(20.0,60.0,40.0);
    glVertex3f(20.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(20.0,60.0,40.0);
    glVertex3f(20.0,50.0,40.0);
    glVertex3f(25.0,60.0,40.0);
    glVertex3f(25.0,50.0,40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(25.0,60.0,40.0);
    glVertex3f(25.0,50.0,40.0);
    glVertex3f(30.0,60.0,40.0);
    glVertex3f(30.0,50.0,40.0);
    glEnd();

    //TIANG belakang
     glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-45.0,50.0,-35.0);
    glVertex3f(-30.0,60.0,-35.0);
    glVertex3f(30.0,60.0,-35.0);
    glVertex3f(45.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-45.0,50.0,-40.0);
    glVertex3f(-30.0,60.0,-40.0);
    glVertex3f(30.0,60.0,-40.0);
    glVertex3f(45.0,50.0,-40.0);
    glEnd();

     glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-30.0,60.0,-35.0);
    glVertex3f(-30.0,50.0,-35.0);
    glVertex3f(-25.0,60.0,-35.0);
    glVertex3f(-25.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-25.0,60.0,-35.0);
    glVertex3f(-25.0,50.0,-35.0);
    glVertex3f(-20.0,60.0,-35.0);
    glVertex3f(-20.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-20.0,60.0,-35.0);
    glVertex3f(-20.0,50.0,-35.0);
    glVertex3f(-15.0,60.0,-35.0);
    glVertex3f(-15.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-15.0,60.0,-35.0);
    glVertex3f(-15.0,50.0,-35.0);
    glVertex3f(-10.0,60.0,-35.0);
    glVertex3f(-10.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-10.0,60.0,-35.0);
    glVertex3f(-10.0,50.0,-35.0);
    glVertex3f(-5.0,60.0,-35.0);
    glVertex3f(-5.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-5.0,60.0,-35.0);
    glVertex3f(-5.0,50.0,-35.0);
    glVertex3f(0.0,60.0,-35.0);
    glVertex3f(0.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,60.0,-35.0);
    glVertex3f(0.0,50.0,-35.0);
    glVertex3f(5.0,60.0,-35.0);
    glVertex3f(5.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(5.0,60.0,-35.0);
    glVertex3f(5.0,50.0,-35.0);
    glVertex3f(10.0,60.0,-35.0);
    glVertex3f(10.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(10.0,60.0,-35.0);
    glVertex3f(10.0,50.0,-35.0);
    glVertex3f(15.0,60.0,-35.0);
    glVertex3f(15.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(15.0,60.0,-35.0);
    glVertex3f(15.0,50.0,-35.0);
    glVertex3f(20.0,60.0,-35.0);
    glVertex3f(20.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(20.0,60.0,-35.0);
    glVertex3f(20.0,50.0,-35.0);
    glVertex3f(25.0,60.0,-35.0);
    glVertex3f(25.0,50.0,-35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(25.0,60.0,-35.0);
    glVertex3f(25.0,50.0,-35.0);
    glVertex3f(30.0,60.0,-35.0);
    glVertex3f(30.0,50.0,-35.0);
    glEnd();

    //
    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-30.0,60.0,-40.0);
    glVertex3f(-30.0,50.0,-40.0);
    glVertex3f(-25.0,60.0,-40.0);
    glVertex3f(-25.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-25.0,60.0,-40.0);
    glVertex3f(-25.0,50.0,-40.0);
    glVertex3f(-20.0,60.0,-40.0);
    glVertex3f(-20.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-20.0,60.0,-40.0);
    glVertex3f(-20.0,50.0,-40.0);
    glVertex3f(-15.0,60.0,-40.0);
    glVertex3f(-15.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-15.0,60.0,-40.0);
    glVertex3f(-15.0,50.0,-40.0);
    glVertex3f(-10.0,60.0,-40.0);
    glVertex3f(-10.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-10.0,60.0,-40.0);
    glVertex3f(-10.0,50.0,-40.0);
    glVertex3f(-5.0,60.0,-40.0);
    glVertex3f(-5.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-5.0,60.0,-40.0);
    glVertex3f(-5.0,50.0,-40.0);
    glVertex3f(0.0,60.0,-40.0);
    glVertex3f(0.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(0.0,60.0,-40.0);
    glVertex3f(0.0,50.0,-40.0);
    glVertex3f(5.0,60.0,-40.0);
    glVertex3f(5.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(5.0,60.0,-40.0);
    glVertex3f(5.0,50.0,-40.0);
    glVertex3f(10.0,60.0,-40.0);
    glVertex3f(10.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(10.0,60.0,-40.0);
    glVertex3f(10.0,50.0,-40.0);
    glVertex3f(15.0,60.0,-40.0);
    glVertex3f(15.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(15.0,60.0,-40.0);
    glVertex3f(15.0,50.0,-40.0);
    glVertex3f(20.0,60.0,-40.0);
    glVertex3f(20.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(20.0,60.0,-40.0);
    glVertex3f(20.0,50.0,-40.0);
    glVertex3f(25.0,60.0,-40.0);
    glVertex3f(25.0,50.0,-40.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(25.0,60.0,-40.0);
    glVertex3f(25.0,50.0,-40.0);
    glVertex3f(30.0,60.0,-40.0);
    glVertex3f(30.0,50.0,-40.0);
    glEnd();

    //TIANG KANAN

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,45.0,-35.0);
    glVertex3f(52.0,55.0,-20.0);
    glVertex3f(52.0,55.0,20.0);
    glVertex3f(52.0,45.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,45.0,-35.0);
    glVertex3f(47.0,55.0,-20.0);
    glVertex3f(47.0,55.0,20.0);
    glVertex3f(47.0,45.0,35.0);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,-15.0);
    glVertex3f(52.0,45.0,-15.0);
    glVertex3f(52.0,55.0,-20.0);
    glVertex3f(52.0,45.0,-20.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,-10.0);
    glVertex3f(52.0,45.0,-10.0);
    glVertex3f(52.0,55.0,-15.0);
    glVertex3f(52.0,45.0,-15.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,-5.0);
    glVertex3f(52.0,45.0,-5.0);
    glVertex3f(52.0,55.0,-10.0);
    glVertex3f(52.0,45.0,-10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,0.0);
    glVertex3f(52.0,45.0,0.0);
    glVertex3f(52.0,55.0,-5.0);
    glVertex3f(52.0,45.0,-5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,5.0);
    glVertex3f(52.0,45.0,5.0);
    glVertex3f(52.0,55.0,0.0);
    glVertex3f(52.0,45.0,0.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,10.0);
    glVertex3f(52.0,45.0,10.0);
    glVertex3f(52.0,55.0,5.0);
    glVertex3f(52.0,45.0,5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,15.0);
    glVertex3f(52.0,45.0,15.0);
    glVertex3f(52.0,55.0,10.0);
    glVertex3f(52.0,45.0,10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(52.0,55.0,20.0);
    glVertex3f(52.0,45.0,20.0);
    glVertex3f(52.0,55.0,15.0);
    glVertex3f(52.0,45.0,15.0);
    glEnd();

    //

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,-15.0);
    glVertex3f(47.0,45.0,-15.0);
    glVertex3f(47.0,55.0,-20.0);
    glVertex3f(47.0,45.0,-20.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,-10.0);
    glVertex3f(47.0,45.0,-10.0);
    glVertex3f(47.0,55.0,-15.0);
    glVertex3f(47.0,45.0,-15.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,-5.0);
    glVertex3f(47.0,45.0,-5.0);
    glVertex3f(47.0,55.0,-10.0);
    glVertex3f(47.0,45.0,-10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,0.0);
    glVertex3f(47.0,45.0,0.0);
    glVertex3f(47.0,55.0,-5.0);
    glVertex3f(47.0,45.0,-5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,5.0);
    glVertex3f(47.0,45.0,5.0);
    glVertex3f(47.0,55.0,0.0);
    glVertex3f(47.0,45.0,0.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,10.0);
    glVertex3f(47.0,45.0,10.0);
    glVertex3f(47.0,55.0,5.0);
    glVertex3f(47.0,45.0,5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,15.0);
    glVertex3f(47.0,45.0,15.0);
    glVertex3f(47.0,55.0,10.0);
    glVertex3f(47.0,45.0,10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(47.0,55.0,20.0);
    glVertex3f(47.0,45.0,20.0);
    glVertex3f(47.0,55.0,15.0);
    glVertex3f(47.0,45.0,15.0);
    glEnd();

    //TIANG KIRI

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,45.0,-35.0);
    glVertex3f(-52.0,55.0,-20.0);
    glVertex3f(-52.0,55.0,20.0);
    glVertex3f(-52.0,45.0,35.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,45.0,-35.0);
    glVertex3f(-47.0,55.0,-20.0);
    glVertex3f(-47.0,55.0,20.0);
    glVertex3f(-47.0,45.0,35.0);
    glEnd();


    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,-15.0);
    glVertex3f(-52.0,45.0,-15.0);
    glVertex3f(-52.0,55.0,-20.0);
    glVertex3f(-52.0,45.0,-20.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,-10.0);
    glVertex3f(-52.0,45.0,-10.0);
    glVertex3f(-52.0,55.0,-15.0);
    glVertex3f(-52.0,45.0,-15.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,-5.0);
    glVertex3f(-52.0,45.0,-5.0);
    glVertex3f(-52.0,55.0,-10.0);
    glVertex3f(-52.0,45.0,-10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,0.0);
    glVertex3f(-52.0,45.0,0.0);
    glVertex3f(-52.0,55.0,-5.0);
    glVertex3f(-52.0,45.0,-5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,5.0);
    glVertex3f(-52.0,45.0,5.0);
    glVertex3f(-52.0,55.0,0.0);
    glVertex3f(-52.0,45.0,0.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,10.0);
    glVertex3f(-52.0,45.0,10.0);
    glVertex3f(-52.0,55.0,5.0);
    glVertex3f(-52.0,45.0,5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,15.0);
    glVertex3f(-52.0,45.0,15.0);
    glVertex3f(-52.0,55.0,10.0);
    glVertex3f(-52.0,45.0,10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-52.0,55.0,20.0);
    glVertex3f(-52.0,45.0,20.0);
    glVertex3f(-52.0,55.0,15.0);
    glVertex3f(-52.0,45.0,15.0);
    glEnd();

    //

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,-15.0);
    glVertex3f(-47.0,45.0,-15.0);
    glVertex3f(-47.0,55.0,-20.0);
    glVertex3f(-47.0,45.0,-20.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,-10.0);
    glVertex3f(-47.0,45.0,-10.0);
    glVertex3f(-47.0,55.0,-15.0);
    glVertex3f(-47.0,45.0,-15.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,-5.0);
    glVertex3f(-47.0,45.0,-5.0);
    glVertex3f(-47.0,55.0,-10.0);
    glVertex3f(-47.0,45.0,-10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,0.0);
    glVertex3f(-47.0,45.0,0.0);
    glVertex3f(-47.0,55.0,-5.0);
    glVertex3f(-47.0,45.0,-5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,5.0);
    glVertex3f(-47.0,45.0,5.0);
    glVertex3f(-47.0,55.0,0.0);
    glVertex3f(-47.0,45.0,0.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,10.0);
    glVertex3f(-47.0,45.0,10.0);
    glVertex3f(-47.0,55.0,5.0);
    glVertex3f(-47.0,45.0,5.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,15.0);
    glVertex3f(-47.0,45.0,15.0);
    glVertex3f(-47.0,55.0,10.0);
    glVertex3f(-47.0,45.0,10.0);
    glEnd();

    glLineWidth(5.0f);
    glBegin(GL_LINE_LOOP);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-47.0,55.0,20.0);
    glVertex3f(-47.0,45.0,20.0);
    glVertex3f(-47.0,55.0,15.0);
    glVertex3f(-47.0,45.0,15.0);
    glEnd();

    glPushMatrix();
    glPopMatrix();

    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 'W':
        glTranslatef(0, 0, 3);
        break;
    case 's':
    case 'S':
        glTranslatef(0, 0, -3);
        break;
    case 'd':
    case 'D':
        glTranslatef(3, 0, 0);
        break;
    case 'a':
    case 'A':
        glTranslatef(-3, 0, 0);
        break;
    case 'q':
    case 'Q':
        glTranslatef(0, 3, 0);
        break;
    case 'e':
    case 'E':
        glTranslatef(0, -3, 0);
        break;
    case '=':
    case '+':
        glScalef(1.1, 1.1, 1.1);
        break;
    case '-':
    case '_':
        glScalef(0.9, 0.9, 0.9);
        break;
    case '2':
        glRotatef(-2, 1, 0, 0);
        break;
    case '8':
        glRotatef(2, 1, 0, 0);
        break;
    case '6':
        glRotatef(2, 0, 1, 0);
        break;
    case '4':
        glRotatef(-2, 0, 1, 0);
        break;
    case '9':
        glRotatef(2, 0, 0, 1);
        break;
    case '7':
        glRotatef(-2, 0, 0, 1);
        break;
    case '0':
    case 27:
        exit(0);
        break;
    case '5':
        if (is_depth) {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }glutPostRedisplay();
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void Mouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {

		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}

	else{
        mouseDown = false;
	}
	tampil();
}

void MouseMove(int x, int y){
	if (mouseDown) {
		yrot= x - xdiff;
		_angle = y + ydiff;
		glLoadIdentity();
		gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		glRotatef(-_angle, 30.0f, 0.0f, 20.0f);
		glRotatef(yrot, 00.0f, 10.0f, 20.0f);
	}
	glutPostRedisplay();
}


void ukuran(int lebar, int tinggi)
{
    if (tinggi==0) tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main (int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR_ASDOS_GRAFKOM_B");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(Mouse);
	glutMotionFunc(MouseMove);
	glutReshapeFunc(ukuran);
	glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
