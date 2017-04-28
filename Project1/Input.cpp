#include "Input.h"
#include "singletons.h"

Input::Input()
{
	wired = false;
	screenW = 1280;
	screenH = 720;
	oldx = screenW / 2;
	oldy = screenH / 2;
}

void Input::keys(unsigned char key, int x, int y)
{
	auto speed = 1.f;
	switch (key)
	{
	case 'w':
		gameWorld.camera.AddVel(0, 0, speed);
		break;
	case 's':
		gameWorld.camera.AddVel(0, 0, -speed);
		break;
	case 'a':
		gameWorld.camera.AddVel(-speed, 0, 0);
		break;
	case 'd':
		gameWorld.camera.AddVel(speed, 0, 0);
		break;
	case'k':
		if (wired)
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			wired = false;
		}
		else
		{
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			wired = true;
		}
		break;
	case 'x':
		exit(0);
	}
}

void Input::mouseMove(int x, int y)
{
	int deltaX = oldx - x;
	int deltaY = oldy - y;
	gameWorld.camera.yaw -= deltaX*.25;
	//gameWorld.camera.pos.y += deltaY*.05f;

	oldx = x;
	oldy = y;
	//glutWarpPointer(screenW / 2, screenH / 2);
}