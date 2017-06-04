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
 * 占用时间：9s
 */
Status CreateObjInMap0(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 270 };
	Vector2D pos2 = { maxX, 210 };
	Vector2D pos3 = { maxX, 150 };
	Vector2D pos4 = { maxX, 90 };
	Vector2D pos5 = { maxX, 30 };
	Vector2D pos6 = { maxX, -30 };
	Vector2D pos7 = { maxX, -90 };
	Vector2D pos8 = { maxX, -150 };
	Vector2D pos9 = { maxX, -210 };
	Vector2D pos10 = { maxX, -270 };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_MONSTER, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.0f, OTYPE_MONSTER, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.5f, OTYPE_MONSTER, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.0f, OTYPE_MONSTER, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.5f, OTYPE_MONSTER, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.0f, OTYPE_MONSTER, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.5f, OTYPE_MONSTER, SIZE_BLOCK, pos8, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.0f, OTYPE_MONSTER, SIZE_BLOCK, pos9, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.5f, OTYPE_MONSTER, SIZE_BLOCK, pos10, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.0f, OTYPE_MONSTER, SIZE_BLOCK, pos9, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.5f, OTYPE_MONSTER, SIZE_BLOCK, pos8, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.0f, OTYPE_MONSTER, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.5f, OTYPE_MONSTER, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 7.0f, OTYPE_MONSTER, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 7.5f, OTYPE_MONSTER, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 8.0f, OTYPE_MONSTER, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 8.5f, OTYPE_MONSTER, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 9.0f, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}

/*
* By WJ
* 从上至下再至上依次出现障碍物
* 占用时间：9s
*/
Status CreateObjInMap1(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 270 };
	Vector2D pos2 = { maxX, 210 };
	Vector2D pos3 = { maxX, 150 };
	Vector2D pos4 = { maxX, 90 };
	Vector2D pos5 = { maxX, 30 };
	Vector2D pos6 = { maxX, -30 };
	Vector2D pos7 = { maxX, -90 };
	Vector2D pos8 = { maxX, -150 };
	Vector2D pos9 = { maxX, -210 };
	Vector2D pos10 = { maxX, -270 };
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.0f, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.5f, OTYPE_BLOCK, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.0f, OTYPE_BLOCK, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.5f, OTYPE_BLOCK, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.0f, OTYPE_BLOCK, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.5f, OTYPE_BLOCK, SIZE_BLOCK, pos8, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.0f, OTYPE_BLOCK, SIZE_BLOCK, pos9, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 4.5f, OTYPE_BLOCK, SIZE_BLOCK, pos10, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.0f, OTYPE_BLOCK, SIZE_BLOCK, pos9, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 5.5f, OTYPE_BLOCK, SIZE_BLOCK, pos8, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.0f, OTYPE_BLOCK, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 6.5f, OTYPE_BLOCK, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 7.0f, OTYPE_BLOCK, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 7.5f, OTYPE_BLOCK, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 8.0f, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 8.5f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 9.0f, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
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
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_MONSTER, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.1f, OTYPE_BLOCK, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.8f, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
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
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
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
* 连续三个小怪物（左高右低）
* 占用时间：0.4s
*/
Status CreateObjInMap6(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 100 };
	Vector2D pos2 = { maxX, 65 };
	Vector2D pos3 = { maxX, 30 };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime+0.2, OTYPE_MONSTER, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime+0.4, OTYPE_MONSTER, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}


/*
* By WYZ
* 连续三个小怪物（左低右高）
* 占用时间：0.4s
*/
Status CreateObjInMap7(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 100 };
	Vector2D pos2 = { maxX, 65 };
	Vector2D pos3 = { maxX, 30 };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.2, OTYPE_MONSTER, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.4, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}