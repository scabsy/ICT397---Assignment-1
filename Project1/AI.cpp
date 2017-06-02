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


void setRot(float rot)
{
	 stattt::a->setRot(rot);
}

float getRot()
{
	return stattt::a->getRot();
}

float getPosZ()
{
	return stattt::a->getPosZ();
}

float getPosY()
{
	return stattt::a->getPosY();
}

float getPosX()
{
	return stattt::a->getPosX();
}

void setPosX(float x)
{
	stattt::a->setPosX(x);
}


void setPosY(float y)
{
	stattt::a->setPosY(y);
}

void setPosZ(float z)
{
	stattt::a->setPosZ(z);
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

	luaL_openlibs(stattt::L);
	luabind::open(stattt::L);
	luabind::module(stattt::L)
		[
			luabind::def("getPosX", &getPosX),
			luabind::def("setPosX", &setPosX),
			luabind::def("getPosY", &getPosY),
			luabind::def("setPosY", &setPosY),
			luabind::def("getPosZ", &getPosZ),
			luabind::def("setPosZ", &setPosZ),
			luabind::def("getRot", &getRot),
			luabind::def("setRot", &setRot),
			luabind::def("getCamLoc", &getCamLoc)
		];
	if (luaL_dofile(stattt::L, filename.c_str()))
	{
		const char* err = lua_tostring(stattt::L, -1);
		cout << err << endl;
	}

	lua_settop(stattt::L, 0);
	lua_close(stattt::L);
}