/**
 * Project:		GeometryRun
 * File Name:	Level4.c
 * Author:		王晶
 * Date:		2017-6-12
 * Purpose:		关卡4
 */
#include "Level4.h"

clock_t timeStart_level4;

void Load4(void)
{
	// 初始化时间系统
	TimerIni(&timeStart_level4);

	printf("Level4: Load\n");
	theBaseList = NULL;
	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);
	// 初始化随机生成对象函数指针数组
	IniCreateRandomArrays();

	PlayerLoad();
	BlockLoad();
	BulletLoad();
	MonsterLoad();
	AIMonsterLoad();
	PlatformLoad();
	Boss2Load();
	BackGroundLoad();
	PauseLoad();
}

void Ini4(void)
{
	// 设置当前关卡的一些属性值
	float BlockVel = -400.0f;
	float MonsterVel = -400.0f;
	int bossMaxHP = 5;

	stage = 1;
	stageWaves = 5 + rand() % 2;	// 第一关波数随机5~6
	currentWave = 0;
	toCreateTime = 0.0f;

	printf("Level4: Ini\n");
	// 获取当前关卡时间
	timeStart_level4 = clock();

	PlayerStart();
	BlockStart(BlockVel);
	PlatformStart();
	BackGroundStart();
	MonsterStart(MonsterVel);
	AIMonsterStart(MonsterVel);
	BulletStart();
	Boss2Start(bossMaxHP);
	PauseStart();

	// 对象实例化：
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, iniPosition_Background, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, iniPosition_Platform, iniVelocity_Platform, 0, theBaseList, 0, NULL);
}

void Update4(void)
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
		timeStart_level4 += pauseEndTime - pauseStartTime;
		endPause = FALSE;
		GameObjDelete(pPause);
		pauseCreated = FALSE;
	}

	if (isPaused)
	{
		if (!pauseCreated)
		{
			pPause = CreateGameObj(OTYPE_PAUSE, SIZE_PAUSE, iniPosition_Pause, zero, 0, theBaseList, 0, NULL);
			pauseCreated = TRUE;
		}
	}
	else
	{
		TimerUpdate(timeStart_level4);

		if (!Boss2Alive && passTime >= toCreateTime)
		{
			if (currentWave <= stageWaves)
			{
				if (currentWave == 0)
				{
					// 每个阶段间隔3.0s
					toCreateTime = passTime + 3.0f;
					currentWave++;
				}
				else
				{
					// 当前时刻随机用一种方式生成一波障碍物，并这波结束后延迟2.5s生成下一波
					int createMethod = rand() % CreateMethods;
					toCreateTime =	passTime + (CreateObjInMapRamdom[createMethod])(passTime) + 2.5f;
					currentWave++;
				}
			}
			else
			{
				Boss2Alive = TRUE;
				pBoss2 = CreateGameObj(OTYPE_BOSS2, SIZE_BOSS2, Boss2IniPos, Boss2EnterVel, 0, theBaseList, 0, NULL);
				printf("\nBossHP : %d\n", Boss2HP);
				printf("Boss vx : %f, vy: %f\n", Boss2EnterVel.x, Boss2EnterVel.y);

				// 更新下个阶段变量
				stage++;
				currentWave = 0;
				// 增加难度
				defaultBlockVel.x -= 20.0f;
				defaultMonsterVel.x -= 20.0f;
				defaultAIMonsterVel.x -= 20.0f;
				defaultAIMonsterVelyABS += 10.0f;
				Boss2MaxHP += 4;
				stageWaves = 5 + rand() % 3;	// 波数随机为5~7
			}
		}

		// 更新对象
		ObjUpdate();

		// ====================
		// 碰撞检测
		// ====================
		BaseListTraverse(Visit_CollisionDetect);

	}
	// =====================================
	// 计算所有对象的2D变换矩阵
	// =====================================
	BaseListTraverse(Visit_Matrix2DCount);
}

void Draw4(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// 逐个绘制对象列表中的所有对象
	BaseListTraverse(Visit_DrawObj);

}

void Free4(void)
{

	printf("Level4: free\n");
	// 使用函数gameObjDestroy删除列表中的对象
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload4(void)
{
	printf("Level4: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
