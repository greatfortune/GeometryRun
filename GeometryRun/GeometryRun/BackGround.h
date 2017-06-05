#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_BACKGROUND 400.0f	// 背景尺寸

// 仅在Level0中控制动画播放
GameObj* pImage;
int xcurrentFrame;
float elpasedTime;

// 初始坐标及速度
Vector2D iniPosition_Background;
Vector2D iniVelocity_Background;

Status BackGroundLoad(int level);

Status BackGroundStart();

Status BackGroundUpdate(GameObj* pInst);

#endif