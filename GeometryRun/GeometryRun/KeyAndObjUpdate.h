#pragma once

#include "GameObjectManager.h"
#include "input.h"

#define FLAG_IMPORTANTKEY 2

float winMaxX, winMaxY, winMinX, winMinY;

Status GetWinMaxMinXY();

Status KeyUpdate();

Status Visit_PositionUpdate(insNode* pinsNode, GameObjList L);

Status Visit_CollisionDetect(insNode* pinsNode, GameObjList L);

Status Visit_Matrix2DCount(insNode* pinsNode, GameObjList L);
