#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "GameStateList.h"
#include "Player.h"
#include "BackGround.h"

#define SIZE_SCORE 3// 显示的分数的位数

enum {
	STYPE_LEVEL,
	STYPE_UNLIMITED,
	STYPE_COUNT
};

extern Status UIStatusLoad();

extern Status UIStatusStart();

extern Status UIStatusUpdate();

extern float UIStatusScaleGet();

