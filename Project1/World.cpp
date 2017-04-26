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

}