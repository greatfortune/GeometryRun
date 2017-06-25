/**
* Project:		GeometryRun
* File Name:	Player.h
* Author:		�Ƽ�ά
* Date:		2017-6-17
*/
#pragma once
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"
#include "AddLife.h"

#define GRAVITY 620.0f	// ����
#define JUMP_VELOCITY 350.0f		// ����������Ծ�ٶ�
#define DROP_VELOCITY 500.0f		// ���ǽ����ٶ�

extern int isProtected;
// �������ñ���ʱ��ĳ���
extern int ProtectCur, MaxProtectCur;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

Status PlayerGetHurt(int hurt);

Status PlayerDead();

Status PlayerClear(insNode* pinsNode);//��������

extern Status PlayerAddLife(int life);

extern int PlayerHPGet();

extern int PlayerBulletCountGet();

extern int PlayerClearCountGet();

extern Status PlayerClearReload();

extern Vector2D PlayerPosGet();

extern float PlayerScaleGet();
