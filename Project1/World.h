#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "freeglut.h"
#include "Camera.h"
#include "BruteForce.h"
#include "GameObject.h"

using namespace std;

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
	BruteForce terrain;
	Camera camera;
	GameObject* gameObjects;
	GameObject monkey;
	GameObject monkey1;
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

	void LoadWorld();
	void LoadWorldTextures();
	void UnloadWorld();
	int CountObjTypes(const type_info &classID);
	void Animate(float deltaTime);
	//void Draw(Camera *camera);
	void Draw();
	void Prepare() { OnPrepare(); }
	void FadeScreen();
	void SetScreen(int w, int h);
	bool IsGameDone() { return gameDone; }
	void QuitGame() { gameDone = true; }
	int GetNpcs() { return numNpcs; }
	float getWorldXZHeight(int x, int z) { return terrain.getHeight(x, z); }

	double time0, time1;
};