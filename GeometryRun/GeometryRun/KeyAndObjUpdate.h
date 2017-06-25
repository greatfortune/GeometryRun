/**
* Project:		GeometryRun
* File Name:	KeyAndObjUpdate.h
* Author:		黄嘉维
* Date:
*/
#pragma once

#include "GameObjectManager.h"
#include "BackGround.h"
#include "Input.h"
#include "Player.h"
#include "Boss2.h"
#include "Pause.h"
#include "UICalculate.h"
#include "SoundSystem.h"

#define FLAG_IMPORTANTKEY 2

extern float winMaxX, winMaxY, winMinX, winMinY;
// 碰撞检测主对象，方便遍历时使用
extern GameObj *pInstForCollisionDetect;

// ======================
// 帧时间：Unity中的dt
// ======================
extern float frameTime;

Status GetWinMaxMinXY();

Status KeyUpdate();

Status ObjUpdate();

Status Visit_CollisionDetect(GameObj* pInst);

Status Visit_Matrix2DCount(GameObj* pInst);

// never used
Status BossUpdate(int level, clock_t LevelTime, float bossOccurTime);

Status Visit_DestroyObj(GameObj* pInst);

Status Visit_DrawObj(GameObj* pInst);

