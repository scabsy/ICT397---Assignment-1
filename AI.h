#ifndef __AI_H
#define __AI_H
#include "vec3.h"
#include "GameObject.h"
#include "Camera.h"
#include "lua.hpp"
#include "lualib.h"
#include <string>
#include <sstream>
#include "luabind\luabind.hpp"
using namespace std;
class GameObject;
class AI
{
private:
   
   void Position();
   string aiFile;
   float x, y, z;
   

public:
	AI();
	void Update();
	static void ReadAIFile(string filename,GameObject* ab, Camera &cam);
	static GameObject* a;
	static vec3 pos;
	static lua_State *L;
};

#endif