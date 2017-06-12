#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_AIMONSTER 30.0f		// ����ߴ�

// ����Ĭ���ٶȣ���ؿ���أ�
Vector2D defaultAIMonsterVel;
float defaultAIMonsterVelyABS;		// �����ƶ��ٶȾ���ֵ���ɸ���

Status AIMonsterLoad();

Status AIMonsterStart(float velx);

Status AIMonsterUpdate(GameObj* pInst);

Status AIMonsterCollision(insNode* pinsNode);