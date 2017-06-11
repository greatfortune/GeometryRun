#pragma once

#include "GameObjectManager.h"
#include "BackGround.h"
#include "Input.h"
#include "Player.h"
#include "Pause.h"

#define FLAG_IMPORTANTKEY 2

float winMaxX, winMaxY, winMinX, winMinY;

// ��ײ��������󣬷������ʱʹ��
GameObj *pInstForCollisionDetect;

// ======================
// ֡ʱ�䣺Unity�е�dt
// ======================
double frameTime;

Status GetWinMaxMinXY();

Status KeyUpdate();

Status Visit_Update(insNode* pinsNode);

Status Visit_CollisionDetect(insNode* pinsNode);

Status Visit_Matrix2DCount(insNode* pinsNode);

Status BossUpdate(int level, clock_t LevelTime, float bossOccurTime);

Status Visit_DestroyObj(insNode* pinsNode);

Status Visit_DrawObj(insNode* pinsNode);

