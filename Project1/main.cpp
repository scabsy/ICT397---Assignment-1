<<<<<<< HEAD
#include <iostream>
#include "freeglut.h"
#include "World.h"
#include "singletons.h"
#include "Camera.h"

//World gameWorld;

using namespace std;

//Camera cam;

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

=======
#include <iostream>
#include "freeglut.h"
#include "World.h"
#include "singletons.h"
#include "Camera.h"

//World gameWorld;

using namespace std;

Camera cam;

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

>>>>>>> origin/master
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
<<<<<<< HEAD
	glShadeModel(GL_SMOOTH);

	gameWorld.LoadWorldTextures();
}

void display(void)
{
	gameWorld.Draw();
}


void keys(unsigned char key, int x, int y)
{
	auto speed = 5.f;
	switch (key)
	{
	case 'w':
		gameWorld.camera.AddVel(0, 0, speed);
		break;
	case 's':
		gameWorld.camera.AddVel(0, 0, -speed);
		break;
	case 'a':
		gameWorld.camera.AddVel(-speed, 0, 0);
		break;
	case 'd':
		gameWorld.camera.AddVel(speed, 0, 0);
		break;
	/*case 'q':
		camY--;
		break;
	case 'e':
		camY++;
		break;*/
	case 'z':
		gameWorld.camera.yaw--;
		break;
	case 'x':
		gameWorld.camera.yaw++;
		break;
	case'm':
		break;
	case 27:
		exit(0);
	}
}
int oldx = screenW / 2;
int oldy = screenH / 2;
void mouseMove(int x, int y)
{
	
	int deltaX = oldx - x;
	int deltaY = oldy - y;
	gameWorld.camera.yaw -= deltaX*.25;
	gameWorld.camera.pitch += deltaY*.25;
	oldx = x;
	oldy = y;
	//glutWarpPointer(screenW / 2, screenH / 2);
}

int main(int argc,char**argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(screenW, screenH);
	glutCreateWindow("Height Map");
=======
	glShadeModel(GL_SMOOTH);

	gameWorld.LoadWorldTextures();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	GLfloat ambientColor[] = {0.4f, 0.4f, 0.4f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	GLfloat lightColor0[] = {0.6f, 0.6f, 0.6f, 1.0f};
	GLfloat lightPos0[] = {-0.5f, 0.8f, 0.1f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	glTranslatef(0, 0, 0);
	//glRotatef(-_angle, 0.0f, 1.0f, 0.0f);
	

	cam.Update();
	gameWorld.Draw();
>>>>>>> origin/master
	
	glutPostRedisplay();
    glutSwapBuffers();
}

void keys(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
		cam.AddVel(0, 0, .5);
		break;
	case 's':
		cam.AddVel(0, 0, -.5);
		break;
	case 'a':
		cam.AddVel(-.5, 0, 0);
		break;
	case 'd':
		cam.AddVel(.5, 0, 0);
		break;
	/*case 'q':
		camY--;
		break;
	case 'e':
		camY++;
		break;*/
	case 'z':
		_angle--;
		break;
	case 'x':
		_angle++;
		break;
	case'm':
		break;
	case 27:
		exit(0);
	}
}

void mouseMove(int x, int y)
{
	int oldx = screenW / 2;
	int oldy = screenH / 2;
	int deltaX;
	int deltaY;
	deltaY = oldy - y;
	deltaX = oldx - x;
	cam.yaw -= deltaX*.25;
	cam.pitch += deltaY*.25;
	oldx = x;
	oldy = y;
	glutWarpPointer(screenW / 2, screenH / 2);
}

int main(int argc,char**argv)
{	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(screenW, screenH);
	glutCreateWindow("Game Engine");
	
	init();

	glutDisplayFunc(display);
<<<<<<< HEAD
	glutKeyboardFunc(keys);
	glutPassiveMotionFunc(mouseMove);

	glutMainLoop();
	return 0;
=======
	glutKeyboardFunc(keys);
	glutMotionFunc(mouseMove);

	glutMainLoop();
	return 0;
>>>>>>> origin/master
}