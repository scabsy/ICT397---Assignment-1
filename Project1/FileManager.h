#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>
#include <fstream>
#include <iostream>
#include "lua.hpp"
#include "GameObject.h"
#include <vector>

class FileManager
{
private:
public:
	FileManager(void);
	~FileManager(void);

	GameObject* LoadScripts();

	void ModelLoad(const char * fileName);
	GameObject LoadGO(const char * fileName);
};

#endif