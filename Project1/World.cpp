<<<<<<< HEAD
#include "World.h"


World::World()
{
	LoadWorld();
}

/*World::World(Camera *c)
{

}*/

World::~World()
{
	UnloadWorld();
}

void World::LoadWorld()
{
	time0 = glutGet(GLUT_ELAPSED_TIME);
	terrain.setScalingFactor(1, 1, 1);
	terrain.loadHeightfield("heightmaps/height128.raw", 128);

	monkey = obj.loadObject("models/monkey.obj");
	//camera.SetTerrain(terrain);
}

void World::LoadWorldTextures()
{
	terrain.loadTexture("textures/grassB.raw", 1024);
}

void World::UnloadWorld()
{

}

int World::CountObjTypes(const type_info &classID)
{
	return 1;
}

void World::Animate(float deltaTime)
{

}

/*void World::Draw(Camera *camera)
{

}*/

void World::Draw()
{
	time1 = glutGet(GLUT_ELAPSED_TIME);
	if (((float)time1 - time0) > 0.05)
	{
		time0 = time1 - 0.05;
	}

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat ambientColor[] = { 0.4f, 0.4f, 0.4f, 1.0f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

	GLfloat lightColor0[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	GLfloat lightPos0[] = { -0.5f, 0.8f, 0.1f, 0.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	camera.Update(time1-time0);
	terrain.Render();

	glTranslatef(50, 50, 50);
	//glColor3ub(0.5, 0.8, 0.1);
	glCallList(monkey);

	glutPostRedisplay();
	glutSwapBuffers();
}

void World::FadeScreen()
{

}

void World::SetScreen(int w, int h)
{

=======
#include "World.h"


World::World()
{
	LoadWorld();
}

/*World::World(Camera *c)
{

}*/

World::~World()
{
	UnloadWorld();

}

void World::LoadWorld()
{
	terrain.setScalingFactor(1, 1, 1);
	terrain.loadHeightfield("heightmaps/height128.raw", 128);
	fileManager.ScriptLoad("scripts/test.lua");
	//camera.SetTerrain(terrain);
}

void World::LoadWorldTextures()
{
	terrain.loadTexture("textures/grassB.raw", 1024);
}

void World::UnloadWorld()
{
	
}

int World::CountObjTypes(const type_info &classID) 
{
	return 1;
}

void World::Animate(float deltaTime)
{

}

/*void World::Draw(Camera *camera)
{

}*/

void World::Draw()
{
	//camera->Update();
	terrain.Render();
}

void World::FadeScreen()
{

}

void World::SetScreen(int w, int h)
{

>>>>>>> origin/master
}