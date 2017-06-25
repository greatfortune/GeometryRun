/**
* Project:		GeometryRun
* File Name:	Player.h
* Author:		黄嘉维
* Date:		2017-6-17
*/
#pragma once
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"
#include "AddLife.h"

#define GRAVITY 620.0f	// 重力
#define JUMP_VELOCITY 350.0f		// 主角纵向跳跃速度
#define DROP_VELOCITY 500.0f		// 主角降落速度

extern int isProtected;
// 用于设置保护时间的长短
extern int ProtectCur, MaxProtectCur;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

Status PlayerGetHurt(int hurt);

Status PlayerDead();

Status PlayerClear(insNode* pinsNode);//清屏技能

extern Status PlayerAddLife(int life);

extern int PlayerHPGet();

extern int PlayerBulletCountGet();

extern int PlayerClearCountGet();

extern Status PlayerClearReload();

extern Vector2D PlayerPosGet();

extern float PlayerScaleGet();
