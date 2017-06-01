#pragma once
#ifndef SKYBOX_H
#define SKYBOX_H

class Skybox
{
public:
	void loadSkybox();
	void renderSkybox();
	void releaseSkybox();

private:
	int ioVAO;
	
};
#endif // !SKYBOX_H
