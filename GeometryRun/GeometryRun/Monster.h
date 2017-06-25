/**
* Project:		GeometryRun
* File Name:	Monster.h
* Author:		»Æ¼ÎÎ¬
* Date:		2017-6-4
*/
#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "TimeManager.h"

Status MonsterLoad();

Status MonsterStart();

Status MonsterUpdate(GameObj* pInst);

Status BoomUpdate(GameObj* pInst);

Status MonsterCollision(insNode* pinsNode);

GameObj* MonsterCreateAtPosWithVel(Vector2D monsterPos, Vector2D monsterVel);

GameObj* MonsterCreateAtPos(Vector2D monsterPos);

float MonsterScaleGet();

Status MonsterDefaultVelSet(float vx, float vy);

Status MonsterDefaultVxChange(float change);

Status MonsterDead(GameObj* theInst);
