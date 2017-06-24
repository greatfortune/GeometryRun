/**
* Project:		GeometryRun
* File Name:	Block.h
* Author:		»Æ¼ÎÎ¬
* Date:		2017-6-17
*/
#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

Status BlockLoad();

Status BlockStart();

Status BlockUpdate(GameObj* pInst);

Status BlockCollision(insNode* pinsNode);

GameObj* BlockCreateAtPosWithVel(Vector2D blockPos, Vector2D blockVel);

GameObj* BlockCreateAtPos(Vector2D blockPos);

float BlockScaleGet();

Status BlockDefaultVelSet(float vx, float vy);

Status BlockDefaultVxChange(float change);
