#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "freeglut.h"
#include "Image.h"
#include "Camera.h"
#include "BruteForce.h"
#include "GameObject.h"
#include "md2model.h"

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

	int frameCounter;

	Image* skytex;///Texture for skybox
	Image* watertex;///Texture for water
	int waterHeight;///Height of water texture

	void DrawSkybox();///Draws skybox
	void LoadSkybox(const char* filename);///Loads skybox texture
	void DrawWater();///Draws water
	void LoadWater(const char* filename, int height);///Loads water texture
	void DrawMenu();///Draws menu on startup
	void DrawUI();///Draws UI when playing

	float playerHP;///Health of player
	float playerScore;///Time survived in game

	int len; /// Integer for reading string length of UI string elements
	string hpString; /// String for HP UI element
	string scoreString; /// String for Score UI element
	void * font;
protected:
	void OnAnimate(float deltaTime);
	//void OnDraw(CCamera *camera);
	void OnPrepare();
	

public:
	BruteForce terrain;///renderer
	Camera camera;///player camera
	GameObject* gameObjects; /// objects to interact with
	//GameObject first;
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
	bool IsGameDone() { return gameDone; }
	void QuitGame() { gameDone = true; }
	int GetNpcs() { return numNpcs; }
	float getWorldXZHeight(int x, int z) { return terrain.getHeight(x, z); }
	float time0, time1;
	void SetHP(float hp);
	float GetHP();

	Image* groupImg;///group image
	bool ended;///check if player has finished level
	bool menu;///Check if menu is showing


	int GetWaterHeight() { return waterHeight; }
};