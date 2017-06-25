/**
 * Project:		Geometry Run
 * File Name:	AIMonster.h
 * Author:		王晶
 * Date:		2017-6-11
 * Purpose:		游戏对象AIMonster
 */

#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Player.h"

// 怪物默认速度（与关卡相关）
extern Vector2D defaultAIMonsterVel;
extern float defaultAIMonsterVelyABS;		// 纵轴移动速度绝对值，可更改

Status AIMonsterLoad();

Status AIMonsterStart();

Status AIMonsterUpdate(GameObj* pInst);

Status AIMonsterCollision(insNode* pinsNode);

GameObj* AIMonsterCreateAtPos(Vector2D aimonsterPos);

Status AIMonsterDefaultVelSet(float vx, float vy);

Status AIMonsterDefaultVxChange(float change);

Status AIMonsterDefaultVelyABSChange(float change);

Status AIMonsterDead(GameObj* theInst);
