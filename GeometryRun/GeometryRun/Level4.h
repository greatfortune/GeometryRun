/**
 * Project:		GeometryRun
 * File Name:	Level4.h
 * Author:		王晶
 * Date:		2017-6-12
 * Purpose:		关卡4
 */

#pragma once

#include "CreateObjectInMap.h"
#include "BackGround.h"
#include "Pause.h"
#include "Block.h"
#include "Boss2.h"
#include "Bullet.h"
#include "Monster.h"
#include "AIMonster.h"
#include "Platform.h"
#include "Player.h"
#include "SoundSystem.h"

int stage;				// 阶段
int stageWaves;			// 当前阶段障碍物波数
int currentWave;		// 当前障碍物波数
float toCreateTime;		// 下一波障碍物生成时间

void Load4(void);

void Ini4(void);

void Update4(void);

void Draw4(void);

void Free4(void);

void Unload4(void);
