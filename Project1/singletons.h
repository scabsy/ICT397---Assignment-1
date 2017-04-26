#ifndef __SINGLETONS_H
#define __SINGLETONS_H

#if _MCS_VER >= 1020
  #pragma once
#endif
#include "world.h"
#include "singleton.h"
typedef singleton<World> theWorld;
#define gameWorld theWorld::Instance()

#endif