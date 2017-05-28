/* Project:		
   File Name:	Level1.c
   Author:		闷声发大财
   Date:		
   Purpose:		关卡1  */

#include "Level1.h"
#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "AEEngine.h"
#include "Input.h"
#include "GameObjectManager.h"
#include <time.h>
#include "KeyAndObjUpdate.h"

#define BLOCK_NUM 4	// 初始障碍物数量
//------------------------------------------------------------------------------
// Private Consts:

time_t time_level1;

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load1(void)
{
	printf("Level1: Load\n");
	theBaseList = NULL;


	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);
	

	// 初始化游戏对象类的实例列表

	// 创建基类的实例	

	// =======================
	// 平台
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -0.05f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -0.05f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 0.05f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -0.05f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 0.05f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 0.05f, COLOR_DEFAULT, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLATFORM, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlatForm.png"), theBaseList);

	// =======================
	// 背景
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		3.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		3.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		3.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/background.png"), theBaseList);

	// =========================
	// 主角
	// =========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLAYER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlayer.png"), theBaseList);

	// ========================
	// 障碍物
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
	CreateGameObjBase(OTYPE_BLOCK, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/theBlock.png"), theBaseList);

}

void Ini1(void)
{
	printf("Level1: Ini\n");
	int i;
	Vector2D iniPosition_Player = {-200.0f, 34.0f};
	Vector2D iniPosition_Block[BLOCK_NUM];
	Vector2D iniVelocity_Background = {-3.0f, 0.0f};
	Vector2D iniVelocity_Platform = {-3.0f, 0.0f };
	Vector2D iniVelocity_Block[BLOCK_NUM];
	iniPosition_Block[0].x = -70.0f;
	iniPosition_Block[0].y = 170.0f;
	iniPosition_Block[1].x = 120.0f;
	iniPosition_Block[1].y = 100.0f;
	iniPosition_Block[2].x = 40.0f;
	iniPosition_Block[2].y = 240.0f;
	iniPosition_Block[3].x = 80.0f;
	iniPosition_Block[3].y = 180.0f;

	iniVelocity_Block[0].x = -2.0f;
	iniVelocity_Block[0].y = 1.0f;
	iniVelocity_Block[1].x = -1.5f;
	iniVelocity_Block[1].y = -0.5f;
	iniVelocity_Block[2].x = 1.5f;
	iniVelocity_Block[2].y = -1.0f;
	iniVelocity_Block[3].x = 0.5f;
	iniVelocity_Block[3].y = 1.5f;
	

	// 对象实例化：
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, zero, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, zero, iniVelocity_Platform, 0, theBaseList, 0, NULL);
	for (i = 0; i < BLOCK_NUM; i++)
		CreateGameObj(OTYPE_BLOCK, SIZE_BLOCK, iniPosition_Block[i], iniVelocity_Block[i], 0, theBaseList, 0, NULL);

}

void Update1(void)
{
	double frameTime;

	GetWinMaxMinXY();

	// =========================
	// 游戏逻辑响应输入
	// =========================
	KeyUpdate();

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

void Draw1(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// 逐个绘制对象列表中的所有对象
	BaseListTraverse(theBaseList, Visit_DrawObj);

}

void Free1(void)
{
	printf("Level1: free\n");
	// 使用函数gameObjDestroy删除列表中的对象
	BaseListTraverse(theBaseList, Visit_DestroyObj);
}

void Unload1(void)
{
	printf("Level1: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
