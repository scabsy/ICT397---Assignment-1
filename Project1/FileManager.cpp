#include "FileManager.h"
#include <string>
#include <iostream>
#include "lua.hpp"

using namespace std;

FileManager::FileManager(void)
{
	
}


FileManager::~FileManager(void)
{
}


/**
 * @brief loads in model and returns model
 * @param 
 **/

void FileManager::ScriptLoad(const char * fileName)
{
	
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	int pos;
	if (luaL_dofile(L, fileName))
	{
		const char* err = lua_tostring(L, -1);
		cout << err << endl;
	}
	lua_settop(L,0);
	lua_getglobal(L, "position");
	if(!lua_isnumber(L,1))
	{
		cout << "error checking number" << endl;
	}
	pos = (int)lua_tonumber(L, 1);
	
	lua_close(L);
	cout << pos << endl;
}

void FileManager::ModelLoad(const char * fileName)
{
	//loadobj
	 //return model
}
