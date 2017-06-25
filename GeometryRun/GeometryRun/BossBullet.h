/*
* Project:		GeometryRun
* File Name:	BossBullet.h
* Author:		»Æ½§Ë®
* Date:		2017-6-17
*/
#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Boss2.h"
#include "Player.h"
#include <math.h>


Status BossBulletLoad();

Status BossBulletStart();

Status BossBulletUpdate(GameObj* pInst);

Status BossBulletCollision(GameObj* pInst);

GameObj* BossBulletCreateAtDefaultPosWithDefaultVel();

Status BossBulletDefaultBossBulletVelyABSSet(float vel);

Status BossBulletDefaultVelyABSChange(float change);
