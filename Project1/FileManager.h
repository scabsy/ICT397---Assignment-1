#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include "lua.hpp"
#include "GameObject.h"
#include "BruteForce.h"
#include <vector>

class FileManager
{
private:
	BruteForce terrain;
public:
	FileManager(void);
	~FileManager(void);

	GameObject* LoadScripts();
	BruteForce LoadTerrain(const char * fileName);

	void ModelLoad(const char * fileName);
	GameObject LoadGO(const char * fileName);
};

#endif