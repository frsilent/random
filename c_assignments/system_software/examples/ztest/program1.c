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
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// Clear The Screen And The Depth Buffer
glLoadIdentity();
glTranslatef(-1.5f,0.0f,-6.0f);
glBegin(GL_TRIANGLES);
glVertex3d( 0.0, 1.0, 0.0);
glVertex3d(-1.0,-1.0, 0.0);
glVertex3d( 1.0,-1.0, 0.0);
glEnd();

glTranslatef(3.0f,0.0f,0.0f);
glBegin(GL_QUADS);
glVertex3f(-1.0f, 1.0f, 0.0f);
glVertex3f( 1.0f, 1.0f, 0.0f);
glVertex3f( 1.0f,-1.0f, 0.0f);
glVertex3f(-1.0f,-1.0f, 0.0f);
glEnd();
	
glFlush();
}

GLvoid ReSizeGLScene(int Width, int Height) {
glViewport (0, 0, (GLsizei) Width, (GLsizei) Height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(45.0, (GLfloat) Width / (GLfloat) Height, 0.1, 100.0);   
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

int main(int argc, char* argv[], char *envp[]) {	
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
glutInitWindowSize (kWindowWidth, kWindowHeight); 
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);	
InitGL(); 
glutDisplayFunc(DrawGLScene); 
glutReshapeFunc(ReSizeGLScene); 
glutMainLoop();
return 0;
}
