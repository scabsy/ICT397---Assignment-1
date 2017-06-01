#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include "lua.hpp"
#include "GameObject.h"
#include "BruteForce.h"
#include <vector>
using namespace std;
/**
* Class to manage the LUA files inputted by the developer
*/
class FileManager
{
private:
	BruteForce terrain;
public:
	FileManager(void);
	~FileManager(void);

	GameObject* LoadScripts();

	/**
	* Loads in LUA script to return a new terrain
	* @param heightMap is a string that is the location of the raw file to be used
	* @param fieldText1 is a string that is the location of the raw file to be used
	* @param fieldText2 is a string that is the location of the raw file to be used
	* @param fieldText3 is a string that is the location of the raw file to be used
	* @param fieldText4 is a string that is the location of the raw file to be used
	* @param xScalis a int that ditactes the x size of said terrain
	* @param yScalis a int that ditactes the y size of said terrain
	* @param zScalis a int that ditactes the z size of said terrain
	* @return BruteForce terrain
	*/
	BruteForce LoadTerrain(const char * fileName);

	/**
	* Load model given the file name and path
	* @param filename - path to obj to load
	*/
	void ModelLoad(const char * fileName);

	/*
	* Loads in LUA scripts to return a new GameObject
	* @param model is a string that is the location of the raw file to be used
	* @param scale a int that ditactes the scale of said gameobject
	* @param x is the location of the x axis
	* @param y is the location of the y axis
	* @param z is the location of the z axis
	*/
	GameObject LoadGO(const char * fileName);
};

#endif