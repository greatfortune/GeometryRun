/**
 * Project:		Geometry Run
 * File Name:	AIMonster.h
 * Author:		����
 * Date:		2017-6-11
 * Purpose:		��Ϸ����AIMonster
 */

#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Player.h"

// ����Ĭ���ٶȣ���ؿ���أ�
extern Vector2D defaultAIMonsterVel;
extern float defaultAIMonsterVelyABS;		// �����ƶ��ٶȾ���ֵ���ɸ���

Status AIMonsterLoad();

Status AIMonsterStart();

Status AIMonsterUpdate(GameObj* pInst);

Status AIMonsterCollision(insNode* pinsNode);

GameObj* AIMonsterCreateAtPos(Vector2D aimonsterPos);

Status AIMonsterDefaultVelSet(float vx, float vy);

Status AIMonsterDefaultVxChange(float change);

Status AIMonsterDefaultVelyABSChange(float change);

Status AIMonsterDead(GameObj* theInst);
