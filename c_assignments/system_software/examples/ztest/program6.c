//Apple gcc program1.c -framework opengl -framework glut
//Linux gcc program1.c -lglut
//Windows cl program1.c
//PROGRAM ONE
//#define APPLE
#define LINUX
//#define WINDOWS
#ifdef APPLE
#include <glut/glut.h> // Header File For The GLUT Library
#endif
#ifdef LINUX
#include <GL/glut.h> // Header File For The GLUT Library
#endif
#ifdef WINDOWS
#include <windows.h>
#include <gl/gl.h>
#include "glut.h"
#endif
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

#define kWindowWidth	400 // Constants
#define kWindowHeight	300
#define N 10
typedef struct {
GLdouble red,green,blue;
GLdouble x,y,z;
GLdouble width,height;
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
mr[i].x=drand();
mr[i].y=drand();
mr[i].width=drand()/5.0+0.1;
mr[i].height=drand()/5.0+0.1;
mr[i].red=drand();
mr[i].green=drand();
mr[i].blue=drand();
mr[i].dx=drand()/10;
mr[i].dy=mr[i].dx;
}
}

GLvoid DrawGLScene(GLvoid) {    
int i;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Clear The Screen And The Depth Buffer
glLoadIdentity();

glTranslated(0.0,0.0,-6.0);
  // draw a pyramid (in smooth coloring mode)
glBegin(GL_QUADS);		// start drawing rectangles
for (i=0; i<N; i++) {
  glColor3d(mr[i].red,mr[i].green,mr[i].blue);
  glVertex3d(mr[i].x, mr[i].y, mr[i].z);
  glVertex3d(mr[i].x, mr[i].y+mr[i].height, mr[i].z);
  glVertex3d(mr[i].x+mr[i].width, mr[i].y+mr[i].height, mr[i].z);
  glVertex3d(mr[i].x+mr[i].width, mr[i].y, mr[i].z);
}
glEnd();
glutSwapBuffers();
}

void idle() { /*new*/
int i;
for (i=0; i<N; i++) {
mr[i].x += mr[i].dx;
mr[i].y += mr[i].dy;
if (fabs(mr[i].y)>2.0) {
  if (fabs(mr[i].x-mr[i].y)<0.001) {
    mr[i].dx=-mr[i].dx;
  }
  mr[i].dy=-mr[i].dy;
}
if (fabs(mr[i].x)>2.0) {
  if (fabs(mr[i].x-mr[i].y)<0.001) {
    mr[i].dy=-mr[i].dy;
  }
  mr[i].dx=-mr[i].dx;
}
}
glutPostRedisplay();
usleep(10000);
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

