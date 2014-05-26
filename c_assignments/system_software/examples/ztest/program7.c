//Apple gcc program1.c -framework opengl -framework glut
//Linux gcc program1.c -lglut
//Windows cl program1.c
//PROGRAM ONE
#define APPLE
//#define LINUX
//#define WINDOWS
#ifdef APPLE
#include <glut/glut.h> // Header File For The GLUT Library
#include <unistd.h>
#endif
#ifdef LINUX
#include <GL/glut.h> // Header File For The GLUT Library
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#include <gl/gl.h>
#include "glut.h"
#define usleep(x) Sleep((x)/16000+1)
#endif
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "rectangle.h"

#define kWindowWidth	400 // Constants
#define kWindowHeight	300
#define N 10
typedef struct {
tRectangle r;
double dx,dy;
} MovingRect;
MovingRect mr[N];
#define drand() ((double)rand()/(double)RAND_MAX)
GLvoid InitGL(GLvoid) {
int i;
glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
// This Will Clear The Background Color To Black
glClearDepth(1.0);
// Enables Clearing Of The Depth Buffer
glDepthFunc(GL_LESS);
// The Type Of Depth Test To Do
glEnable(GL_DEPTH_TEST);
// Enables Depth Testing
glShadeModel(GL_SMOOTH);
// Enables Smooth Color Shading
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
// Reset The Projection Matrix
gluPerspective(45.0f,
 (GLfloat)kWindowWidth/(GLfloat)kWindowHeight,0.1f,100.0f);
// Calculate The Aspect Ratio Of The Window
glMatrixMode(GL_MODELVIEW);
for (i=0; i<N; i++) {
mr[i].r = rect_open();
rect_init(mr[i].r, RECT5whxyz
,drand()/5.0+0.1,drand()/5.0+0.1,
drand(),drand(),drand());
rect_setcolor(mr[i].r, drand(), drand(), drand());
mr[i].dx=drand()/10;
mr[i].dy=mr[i].dx;
} /*for*/
}

GLvoid DrawGLScene(GLvoid) {    
int i;
double r,g,b,w,h,x,y,z;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Clear The Screen And The Depth Buffer
glLoadIdentity();

glTranslated(0.0,0.0,-6.0);
  // draw a pyramid (in smooth coloring mode)
glBegin(GL_QUADS);		// start drawing rectangles
for (i=0; i<N; i++) {
  rect_color(mr[i].r, &r, &g, &b);
  rect_position(mr[i].r, &x, &y, &z);
  rect_size(mr[i].r, &w, &h);
  glColor3d(r,g,b);
  glVertex3d(x,y,z);
  glVertex3d(x, y+h, z);
  glVertex3d(x+w, y+h, z);
  glVertex3d(x+w, y, z);
}
glEnd();
glutSwapBuffers();
}

void idle(void) { /*new*/
int i;
double x,y,z;
for (i=0; i<N; i++) {
rect_position(mr[i].r, &x, &y, &z);
x += mr[i].dx;
y += mr[i].dy;
if (fabs(y)>2.0) {
  if (fabs(x-y)<0.001) {
    mr[i].dx=-mr[i].dx;
  }
  mr[i].dy=-mr[i].dy;
} /*if*/
if (fabs(x)>2.0) {
  if (fabs(x-y)<0.001) {
    mr[i].dy=-mr[i].dy;
  }
  mr[i].dx=-mr[i].dx;
} /*if*/
rect_setposition(mr[i].r, x, y, z);
} /*for*/
glutPostRedisplay();
usleep(100000);
}

GLvoid ReSizeGLScene(int Width, int Height) {
glViewport (0, 0, (GLsizei) Width, (GLsizei) Height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0, (GLfloat) Width / (GLfloat) Height, 0.1, 100.0);   
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

int main(int argc, char *argv[]) {	
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_ALPHA);
glutInitWindowSize (kWindowWidth, kWindowHeight); 
glutInitWindowPosition (100, 100);
glutCreateWindow ("3D Rotation");	
InitGL(); 
glutDisplayFunc(DrawGLScene); 
glutReshapeFunc(ReSizeGLScene); 
/*new*/glutIdleFunc(idle);
glutMainLoop();
return 0;
}

