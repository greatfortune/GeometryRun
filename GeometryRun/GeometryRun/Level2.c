/**
 * Project:		GameStateManager
 * File Name:	Level2.c
 * Author:		王晶
 * Date:		2017-4-22
 * Purpose:		关卡2
 */
/* Project:		GProj_Asteroid
File Name:	Level1.c
Author:		闷声发大财
Date:
Purpose:		关卡1  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level2.h"
#include "AEEngine.h"
#include "Input.h"
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "TimeManager.h"
#include "CreateObjectInMap.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

clock_t time_start_level2;

void Load2(void)
{
	// 初始化时间系统
	TimerIni(&time_start_level2);
	printf("Level2: Load\n");
	theBaseList = NULL;
	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);

	// 创建基类的实例	

	// =======================
	// 平台
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -0.05f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -0.05f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 0.05f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -0.05f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 0.05f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 0.05f, COLOR_PLAYER, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_PLATFORM, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlatForm.png"), theBaseList);

	// =======================
	// 背景
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		3.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		3.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		3.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/level2.png"), theBaseList);

	// =========================
	// 主角
	// =========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLAYER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlayer.png"), theBaseList);

	// ========================
	// 怪物
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/star.png"), theBaseList);

	// ========================
	// 障碍物
	// ========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_BLOCK, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/theBlock2.png"), theBaseList);
}

void Ini2(void)
{
	printf("Level2: Ini\n");
	Vector2D iniPosition_Player = { -200.0f, 40.0f };
	Vector2D iniVelocity_Background = { -3.0f, 0.0f };
	Vector2D iniVelocity_Platform = { -3.0f, 0.0f };
	Vector2D iniPosition_Block = { 10.0f, 10.0f };
	Vector2D iniVelocity_Block = { -1.0f, -1.0f };
	float iniFloat = 1.0f;
	float iniMinX = 0.0f, iniMaxX = 100.0f, iniMinY = 70.0f, iniMaxY = 500.0f, iniMinVx = -1.0f, iniMaxVx = 1.0f;
	float iniMinVy = -1.0f, iniMaxVy = 1.0f, iniMinDir = -3.0f, iniMaxDir = 3.0f;

	// 设置当前障碍物默认速度
	defaultBlockVel.x = -5.0f;
	defaultBlockVel.y = 0.0f;

	// 获取当前关卡时间
	time_start_level2 = clock();

	//数值初始化
	jumpCheck = 0;
	dropCheck = 0;

	// 对象实例化：
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, zero, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, zero, iniVelocity_Platform, 0, theBaseList, 0, NULL);
	// 分别是在3s时固定创建一个block和在5s时随机创建5个block（少了是范围外的被删了）
	//CreateOneObjAtTime(3.0f, OTYPE_BLOCK, SIZE_BLOCK, iniPosition_Block, iniVelocity_Block, iniFloat, theBaseList, 0, NULL);
	
	CreateObjInMap4(1.0f);
	CreateObjInMap3(2.0f);
	CreateObjInMap2(3.0f);
	CreateObjInMap1(6.0f);
	CreateObjInMap0(8.0f);
}

void Update2(void)
{
	double frameTime;
	Vector2D iniPosition_Block;
	Vector2D iniVelocity_Block;

	GetWinMaxMinXY();

	TimerUpdate(time_start_level2);
	
	// =========================
	// 游戏逻辑响应输入
	// =========================
	KeyUpdate();

	// ======================
	// 帧时间：Unity中的dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	// ======================
	// 帧时间：Unity中的dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	// 更新Hero外的对象位置
	BaseListTraverse(theBaseList, Visit_PositionUpdate);
	// 更新Hero的位置
	pHero->posCurr.x += frameTime * pHero->velCurr.x;
	pHero->posCurr.y += frameTime * pHero->velCurr.y;
	// Player跳起后的重力效应
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// ====================
	// 碰撞检测
	// ====================
	BaseListTraverse(theBaseList, Visit_CollisionDetect);

	// =====================================
	// 计算所有对象的2D变换矩阵
	// =====================================
	BaseListTraverse(theBaseList, Visit_Matrix2DCount);
}

void Draw2(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// 逐个绘制对象列表中的所有对象
	BaseListTraverse(theBaseList, Visit_DrawObj);

}

void Free2(void)
{
	
	printf("Level1: free\n");
	// 使用函数gameObjDestroy删除列表中的对象
	
	BaseListTraverse(theBaseList, Visit_DestroyObj);

	TimerFree();
}

void Unload2(void)
{
	printf("Level1: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
