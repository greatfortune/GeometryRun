#ifndef MONSTER_H
#define MONSTER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_MONSTER 30.0f		// ����ߴ�

// ����Ĭ���ٶȣ���ؿ���أ�
Vector2D defaultMonsterVel;

Status MonsterLoad();

Status MonsterStart(float velx);

Status MonsterUpdate(GameObj* pInst);

Status MonsterCollision(insNode* pinsNode);

#endif