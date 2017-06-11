#pragma once

/**
* Project:		Geometry Run
* File Name:	Pause.h
* Author:		Íõ¾§
* Date:			2017-6-7
* Purpose:		realize pause function
*/

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "GameStateList.h"
#include "input.h"

#define SIZE_PAUSE 40.0f	// ÔÝÍ£°´Å¥³ß´ç

int isPaused;
int endPause;
int pauseCreated;
clock_t pauseStartTime;
clock_t pauseEndTime;

Vector2D iniPosition_Pause;

GameObj *pPause;

Status PauseLoad();

Status PauseStart();