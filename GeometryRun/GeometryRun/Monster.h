#ifndef MONSTER_H
#define MONSTER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_MONSTER 30.0f		// 怪物尺寸

// 怪物默认速度（与关卡相关）
Vector2D defaultMonsterVel;

Status MonsterLoad();

Status MonsterStart(float velx);

Status MonsterUpdate(GameObj* pInst);

Status MonsterCollision(insNode* pinsNode);

#endif