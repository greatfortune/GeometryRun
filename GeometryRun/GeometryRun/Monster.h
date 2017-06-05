#ifndef MONSTER_H
#define MONSTER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_MONSTER 30.0f		// π÷ŒÔ≥ﬂ¥Á

Status MonsterLoad();

Status MonsterStart();

Status MonsterUpdate(GameObj* pInst);

Status MonsterCollision(insNode* pinsNode, GameObjList L);

#endif