/**
* Project:		GeometryRun
* File Name:	Platform.h
* Author:		»Æ¼ÎÎ¬
* Date:		2017-6-17
*/
#pragma once

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

Status PlatformLoad();

Status PlatformStart();

Status PlatformUpdate(GameObj* pInst);

float PlatformHeightGet();
