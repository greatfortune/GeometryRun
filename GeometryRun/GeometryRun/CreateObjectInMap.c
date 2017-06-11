/**
 * Project:		GeometryRun
 * File Name:	CreateObjectInMap.c
 * Author:		闷声发大财
 * Date:			2017-5-28
 * Purpose:		障碍物创建模型素材库
 */

#include "CreateObjectInMap.h"
/*
 * By WJ
 * 从上至下再至上依次出现小怪物
 * startTime：开始时间
 * 占用时间：7s
 */
Status CreateObjInMap0(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 245 };
	Vector2D pos2 = { maxX, 175 };
	Vector2D pos3 = { maxX, 105 };
	Vector2D pos4 = { maxX, 35 };
	Vector2D pos5 = { maxX, -35 };
	Vector2D pos6 = { maxX, -105 };
	Vector2D pos7 = { maxX, -175 };
	Vector2D pos8 = { maxX, -245 };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_MONSTER, pos1, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_MONSTER, SIZE_MONSTER, pos2, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.0f, OTYPE_MONSTER, SIZE_MONSTER, pos3, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.5f, OTYPE_MONSTER, SIZE_MONSTER, pos4, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.0f, OTYPE_MONSTER, SIZE_MONSTER, pos5, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.5f, OTYPE_MONSTER, SIZE_MONSTER, pos6, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.0f, OTYPE_MONSTER, SIZE_MONSTER, pos7, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.5f, OTYPE_MONSTER, SIZE_MONSTER, pos8, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.0f, OTYPE_MONSTER, SIZE_MONSTER, pos7, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.5f, OTYPE_MONSTER, SIZE_MONSTER, pos6, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.0f, OTYPE_MONSTER, SIZE_MONSTER, pos5, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.5f, OTYPE_MONSTER, SIZE_MONSTER, pos4, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.0f, OTYPE_MONSTER, SIZE_MONSTER, pos3, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.5f, OTYPE_MONSTER, SIZE_MONSTER, pos2, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 7.0f, OTYPE_MONSTER, SIZE_MONSTER, pos1, defaultMonsterVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
 * By WJ
 * 从上至下再至上依次出现障碍物
 * 占用时间：7s
 */
Status CreateObjInMap1(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 245 };
	Vector2D pos2 = { maxX, 175 };
	Vector2D pos3 = { maxX, 105 };
	Vector2D pos4 = { maxX, 35 };
	Vector2D pos5 = { maxX, -35 };
	Vector2D pos6 = { maxX, -105 };
	Vector2D pos7 = { maxX, -175 };
	Vector2D pos8 = { maxX, -245 };
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.0f, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.5f, OTYPE_BLOCK, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.0f, OTYPE_BLOCK, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.5f, OTYPE_BLOCK, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.0f, OTYPE_BLOCK, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.5f, OTYPE_BLOCK, SIZE_BLOCK, pos8, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.0f, OTYPE_BLOCK, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.5f, OTYPE_BLOCK, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.0f, OTYPE_BLOCK, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.5f, OTYPE_BLOCK, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.0f, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.5f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 7.0f, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
 * By WYZ
 * 障碍物+小怪（混搭较复杂）
 */
Status CreateObjInMap2(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + 70.0f };
	Vector2D pos2 = { maxX, -SIZE_BLOCK - PLATFORM_HEIGHT };
	Vector2D pos3 = { maxX, SIZE_BLOCK + PLATFORM_HEIGHT };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_MONSTER, pos1, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_MONSTER, SIZE_MONSTER, pos3, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.1f, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.8f, OTYPE_MONSTER, SIZE_MONSTER, pos1, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.3f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
 * By WYZ
 * 障碍物+小怪（上、下）
 * 占用时间：0s
 */
Status CreateObjInMap3(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + 20.0f };
	Vector2D pos2 = { maxX, -SIZE_BLOCK - PLATFORM_HEIGHT };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_MONSTER, pos1, defaultMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}


/*
 * By WYZ
 * 障碍物（2个叠在一起）
 * 占用时间：0s
 */
Status CreateObjInMap4(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + PLATFORM_HEIGHT };
	Vector2D pos2 = { maxX, SIZE_BLOCK + 70.0f };
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
 * By WJ
 * 连续三个障碍物（上、下、上）
 * 占用时间：1.2s
 */
Status CreateObjInMap5(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + PLATFORM_HEIGHT };
	Vector2D pos2 = { maxX, -SIZE_BLOCK - PLATFORM_HEIGHT };
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.6f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.2f, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
 * By WYZ
 * 用于二段跳之后马上倒挂教学
 * 占用时间：1.0s
 */
Status CreateObjInMap6(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + PLATFORM_HEIGHT };
	Vector2D pos2 = { maxX, SIZE_BLOCK + 70.0f };
	Vector2D pos3 = { maxX, -SIZE_BLOCK - PLATFORM_HEIGHT };
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime+1.0, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime+1.0, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
 * By WJ
 * 连续三个追踪Monster
 * 占用时间：1.2s
 */
Status CreateObjInMap7(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 200.0f };
	Vector2D pos2 = { maxX, -200.0f };
	CreateOneObjAtTime(startTime, OTYPE_AIMONSTER, SIZE_AIMONSTER, pos1, defaultAIMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.6f, OTYPE_AIMONSTER, SIZE_AIMONSTER, pos2, defaultAIMonsterVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.2f, OTYPE_AIMONSTER, SIZE_AIMONSTER, pos1, defaultAIMonsterVel, 0, theBaseList, 0, NULL);
	return OK;
}


Status CreateBossInMap_Level2(float startTime)
{
	CreateOneObjAtTime(startTime, OTYPE_BOSS2, SIZE_BOSS2, Boss2IniPos, Boss2EnterVel, 0, theBaseList, 0, NULL);
	return OK;
}
