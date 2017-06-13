#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Boss2.h"
#include "Player.h"
#include <math.h>

#define SIZE_BOSSBULLET 12.0f		// �ӵ��ߴ�

// �ӵ��ٶ�
float Velocity_BossBulletABS;
Vector2D iniBossBulletPos;
float BossBulletDir;
Vector2D Velocity_BossBullet;

Status BossBulletLoad();

Status BossBulletStart(float BossBulletVelABS);

Status BossBulletIni();

Status BossBulletUpdate(GameObj* pInst);

Status BossBulletCollision(insNode* pinsNode);
