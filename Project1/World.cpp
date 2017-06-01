#include "World.h"
#include "singletons.h"


World::World()
{
	LoadWorld();
	ended = false;
	groupImg = texLoad.LoadTexture("textures/group.raw", 256, 256);
	frameCounter = 0;
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

	terrain = FileMan.LoadTerrain("scripts/terrain/terrain.lua");
	/*terrain.setScalingFactor(1, 1, 1);
	terrain.loadHeightfield("heightmaps/height128 - Copy.raw", 128);*/
	//terrain.loadHeightfield("heightmaps/height128.raw", 128);

	//monkey = FileMan.LoadGO("scripts/test.lua");
	//monkey1 = FileMan.LoadGO("scripts/test1.lua");
	//gameObjects = new GameObject[100];
	gameObjects = FileMan.LoadScripts();

	//camera.SetTerrain(terrain);
}

void World::LoadWorldTextures()
{
	/*terrain.addProceduralTexture("textures/lowestTile.raw");
	terrain.addProceduralTexture("textures/lowTile.raw");
	terrain.addProceduralTexture("textures/highTile.raw");
	terrain.addProceduralTexture("textures/highestTile.raw");

	terrain.createProceduralTexture();*/
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

	GLfloat lightColor0[] = { 0.9f, 0.6f, 0.6f, 1.0f };
	GLfloat lightPos0[] = { -0.5f, 0.8f, 0.1f, 0.0f };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

	camera.Update(time1-time0);
	terrain.Render();

	//monkey.render();
	//monkey1.render();
	for (int i = 0; i < 20; i++)
	{
		//if (gameObjects[i].valid)
		//{


		gameObjects[i].render(time1 - time0);
		gameObjects[i].processCollision(camera);


		gameObjects[i].Update(camera);
		//}
			/*frameCounter++;

			if (frameCounter > 60)
			{
				for (int j = 0; j < 20; j++)
				{
					gameObjects[i].processCollision(gameObjects[j]);
				}
				frameCounter = 0;
			}*/
	}
		

	if (ended)
	{
		glMatrixMode(GL_PROJECTION);
		glPushMatrix();
		glLoadIdentity();
		glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();


		glLoadIdentity();


		glColor3f(1, 1, 1);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, groupImg->GetID());

		// Draw a textured quad
		//glTranslatef(
		float offX = screenW + 200;
		float offY = screenH / 2 + 200;
		glBegin(GL_QUADS);
			glTexCoord2f(0, 0); glVertex3f(offX, offY + 400, 0);
			glTexCoord2f(0, 1); glVertex3f(offX, offY, 0);
			glTexCoord2f(1, 1); glVertex3f(offX+400, offY, 0);
			glTexCoord2f(1, 0); glVertex3f(offX+400, offY+400, 0);
		glEnd();


		glDisable(GL_TEXTURE_2D);
		glPopMatrix();


		glMatrixMode(GL_PROJECTION);
		glPopMatrix();

		glMatrixMode(GL_MODELVIEW);
	}
	
	glutPostRedisplay();
	glutSwapBuffers();
}

void World::FadeScreen()
{

}

void World::SetScreen(int w, int h)
{

}