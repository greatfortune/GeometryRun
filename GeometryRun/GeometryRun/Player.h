#ifndef PLAYER_H
#define PLAYER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"

#define SIZE_HERO 30.0f			// 角色尺寸
#define GRAVITY 600.0f	// 重力
#define MOVE_VELOCITY_HERO 180.0f// 主角横向移动速度
#define JUMP_VELOCITY 300.0f		// 主角纵向移动速度
#define DROP_VELOCITY 480.0f		// 主角降落速度



// Player对象：因为是Player，所以单独声明，方便程序设计
GameObj* pHero;

// 初始坐标
Vector2D iniPosition_Player;

int MaxBulletCount, CurSupplyTime, SupplyTime, BulletCount;

AEGfxTexture* pTex_Hero;
//jumpCheck:跳跃次数，用于二级跳
int jumpCheck, dropCheck;
int isProtected, ClearUsed;
// 用于设置保护时间的长短
int ProtectCur, MaxProtectCur;
int PlayerHP, PlayerScore;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

Status PlayerGetHurt(int hurt);

Status PlayerDead();

Status PlayerClear(insNode* pinsNode);//清屏技能

Status PlayerGetScore(int score);

#endif