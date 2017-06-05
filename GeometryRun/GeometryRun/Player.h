#ifndef PLAYER_H
#define PLAYER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"

#define SIZE_HERO 30.0f			// ��ɫ�ߴ�
#define GRAVITY 10.0f	// ����
#define MOVE_VELOCITY_HERO 3.0f// ���Ǻ����ƶ��ٶ�
#define JUMP_VELOCITY 5.0f		// ���������ƶ��ٶ�
#define DROP_VELOCITY 8.0f		// ���ǽ����ٶ�



// Player������Ϊ��Player�����Ե�������������������
GameObj* pHero;

// ��ʼ����
Vector2D iniPosition_Player;

AEGfxTexture* pTex_Hero;
//jumpCheck:��Ծ���������ڶ�����
int jumpCheck, dropCheck;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

#endif