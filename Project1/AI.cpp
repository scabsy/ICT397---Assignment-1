#include "AI.h"
#include <iostream>
namespace stattt
{
	GameObject* a = new GameObject();
	Vector::vec3 pos = Vector::vec3();
	lua_State *L = luaL_newstate();
}

AI::AI()
{

}

void AI::Position()
{

}

void AI::Update()
{

}

float getPosX()
{
	return stattt::a->getPosX();
}

void setPosX(float x)
{
	stattt::a->setPosX(x);
}

luabind::object getCamLoc()
{
	luabind::object blerg = luabind::newtable(stattt::L);
	blerg["x"] = stattt::pos.x;
	blerg["y"] = stattt::pos.y;
	blerg["z"] = stattt::pos.z;
	return blerg;
}

void AI::ReadAIFile(string filename, GameObject* ab, Camera &cam)
{
	//x = xCur;
	//y = yCur;
	//z = zCur;
	stattt::a = ab;
	stattt::pos = cam.pos;
	stattt::L = luaL_newstate();

	//cout << "hello X: " << stattt::a->getPosX() << endl;
	luaL_openlibs(stattt::L);
	luabind::open(stattt::L);
	luabind::module(stattt::L)
		[
			luabind::def("getPosX", &getPosX),
			luabind::def("setPosX", &setPosX),
			luabind::def("getCamLoc", &getCamLoc)
		];
	if (luaL_dofile(stattt::L, filename.c_str()))
	{
		const char* err = lua_tostring(stattt::L, -1);
		cout << err << endl;
	}

	lua_settop(stattt::L, 0);
	lua_close(stattt::L);
	//cout << "hello New X: " << stattt::a->getPosX() << endl;
}