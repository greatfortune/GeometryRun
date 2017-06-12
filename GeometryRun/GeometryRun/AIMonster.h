#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_AIMONSTER 30.0f		// 怪物尺寸

// 怪物默认速度（与关卡相关）
Vector2D defaultAIMonsterVel;
float defaultAIMonsterVelyABS;		// 纵轴移动速度绝对值，可更改

Status AIMonsterLoad();

Status AIMonsterStart(float velx);

Status AIMonsterUpdate(GameObj* pInst);

Status AIMonsterCollision(insNode* pinsNode);