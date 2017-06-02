#include "FileManager.h"
#include "singletons.h"

using namespace std;

FileManager::FileManager(void)
{
}

FileManager::~FileManager(void)
{
}

BruteForce FileManager::LoadTerrain(const char * fileName)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	string heightMap, fieldText1, fieldText2, fieldText3, fieldText4;
	int xScale, yScale, zScale,mapsize,texsize;
	if (luaL_dofile(L, fileName))
	{
		const char* err = lua_tostring(L, -1);
		cout << err << endl;
	}

	lua_settop(L, 0);
	lua_getglobal(L, "heightMap");
	if (!lua_isstring(L, 1))
	{
		cout << "error checking string" << endl;
		heightMap = "";
	}
	else
	{
		heightMap = lua_tostring(L, 1);
	}


	lua_getglobal(L, "xScale");
	if (!lua_isnumber(L, 2))
	{
		cout << "error checking number" << endl << "Default Scale is 1" << endl;
		xScale = 1;
	}

	else
	{
		xScale = lua_tonumber(L, 2);
	}

	lua_getglobal(L, "yScale");
	if (!lua_isnumber(L, 3))
	{
		cout << "error checking number" << endl << "Default x is 0" << endl;
		yScale = 0;
	}

	else
	{
		yScale = lua_tonumber(L, 3);
	}

	lua_getglobal(L, "zScale");
	if (!lua_isnumber(L, 4))
	{
		cout << "error checking number" << endl << "Default y is 0" << endl;
		zScale = 0;
	}

	else
	{
		zScale = lua_tonumber(L, 4);
	}

	lua_getglobal(L, "fieldText1");
	if (!lua_isstring(L, 5))
	{
		cout << "error checking string" << endl;
		fieldText1 = "textures/lowestTile.raw";
	}
	else
	{
		fieldText1 = lua_tostring(L, 5);
	}

	lua_getglobal(L, "fieldText2");
	if (!lua_isstring(L, 6))
	{
		cout << "error checking string" << endl;
		fieldText2 = "textures/lowTile.raw";
	}
	else
	{
		fieldText2 = lua_tostring(L, 6);
	}

	lua_getglobal(L, "fieldText3");
	if (!lua_isstring(L, 7))
	{
		cout << "error checking string" << endl;
		fieldText3 = "textures/highTile.raw";
	}
	else
	{
		fieldText3 = lua_tostring(L, 7);
	}

	lua_getglobal(L, "fieldText4");
	if (!lua_isstring(L, 8))
	{
		cout << "error checking string" << endl;
		fieldText4 = "textures/highestTile.raw";
	}
	else
	{
		fieldText4 = lua_tostring(L, 8);
	}

	lua_getglobal(L, "mapsize");
	if (!lua_isstring(L, 9))
	{
		cout << "error checking string" << endl;
		mapsize = 128;
	}
	else
	{
		mapsize = lua_tonumber(L, 9);
	}
	lua_getglobal(L, "texsize");
	if (!lua_isstring(L, 10))
	{
		cout << "error checking string" << endl;
		texsize = 256;
	}
	else
	{
		texsize = lua_tonumber(L, 10);
	}

	lua_close(L);
	cout << "xScale: " << xScale << endl
		<< "yScale: " << yScale << endl
		<< "zScale: " << zScale << endl
		<< "fieldText4: " << fieldText4 << endl
		<< "fieldText3: " << fieldText3 << endl
		<< "fieldText2: " << fieldText2 << endl
		<< "fieldText1: " << fieldText1 << endl
		<< "heightMap: " << heightMap << endl
		<< "file xy: " << mapsize << endl;

	terrain.setScalingFactor(xScale, yScale, zScale);

	char* convert = new char[heightMap.length() + 1];
	memcpy(convert, heightMap.c_str(), heightMap.length() + 1);

	char* converta = new char[fieldText1.length() + 1];
	memcpy(converta, fieldText1.c_str(), fieldText1.length() + 1);

	char* convertb = new char[fieldText2.length() + 1];
	memcpy(convertb, fieldText2.c_str(), fieldText2.length() + 1);

	char* convertc = new char[fieldText3.length() + 1];
	memcpy(convertc, fieldText3.c_str(), fieldText3.length() + 1);

	char* convertd = new char[fieldText4.length() + 1];
	memcpy(convertd, fieldText4.c_str(), fieldText4.length() + 1);

	terrain.loadHeightfield(convert, mapsize);

	terrain.addProceduralTexture(converta, texsize);
	terrain.addProceduralTexture(convertb, texsize);
	terrain.addProceduralTexture(convertc, texsize);
	terrain.addProceduralTexture(convertd, texsize);

	terrain.createProceduralTexture();

	return terrain;
}

GameObject* FileManager::LoadScripts()
{
	int counter = 0;
	GameObject* gos=new GameObject[20];
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


GameObject FileManager::LoadGO(const char * fileName)
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	string model;
	float scale, x, y, z;
	bool checkAI;
	string aiFileLoc;
	bool isDestroyed, isAnimated = false;
	string tag;

	if (luaL_dofile(L, fileName))
	{
		const char* err = lua_tostring(L, -1);
		cout << err << endl;
	}

	lua_settop(L, 0);
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
		z = (float)lua_tonumber(L, 5);
	}

	//MT check for AI in GO creation script
	lua_getglobal(L, "ai");
	if (!lua_isboolean(L, 6))
	{
		cout << "error checking boolean" << endl << "Default AI is false" << endl;
		checkAI = false;
	}
	else
	{
		checkAI = lua_toboolean(L, 6);
	}
	lua_getglobal(L, "ailocation");
	if (!lua_isstring(L, 7))
	{
		cout << "error checking location" << endl << "No file location found" << endl;
		aiFileLoc = "No Location";
	}
	else
	{
		aiFileLoc = lua_tostring(L, 7);
	}

	lua_getglobal(L, "isDestoryed");
	if (!lua_isboolean(L, 8))
	{
		cout << "error checking boolean" << endl << "Default isDestoryed is false" << endl;
		isDestroyed = false;
	}
	else
	{
		isDestroyed = lua_toboolean(L, 8);
	}

	lua_getglobal(L, "tag");
	if (!lua_isstring(L, 9))
	{
		cout << "error checking string" << endl << "Default tag is 'none'" << endl;
		tag = "none";
	}
	else
	{
		tag = lua_tostring(L, 9);
	}
	lua_getglobal(L, "isAnimated");
	if (!lua_isboolean(L, 10))
	{
		cout << "error checking boolean" << endl << "Default isAnimated is false" << endl;
		isAnimated = false;
	}
	else
	{
		isAnimated = lua_toboolean(L, 10);
	}

	lua_close(L);
	cout << endl << endl << "Scale: " << scale << endl
		<< "Model: " << model << endl
		<< "X: " << x << endl
		<< "Y: " << y << endl
		<< "Z: " << z << endl
		<< "Tag: " << tag << endl
		<< "isDestroyed: " << isDestroyed << endl
		<< "AI: " << checkAI << endl
		<< "AI Location: " << aiFileLoc << endl << endl << endl;

	char* newM = new char[model.length() + 1];
	memcpy(newM, model.c_str(), model.length() + 1);

	GameObject newGO(newM, x, y, z, scale, checkAI, aiFileLoc, isDestroyed, tag, isAnimated);
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


Camera FileManager::LoadCam()
{
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	string heightMap, fieldText1, fieldText2, fieldText3, fieldText4;
	float x, y, z;
	if (luaL_dofile(L, "scripts/camera.lua"))
	{
		const char* err = lua_tostring(L, -1);
		cout << err << endl;
	}

	lua_settop(L, 0);
	lua_getglobal(L, "x");
	if (!lua_isnumber(L, 1))
	{
		cout << "error checking x" << endl;
		x =0;
	}
	else
	{
		x = lua_tonumber(L, 1);
	}

	lua_getglobal(L, "z");
	if (!lua_isnumber(L, 2))
	{
		cout << "error checking z" << endl;
		z = 0;
	}
	else
	{
		z = lua_tonumber(L, 2);
	}


	lua_close(L);

	return Camera(new Vector::vec3(x, 0, z));
}
