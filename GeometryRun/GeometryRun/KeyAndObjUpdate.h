#pragma once

#include "GameObjectManager.h"
#include "BackGround.h"
#include "Input.h"
#include "Player.h"

#define FLAG_IMPORTANTKEY 2

float winMaxX, winMaxY, winMinX, winMinY;

// ��ײ��������󣬷������ʱʹ��
GameObj *pInstForCollisionDetect;

Status GetWinMaxMinXY();

Status KeyUpdate();

Status Visit_Update(insNode* pinsNode, GameObjList L);

Status Visit_CollisionDetect(insNode* pinsNode, GameObjList L);

Status Visit_Matrix2DCount(insNode* pinsNode, GameObjList L);

Status BossUpdate(int level, clock_t LevelTime, float bossOccurTime);

