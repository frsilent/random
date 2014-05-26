//Apple gcc program1.c -framework opengl -framework glut
//Linux gcc program1.c -lglut
//Windows cl program1.c
//PROGRAM ONE
#define APPLE
//#define LINUX
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
#include <stdio.h>

#define kWindowWidth	400 // Constants
#define kWindowHeight	300

#define  size  512 /* use a power of two that fits on screen. */
#define scale (size/8)
#define numOfLevels  6 /* set to number smaller than the power in the last line; if 512; use 8 or less here */
int dist;

/* Each of the mutually recursive procedures draws one side of the basic square figure in the orientation given by its name.
   At the lowest level, this is an angled part, a straight part, and then an angled part, concluding with a "larger" copy of itself at a lower level to glue to the next piece. */

void Right (int level);
void Left (int level);
void Bottom (int level);

int lastX, lastY;
void Line(int x, int y) {
if ((lastX!=0)||(lastY!=0)) {
glBegin(GL_LINES);
glVertex3d(((double)lastX)/scale, ((double)lastY)/scale, 0.0);
glVertex3d(((double)x)/scale, ((double)y)/scale, 0);
glEnd();
}
//printf("%d %d %d %d\n",lastX,lastY,x,y);
lastX=x; lastY=y;
}

void Top (int level) {
  if (level > 0) {
      Top (level - 1);   Line (dist, -dist);
      Right (level - 1); Line (2 * dist, 0);
      Left (level - 1);  Line (dist, dist);
      Top (level - 1);
  } /*if*/
}

void Right (int level) {
  if (level > 0) {
      Right (level - 1);   Line (-dist, -dist);
      Bottom  (level - 1); Line (0, -2 * dist);
      Top (level - 1);     Line (dist, -dist);
      Right (level - 1);
   } /*if*/
}

void Bottom  (int level) {
  if (level > 0) {
      Bottom  (level - 1); Line (-dist, dist);
      Left (level - 1);    Line (-2 * dist, 0);
      Right (level - 1);   Line (-dist, -dist);
      Bottom  (level - 1);
   } /*if*/
}

void Left (int level) {
  if (level > 0) {
      Left (level - 1);    Line (dist, dist);
      Top (level - 1);     Line (0, 2 * dist);
      Bottom  (level - 1); Line (-dist, dist);
      Left (level - 1);
   } /*if*/
}

void sierpinski() {
  int level;
  int startX, startY;
  dist = size / 4; /* initial segment distance */
  startX =  0;
  startY =  dist;
  level = 0; 

 /* The following loop draws the level one figure and then overlays it with the level two figure, and so on until the number of specified levels have all been drawn. */

  do {
    level++;        /* begin at one and work up to max set. */
    startX -= dist; /* set up new corner to start */
    dist = dist / 2;   /* and basic distance for next level */
    startY += dist;
    /* We end up d units left and d/2 units up from last start for next one.*/ 
    lastX=0; lastY=0;
    /* In the main program the figure is drawn with the four "sides" in succession, each followed by a line segment to glue to the next piece. */
    Top (level);     Line (dist, -dist); 
    Right (level);   Line (-dist, -dist);
    Bottom  (level); Line (-dist, dist); 
    Left (level);    Line (dist, dist);
  } while (level != numOfLevels);
}

GLvoid InitGL(GLvoid) {
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
}

GLvoid DrawGLScene(GLvoid) {    
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Clear The Screen And The Depth Buffer
glLoadIdentity();

glTranslated(0.0,0.0,-6.0);
glColor3d(1.0,0.0,0.0);
sierpinski();
glutSwapBuffers();
}

void idle() { /*new*/
glutPostRedisplay();
sleep(5);
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
glutMainLoop();
return 0;
}

