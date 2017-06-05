#ifndef BLOCK_H
#define BLOCK_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_BLOCK 30.0f		// 障碍物尺寸
#define MOVE_MAXVELOCITY_BLOCK 5.0f	// 障碍物最大移动速度

// 障碍物默认速度
Vector2D defaultBlockVel;

Status BlockLoad();

Status BlockStart();

Status BlockUpdate(GameObj* pInst);

Status BlockCollision(insNode* pinsNode);

#endif