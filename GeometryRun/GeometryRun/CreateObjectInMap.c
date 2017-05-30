#include "CreateObjectInMap.h"


/*
 * By WJ
 * 从上至下依次出现小怪物
 * startTime：开始时间
 */
Status CreateObjInMap0(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, 220 };
	Vector2D pos2 = { maxX, 170 };
	Vector2D pos3 = { maxX, 120 };
	Vector2D pos4 = { maxX, 70 };
	Vector2D pos5 = { maxX, 20 };
	Vector2D pos6 = { maxX, -30 };
	Vector2D pos7 = { maxX, -80 };
	Vector2D pos8 = { maxX, -130 };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.5f, OTYPE_MONSTER, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.0f, OTYPE_MONSTER, SIZE_BLOCK, pos3, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.5f, OTYPE_MONSTER, SIZE_BLOCK, pos4, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.0f, OTYPE_MONSTER, SIZE_BLOCK, pos5, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 2.5f, OTYPE_MONSTER, SIZE_BLOCK, pos6, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.0f, OTYPE_MONSTER, SIZE_BLOCK, pos7, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 3.5f, OTYPE_MONSTER, SIZE_BLOCK, pos8, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}


/*
 * By WJ
 * 连续三个障碍物（上、下、上）
 */
Status CreateObjInMap1(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + 10.0f};
	Vector2D pos2 = { maxX, -SIZE_BLOCK - 10.0f };
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 0.6f, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime + 1.2f, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
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
	Vector2D pos2 = { maxX, -SIZE_BLOCK - 10.0f };
	Vector2D pos3 = { maxX, SIZE_BLOCK + 10.0f };
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
*/
Status CreateObjInMap3(float startTime)
{
	float maxX = AEGfxGetWinMaxX();
	Vector2D pos1 = { maxX, SIZE_BLOCK + 20.0f };
	Vector2D pos2 = { maxX, -SIZE_BLOCK - 10.0f };
	CreateOneObjAtTime(startTime, OTYPE_MONSTER, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
	CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
	return OK;
}


/*
* By WYZ
* 障碍物（2个叠在一起）
*/
Status CreateObjInMap4(float startTime)
{
float maxX = AEGfxGetWinMaxX();
Vector2D pos1 = { maxX, SIZE_BLOCK + 10.0f };
Vector2D pos2 = { maxX, SIZE_BLOCK + 70.0f };
CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos1, defaultBlockVel, 0, theBaseList, 0, NULL);
CreateOneObjAtTime(startTime, OTYPE_BLOCK, SIZE_BLOCK, pos2, defaultBlockVel, 0, theBaseList, 0, NULL);
return OK;
}