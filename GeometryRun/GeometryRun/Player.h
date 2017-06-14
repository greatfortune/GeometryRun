#ifndef PLAYER_H
#define PLAYER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"

#define SIZE_HERO 30.0f			// ��ɫ�ߴ�
#define GRAVITY 600.0f	// ����
#define MOVE_VELOCITY_HERO 180.0f// ���Ǻ����ƶ��ٶ�
#define JUMP_VELOCITY 300.0f		// ���������ƶ��ٶ�
#define DROP_VELOCITY 480.0f		// ���ǽ����ٶ�



// Player������Ϊ��Player�����Ե�������������������
GameObj* pHero;

// ��ʼ����
Vector2D iniPosition_Player;

int MaxBulletCount, CurSupplyTime, SupplyTime, BulletCount;

AEGfxTexture* pTex_Hero;
//jumpCheck:��Ծ���������ڶ�����
int jumpCheck, dropCheck;
int isProtected, ClearUsed;
// �������ñ���ʱ��ĳ���
int ProtectCur, MaxProtectCur;
int PlayerHP, PlayerScore;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

Status PlayerGetHurt(int hurt);

Status PlayerDead();

Status PlayerClear(insNode* pinsNode);//��������

Status PlayerGetScore(int score);

#endif