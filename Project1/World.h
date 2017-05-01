#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "freeglut.h"
#include "Camera.h"
#include "BruteForce.h"
#include "GameObject.h"

using namespace std;

/**
* Defines world and sets it up for user
*/
class World
{
private:
	int numNpcs;
	int screenW, screenH;
	bool gameDone;

protected:
	void OnAnimate(float deltaTime);
	//void OnDraw(CCamera *camera);
	void OnPrepare();

public:
	BruteForce terrain;///renderer
	Camera camera;///player camera
	GameObject* gameObjects; /// objects to interact with

	/*Player *player;
	AudioSystem * audioSystem;
	Audio *worldSound;
	GUI *gui;
	Levels *levels;
	Enemy *NPC;
	float timeStart;
	float timeElapsed;*/
	World();
	//World(Camera *c);
	~World();

	/**
	* @brief, all files to be loaded, load here
	*/
	void LoadWorld();

	///deconstructs objects
	void LoadWorldTextures();
	void UnloadWorld();
	int CountObjTypes(const type_info &classID);

	///loads animations
	void Animate(float deltaTime);
	//void Draw(Camera *camera);

	//void Draw(Camera *camera);
	/*
	* @brief all loaded files will be drawn in this method, anything that is needed in the game will be rendered here
	*/
	void Draw();
	void Prepare() { OnPrepare(); }
	void FadeScreen();
	void SetScreen(int w, int h);
	bool IsGameDone() { return gameDone; }
	void QuitGame() { gameDone = true; }
	int GetNpcs() { return numNpcs; }
	float getWorldXZHeight(int x, int z) { return terrain.getHeight(x, z); }

	double time0, time1;

	Image* groupImg;///group image
	bool ended;///check if player has finished level
};