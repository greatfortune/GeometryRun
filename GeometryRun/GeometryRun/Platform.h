#ifndef PLATFORM_H
#define PLATFORM_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_PLATFORM 1000.0f	// ƽ̨�ߴ�
#define PLATFORM_HEIGHT 10.0f	// ƽ̨�߶� = 0.01 * SIZE_PLATFORM

Vector2D iniPosition_Platform;
Vector2D iniVelocity_Platform;

Status PlatformLoad();

Status PlatformStart();

Status PlatformUpdate(GameObj* pInst);

#endif