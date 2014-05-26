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

#define kWindowWidth	400 // Constants
#define kWindowHeight	300

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
static double rotate; /*new*/
static double scale; /*new*/
rotate += 30.0;
if (rotate > 360.0) {
  rotate = 30.0;
}
scale += 0.5;
if (scale > 3.0) {
  scale = -3.0;
} else if (scale == 0.0) {
  scale = 0.5;
}
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Clear The Screen And The Depth Buffer
glLoadIdentity();

glTranslated(0.0,0.0,-6.0);
glRotated(rotate,0.0,1.0,0.0);
glScaled(scale,scale,scale);
  // draw a pyramid (in smooth coloring mode)
glBegin(GL_TRIANGLES);		// start drawing a pyramid

  // front face of pyramid
glColor3d(0.0,0.0,1.0);		// Set The Color To Blue
glVertex3d(0.0, 1.0, 0.0);		// Top of triangle (front)
glVertex3d(-1.0,-1.0, 1.0);		// left of triangle (front)
glVertex3d(1.0,-1.0, 1.0);		// right of triangle (front)	

  // right face of pyramid
glColor3d(0.0,1.0,0.0);		// Green
glVertex3d(0.0,1.0,0.0);		// Top Of Triangle (Right)
glVertex3d(1.0,-1.0,1.0);		// Left Of Triangle (Right)
glVertex3d(1.0,-1.0,-1.0);	// Right Of Triangle (Right)

  // back face of pyramid
glColor3d(1.0,1.0,0.0);		// Yellow
glVertex3d(0.0,1.0,0.0);		// Top Of Triangle (Back)
glVertex3d(1.0,-1.0,-1.0);	// Left Of Triangle (Back)
glVertex3d(-1.0,-1.0,-1.0);	// Right Of Triangle (Back)

  // left face of pyramid.
glColor3d(1.0,0.0,0.0);		// Red
glVertex3d(0.0,1.0,0.0);		// Top Of Triangle (Left)
glVertex3d(-1.0,-1.0,-1.0);		// Left Of Triangle (Left)
glVertex3d(-1.0,-1.0, 1.0);		// Right Of Triangle (Left)

glEnd();				// Done Drawing The Pyramid
glutSwapBuffers();
}

void idle() { /*new*/
glutPostRedisplay();
sleep(1);
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

