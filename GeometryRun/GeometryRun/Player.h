#ifndef PLAYER_H
#define PLAYER_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Bullet.h"
#include "Platform.h"

#define SIZE_HERO 30.0f			// 角色尺寸
#define GRAVITY 10.0f	// 重力
#define MOVE_VELOCITY_HERO 3.0f// 主角横向移动速度
#define JUMP_VELOCITY 5.0f		// 主角纵向移动速度
#define DROP_VELOCITY 8.0f		// 主角降落速度



// Player对象：因为是Player，所以单独声明，方便程序设计
GameObj* pHero;

// 初始坐标
Vector2D iniPosition_Player;

AEGfxTexture* pTex_Hero;
//jumpCheck:跳跃次数，用于二级跳
int jumpCheck, dropCheck;

Status PlayerLoad();

Status PlayerStart();

Status PlayerUpdate(GameObj* pInst);

Status PlayerCollision(insNode* pinsNode);

#endif