/* Project:		
   File Name:	Level1.c
   Author:		闷声发大财
   Date:		
   Purpose:		关卡1  */

#include "Level1.h"

#define BLOCK_NUM 4	// 初始障碍物数量

clock_t timeStart_level1;


void Load1(void)
{
	printf("Level1: Load\n");
	theBaseList = NULL;

	// 获取当前关卡时间
	timeStart_level1 = clock();

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

}

void Ini1(void)
{
	printf("Level1: Ini\n");
	int i;

	PlayerStart();
	BlockStart();
	PlatformStart();
	BackGroundStart();
	MonsterStart();
	BulletStart();

	Vector2D iniPosition_Block[BLOCK_NUM];
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
		CreateGameObj(OTYPE_MONSTER, SIZE_BLOCK, iniPosition_Block[i], iniVelocity_Block[i], 0, theBaseList, 0, NULL);

}

void Update1(void)
{
	GetWinMaxMinXY();

	// =========================
	// 游戏逻辑响应输入
	// =========================
	KeyUpdate();

	// 更新对象位置及属性
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
}

void Unload1(void)
{
	printf("Level1: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
