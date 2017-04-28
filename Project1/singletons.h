#ifndef __SINGLETONS_H
#define __SINGLETONS_H

#include "World.h"
#include "OBJLoader.h"
#include "TextureLoader.h"
#include "FileManager.h"
#include "singleton.h"
typedef singleton<World> theWorld;
#define gameWorld theWorld::Instance()

typedef singleton<OBJLoader> objLoader;
#define objLoad objLoader::Instance()

typedef singleton<TextureLoader> textureLoader;
#define texLoad textureLoader::Instance()


typedef singleton<FileManager> fileManager;
#define FileMan fileManager::Instance()

#endif