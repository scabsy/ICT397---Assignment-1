#include "Input.h"
#include "singletons.h"

Input::Input()
{
	wired = false;
	screenW = 1280;
	screenH = 720;
	oldx = screenW / 2;
	oldy = screenH / 2;
	rotSpeed = 1200;
}

void Input::keys(unsigned char key, int x, int y)
{
	float speed = .5f;
	if (gameWorld.camera.pos.y < 8)
	{
		speed = .1f;
	}
	else
	{
		speed = .5f;
	}
	switch (key)
	{
		
	case 'w':
		if (!gameWorld.menu)
		{
			gameWorld.camera.AddVel(0, 0, speed);
		}
		break;
	case 's':
		if (!gameWorld.menu)
		{
			gameWorld.camera.AddVel(0, 0, -speed);
		}
		break;
	case 'a':
		if (!gameWorld.menu)
		{
			gameWorld.camera.AddVel(-speed, 0, 0);
		}
		break;
	case 'd':
		if (!gameWorld.menu)
		{
			gameWorld.camera.AddVel(speed, 0, 0);
		}
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
	case'm':
		cout << gameWorld.camera.pos.x << " " << gameWorld.camera.pos.y << " " << gameWorld.camera.pos.z << endl;
		break;
	case 'x':
		if (!gameWorld.ended)
			gameWorld.ended = true;
		else
			gameWorld.ended = false;
		break;
	case'z':
		gameWorld.menu = false;
		break;
	}
}

void Input::mouseMove(int x, int y)
{
	// Warp mouse pointer to center of screen
	if (x != screenW / 2 || y != screenH / 2)
        glutWarpPointer(screenW / 2, screenH / 2);


	int deltaX = (x - screenW / 2);
	int deltaY = (y - screenH / 2);
	gameWorld.camera.yaw += (deltaX * 180) / rotSpeed;
	gameWorld.camera.pitch -= (deltaY * 180) / rotSpeed;

	//oldx = x;
	//oldy = y;
	//glutWarpPointer(screenW / 2, screenH / 2);
}

void Input::mouseClicks(int button, int state, int x, int y)
{
	if (gameWorld.ended)
	{
		exit(0);
	}
}