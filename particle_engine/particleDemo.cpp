/*
 * @Heintze, Darrell R.
 * 6544 10/10/2012
*/
// compile with g++ particleDemo.cpp -lX11 -lXi -lXmu -lglut -lGL -lGLU -lm // -framework OpenGL -framework GLUT for osx
#include <stdlib.h>
#include <iostream>
using namespace std;

// #include <GL/glu.h> // Header File For The GLu32 Library
#include <unistd.h>     // Header file for sleeping.

#ifdef __APPLE__                    // Header File For The GLUT Library
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#ifdef __APPLE__                    // Header File For The OpenGL32 Library
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif


#include "particle.h"


#define PARTICLE_MAX 100
#define ESCAPE 27 //escape key

int window; // GL Window Handle

int i = 0; //Iterator


Particle* particles = new Particle[PARTICLE_MAX];

void initParticles()
{
    for(i=0;i<PARTICLE_MAX;i++)
    {
        particles[i].setPosX(0.1f); particles[i].setPosY(0.1f);
        particles[i].setvX(((float)rand()/(float)RAND_MAX+1)-1);
        particles[i].setvY(((float)rand()/(float)RAND_MAX+1)-1);
    }
}
void updateParticles()
{
    cout<<"Update Particles called!"<<endl<<endl;
    for(i=0;i<PARTICLE_MAX;i++)
    {
        //change velocities
        particles[i].setvX(particles[i].getvX() + particles[i].getaX());
        particles[i].setvY(particles[i].getvY() + particles[i].getaY());
        //change positions
        particles[i].setPosX(particles[i].getPosX() + particles[i].getvX());
        particles[i].setPosY(particles[i].getPosY() + particles[i].getvY());
    }
}
void drawParticles()
{
    glTranslated(0.0f,0.0f,-9.0f);
    for(i=0;i<PARTICLE_MAX;i++) {
        glColor4f(              //Sets draw color to correct particle values
            particles[i].getR(),
            particles[i].getG(),
            particles[i].getB(),
            particles[i].getA()
        );
        glBegin(GL_QUADS);

        glVertex3f(particles[i].getPosX(), particles[i].getPosY(), 0.0f);
        glVertex3f(particles[i].getPosX()+0.1f, particles[i].getPosY(), 0.0f);
        glVertex3f(particles[i].getPosX()+0.1f, particles[i].getPosY()+0.1f,0.0f);
        glVertex3f(particles[i].getPosX(), particles[i].getPosY()+0.1f, 0.0f);
        glEnd();
        glutSwapBuffers();

        //Testing prints statements that ensure particles are working, just need to be drawn
        cout<<"particle's variables are: " << endl;
        cout<<"posX:\t" << particles[i].getPosX() << "\t\tposY:\t" << particles[i].getPosY() << endl;
        cout<<"vX:\t" << particles[i].getvX() << "\tvY:\t" << particles[i].getvY() << endl;
        cout<<"aX:\t" << particles[i].getaX() << "\t\taY:\t" << particles[i].getaY() << endl;
        cout<<"Particle color is: " << endl;
        cout<<"R: "<< particles[i].getR() << " G: " << particles[i].getG() << " B: " << particles[i].getB() << endl;
    }
    usleep(1000);
}

//////////////////////////////////////*	 GL Functions to use: 	*/////////////////////////////////////////////////////
/* A general OpenGL initialization function.  Sets all of the initial parameters. */
void InitGL(int Width, int Height)	        // We call this right after our OpenGL window is created.
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);		// This Will Clear The Background Color To Black
    glClearDepth(1.0);				// Enables Clearing Of The Depth Buffer
    glDepthFunc(GL_LESS);				// The Type Of Depth Test To Do
    glEnable(GL_DEPTH_TEST);			// Enables Depth Testing
    glShadeModel(GL_SMOOTH);			// Enables Smooth Color Shading

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();				// Reset The Projection Matrix

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);	// Calculate The Aspect Ratio Of The Window

    glMatrixMode(GL_MODELVIEW);
}
/* The function called when our window is resized (which shouldn't happen, because we're fullscreen) */
void ReSizeGLScene(int Width, int Height)
{
    if (Height==0) Height=1;				// Prevent A Divide By Zero If The Window Is Too Small

    glViewport(0, 0, Width, Height);		// Reset The Current Viewport And Perspective Transformation

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
    glMatrixMode(GL_MODELVIEW);
}
/* The main drawing function. */
void DrawGLScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		// Clear The Screen And The Depth Buffer
    glLoadIdentity();				// Reset The View

    updateParticles();
    drawParticles();
}
void keyPressed(unsigned char key, int x, int y)
{
    /* avoid thrashing this procedure */
    usleep(100);
    /* If escape is pressed, kill everything. */
    if (key == ESCAPE) {
	    glutDestroyWindow(window);
    	exit(0);
    }
}
//End of GL functions

int main ( int argc, char **argv )
{
    initParticles();
    //General GL calls
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_ALPHA | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    window = glutCreateWindow("Roland's particle engine demo");
    glutDisplayFunc(&DrawGLScene);
    glutIdleFunc(&DrawGLScene);
    glutReshapeFunc(&ReSizeGLScene);
    glutKeyboardFunc(&keyPressed);
    InitGL(800, 600);
    glutMainLoop();
    //GL End
    return 0;
}
