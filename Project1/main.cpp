#include <iostream>
#include "freeglut.h"
#include "World.h"
#include "singletons.h"
#include "Camera.h"
#include "Input.h"

//World gameWorld;

using namespace std;

Input input;

float _angle = 180.0f;


int screenW = 1280;
int screenH = 720;

void init(void)
{
	/* attributes */
    glClearColor(0.0, 0.0, 0.0, 1.0); /* draw on white background */
    glColor3f(1.0, 0.0, 0.0); /* draw in red */
    glLineWidth(5.0);   /* draw using lines 5 pixels wide */
    /* set up viewing */
    /* 500 x 500 pixel window with origin at lower left corner of display
     window*/
    glEnable(GL_DEPTH_TEST);
    /* switch matrix mode to 'projection' and load an identity matrix as the projection matrix */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();


//
    GLdouble fov	 = 90;		// degrees
    GLdouble aspect	 = 1;		// aspect ratio aspect = height/width
    GLdouble nearVal = 0.1;
    GLdouble farVal  = 10000;     // near and far clipping planes
    gluPerspective(fov, aspect, nearVal, farVal);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);

	gameWorld.LoadWorldTextures();
}

void display(void)
{
	gameWorld.Draw();
}

void keys(unsigned char key, int x, int y)
{
	input.keys(key, x, y);
}

void mouseMove(int x, int y)
{	
	input.mouseMove(x, y);
}

int main(int argc,char**argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(screenW, screenH);
	glutCreateWindow("Height Map");
	
	init();

	glutDisplayFunc(display);
	glutKeyboardFunc(keys);
	glutPassiveMotionFunc(mouseMove);

	glutMainLoop();
	return 0;
}