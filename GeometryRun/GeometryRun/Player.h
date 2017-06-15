#pragma once
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"

#define SIZE_HERO 30.0f			// 角色尺寸
#define GRAVITY 600.0f	// 重力
#define MOVE_VELOCITY_HERO 180.0f// 主角横向移动速度
#define JUMP_VELOCITY 300.0f		// 主角纵向移动速度
#define DROP_VELOCITY 480.0f		// 主角降落速度

extern int isProtected, ClearUsed;
// 用于设置保护时间的长短
extern int ProtectCur, MaxProtectCur;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

Status PlayerGetHurt(int hurt);

Status PlayerDead();

Status PlayerClear(insNode* pinsNode);//清屏技能

Status PlayerGetScore(int score);

extern int PlayerHPGet();

extern int PlayerScoreGet();

extern int PlayerBulletCountGet();

extern int PlayerClearUsedGet();

extern Vector2D PlayerPosGet();
