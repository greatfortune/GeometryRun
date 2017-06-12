/**
 * Project:		GeometryRun
 * File Name:	Level4.c
 * Author:		����
 * Date:		2017-6-12
 * Purpose:		�ؿ�4
 */
#include "Level4.h"

clock_t timeStart_level4;

void Load4(void)
{
	// ��ʼ��ʱ��ϵͳ
	TimerIni(&timeStart_level4);

	printf("Level4: Load\n");
	theBaseList = NULL;
	// ���ó���
	SetConstants();
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);
	// ��ʼ��������ɶ�����ָ������
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
	// ���õ�ǰ�ؿ���һЩ����ֵ
	float BlockVel = -400.0f;
	float MonsterVel = -400.0f;
	int bossMaxHP = 5;

	stage = 1;
	stageWaves = 5 + rand() % 2;	// ��һ�ز������5~6
	currentWave = 0;
	toCreateTime = 0.0f;

	printf("Level4: Ini\n");
	// ��ȡ��ǰ�ؿ�ʱ��
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

	// ����ʵ������
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
	// ��Ϸ�߼���Ӧ����
	// =========================
	KeyUpdate();

	if (endPause)
	{
		// ���¼�������ͣ�ӳٵ�ʱ��
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
					// ÿ���׶μ��3.0s
					toCreateTime = passTime + 3.0f;
					currentWave++;
				}
				else
				{
					// ��ǰʱ�������һ�ַ�ʽ����һ���ϰ�����Ⲩ�������ӳ�2.5s������һ��
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

				// �����¸��׶α���
				stage++;
				currentWave = 0;
				// �����Ѷ�
				defaultBlockVel.x -= 20.0f;
				defaultMonsterVel.x -= 20.0f;
				defaultAIMonsterVel.x -= 20.0f;
				defaultAIMonsterVelyABS += 10.0f;
				Boss2MaxHP += 4;
				stageWaves = 5 + rand() % 3;	// �������Ϊ5~7
			}
		}

		// ���¶���
		ObjUpdate();

		// ====================
		// ��ײ���
		// ====================
		BaseListTraverse(Visit_CollisionDetect);

	}
	// =====================================
	// �������ж����2D�任����
	// =====================================
	BaseListTraverse(Visit_Matrix2DCount);
}

void Draw4(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// ������ƶ����б��е����ж���
	BaseListTraverse(Visit_DrawObj);

}

void Free4(void)
{

	printf("Level4: free\n");
	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload4(void)
{
	printf("Level4: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
