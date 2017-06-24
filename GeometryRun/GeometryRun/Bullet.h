/**
* Project:		GeometryRun
* File Name:	Bullet.h
* Author:		�Ƽ�ά
* Date:		2017-6-17
*/
#pragma once
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "Boss2.h"

Status BulletLoad();

Status BulletStart();

Status BulletUpdate(GameObj* pInst);

Status BulletCollision(insNode* pinsNode);

GameObj* BulletCreateAtPos(Vector2D bulletPos);

GameObj* BulletCreateAtPosWithVel(Vector2D bulletPos, Vector2D bulletVel);
