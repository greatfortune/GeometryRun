#ifndef BLOCK_H
#define BLOCK_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_BLOCK 30.0f		// �ϰ���ߴ�
#define MOVE_MAXVELOCITY_BLOCK 300.0f	// �ϰ�������ƶ��ٶ�

// �ϰ���Ĭ���ٶȣ���ؿ���أ�
Vector2D defaultBlockVel;

Status BlockLoad();

Status BlockStart(float velx);

Status BlockUpdate(GameObj* pInst);

Status BlockCollision(insNode* pinsNode);

#endif