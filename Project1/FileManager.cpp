#include "FileManager.h"

using namespace std;

FileManager::FileManager(void)
{

}
FileManager::~FileManager(void){}

GameObject* FileManager::LoadScripts()
{
	int counter = 0;
	GameObject* gos=new GameObject[100];
	fstream f ("scripts/loader.txt", fstream::in | fstream::out);
	if (f)
	{
		string line;
		while (getline(f, line))
		{
			char* newM = new char[line.length() + 1];
			memcpy(newM, line.c_str(), line.length() + 1);

			GameObject tmp = LoadGO(newM);
			gos[counter] = tmp;
			counter++;
			//gos.push_back(tmp);
		}

		f.close();
	}
	return gos;
}

/**
 * @brief loads in model and returns model
 * @param 
 **/

GameObject FileManager::LoadGO(const char * fileName)
{	
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	string model;
	int scale, x, y, z;
	if (luaL_dofile(L, fileName))
	{
		const char* err = lua_tostring(L, -1);
		cout << err << endl;
	}

	lua_settop(L,0);
	lua_getglobal(L, "model");
	if (!lua_isstring(L, 1))
	{
		cout << "error checking string" << endl;
		model = "";
	}
	else
	{
		model = lua_tostring(L, 1);
	}

	lua_getglobal(L, "scale");
	if (!lua_isnumber(L, 2))
	{
		cout << "error checking number" << endl << "Default Scale is 1" << endl;
		scale = 1;
	}

	else
	{
		scale = lua_tonumber(L, 2);
	}

	lua_getglobal(L, "x");
	if (!lua_isnumber(L, 3))
	{
		cout << "error checking number" << endl << "Default x is 0" << endl;
		x = 0;
	}

	else
	{
		x = lua_tonumber(L, 3);
	}

	lua_getglobal(L, "y");
	if (!lua_isnumber(L, 4))
	{
		cout << "error checking number" << endl << "Default y is 0" << endl;
		y = 0;
	}

	else
	{
		y = lua_tonumber(L, 4);
	}

	lua_getglobal(L, "z");
	if (!lua_isnumber(L, 5))
	{
		cout << "error checking number" << endl << "Default z is 0" << endl;
		z = 0;
	}

	else
	{
		z = lua_tonumber(L, 5);
	}

	lua_close(L);
	cout << "Scale: " << scale << endl
		<< "Dave: " << model << endl
		<< "X: " << x << endl
		<< "Y: " << y << endl
		<< "Z: " << z << endl;
	
	char* newM = new char[model.length() + 1];
	memcpy(newM, model.c_str(), model.length() + 1);

	GameObject newGO(newM, x, y, z, scale);
	return newGO;
}

void FileManager::ModelLoad(const char * fileName)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	int pos;
	if (luaL_dofile(L, fileName))
	{
		const char* err = lua_tostring(L, -1);
		cout << err << endl;
	}
	lua_settop(L, 0);
	lua_getglobal(L, "position");
	if (!lua_isnumber(L, 1))
	{
		cout << "error checking number" << endl;
	}
	pos = (int)lua_tonumber(L, 1);

	lua_close(L);
	cout << pos << endl;
}
