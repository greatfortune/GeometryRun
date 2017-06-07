/**
* Project:		GameStateManager
* File Name:	Level1.c
* Author:		wyz
* Date:		2017-6-7
* Purpose:		关卡1
*/
#include "Level1.h"

clock_t timeStart_level1;


void Load1(void)
{
	// 初始化时间系统
	TimerIni(&timeStart_level1);

	printf("Level1: Load\n");
	theBaseList = NULL;
	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);

	PlayerLoad();
	BlockLoad();
	BulletLoad();
	MonsterLoad();
	PlatformLoad();
	BackGroundLoad();
	PauseLoad();
}

void Ini1(void)
{
	printf("Level1: Ini\n");
	// 获取当前关卡时间
	timeStart_level1 = clock();

	PlayerStart();
	BlockStart();
	PlatformStart();
	BackGroundStart();
	MonsterStart();
	BulletStart();
	PauseStart();

	// 对象实例化：
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, iniPosition_Background, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, iniPosition_Platform, iniVelocity_Platform, 0, theBaseList, 0, NULL);

	CreateObjInMap4(1.0f);
	CreateObjInMap3(2.5f);
	CreateObjInMap5(4.0f);
	CreateObjInMap0(6.0f);
	CreateObjInMap6(16.0f);
	

}

void Update1(void)
{
	Vector2D iniPosition_Block;
	Vector2D iniVelocity_Block;

	GetWinMaxMinXY();

	// =========================
	// 游戏逻辑响应输入
	// =========================
	KeyUpdate();

	if (endPause)
	{
		// 重新计算因暂停延迟的时间
		timeStart_level1 += pauseEndTime - pauseStartTime;
		endPause = FALSE;
	}

	if (!isPaused)
	{
		TimerUpdate(timeStart_level1);
		// 更新对象
		ObjUpdate();

		// ====================
		// 碰撞检测
		// ====================
		BaseListTraverse(Visit_CollisionDetect);

		// =====================================
		// 计算所有对象的2D变换矩阵
		// =====================================
		BaseListTraverse(Visit_Matrix2DCount);
	}
}

void Draw1(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// 逐个绘制对象列表中的所有对象
	BaseListTraverse(Visit_DrawObj);

}

void Free1(void)
{

	printf("Level1: free\n");
	// 使用函数gameObjDestroy删除列表中的对象
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload1(void)
{
	printf("Level1: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
