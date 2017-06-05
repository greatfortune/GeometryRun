#ifndef BULLET_H
#define BULLET_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Boss2.h"

#define SIZE_BULLET 9.0f		// 子弹尺寸

enum bulletProperties
{
	damage = 0,
	BULLETPCount
};

// 子弹速度
Vector2D Velocity_Bullet;

Status BulletLoad();

Status BulletStart();

Status BulletUpdate(GameObj* pInst);

Status BulletCollision(insNode* pinsNode);

#endif