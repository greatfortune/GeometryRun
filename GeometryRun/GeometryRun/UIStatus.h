#ifndef UISTATUS_H
#define UISTATUS_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "GameStateList.h"
#include "Player.h"

#define SIZE_UISTATUS 400.0f	// UIStatus尺寸
#define SIZE_NUMBER 30.0f	// UINumber尺寸
#define SIZE_SCORE 3		// 显示的分数的位数

enum {
	STYPE_LEVEL,
	STYPE_UNLIMITED,
	STYPE_COUNT
};

GameObj *pUINumber_HP, *pUINumber_Bullet, *pUINumber_Score[3];

Vector2D UIStatusPos;
Vector2D UINumberPos_Level_HP, UINumberPos_Level_Bullet;
Vector2D UINumberPos_Unlimited_HP, UINumberPos_Unlimited_Bullet, UINumberPos_Unlimited_Score[3];

float iniY, HP_Level_iniX, Bullet_Level_iniX, offX;
float HP_Unlimited_iniX, Bullet_Unlimited_iniX, Score_Unlimited_iniX;
int UIScore[SIZE_SCORE];


Status UIStatusLoad();

Status UIStatusStart();

Status UIStatusUpdate();

#endif