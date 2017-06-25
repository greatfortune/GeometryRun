/**
 * Project:		GeometryRun
 * File Name:	Monster.c
 * Author:		黄嘉维
 * Date:		2017-6-2
 */
#include "Monster.h"

// 怪物默认速度（与关卡相关）
static Vector2D defaultMonsterVel;

static float defaultMonsterScale;
static int boomTime;
static Property MonsterBoomPro[1];

Status MonsterLoad()
{
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
	switch (Current)
	{
	case GS_L1:
		CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/TriangleMonster.png"), theBaseList);
		break;
	case GS_L2:
		CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/StarMonster.png"), theBaseList);
		break;
	case GS_L3:
		CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/DiamondMonster.png"), theBaseList);
		break;
	case GS_L4:
		CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/StarMonster.png"), theBaseList);
		break;
	}
	// ========================
	// 爆炸效果1
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
	switch (Current)
	{
		case GS_L1:
			CreateGameObjBase(OTYPE_BOOM1, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_1_Blue.png"), theBaseList);
			break;
		case GS_L2:
			CreateGameObjBase(OTYPE_BOOM1, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_1_Orange.png"), theBaseList);
			break;
		case GS_L3:
			CreateGameObjBase(OTYPE_BOOM1, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_1_Yellow.png"), theBaseList);
			break;
		case GS_L4:
			CreateGameObjBase(OTYPE_BOOM1, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_1_Blue.png"), theBaseList);
			break;
	}
	// ========================
	// 爆炸效果2
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
	switch (Current)
	{
		case GS_L1:
			CreateGameObjBase(OTYPE_BOOM2, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_Blue.png"), theBaseList);
			break;
		case GS_L2:
			CreateGameObjBase(OTYPE_BOOM2, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_Orange.png"), theBaseList);
			break;
		case GS_L3:
			CreateGameObjBase(OTYPE_BOOM2, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_Yellow.png"), theBaseList);
			break;
		case GS_L4:
			CreateGameObjBase(OTYPE_BOOM2, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/Boom_Blue.png"), theBaseList);
			break;
	}
	return OK;
}

Status MonsterStart()
{
	MonsterBoomPro[0].value = 0;
	strcpy(MonsterBoomPro[0].name, "boomtime");
	defaultMonsterScale = 30.0f;
	boomTime = 0;
	Vector2DSet(&defaultMonsterVel, -300.0f, 0.0f);
	return OK;
}

Status MonsterUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status BoomUpdate(GameObj* pInst)
{
	pInst->properties[0].value++;
	if (pInst->properties[0].value == 25)
		GameObjDelete(pInst);
	return OK;
}

Status MonsterCollision(insNode* pinsNode)
{
	return OK;
}

GameObj* MonsterCreateAtPosWithVel(Vector2D monsterPos, Vector2D monsterVel)
{
	return CreateGameObj(OTYPE_MONSTER, defaultMonsterScale, monsterPos, monsterVel, 0, theBaseList, 0, NULL);
}

GameObj* MonsterCreateAtPos(Vector2D monsterPos)
{
	return CreateGameObj(OTYPE_MONSTER, defaultMonsterScale, monsterPos, defaultMonsterVel, 0, theBaseList, 0, NULL);
}

float MonsterScaleGet()
{
	return defaultMonsterScale;
}

Status MonsterDefaultVelSet(float vx, float vy)
{
	Vector2DSet(&defaultMonsterVel, vx, vy);
	return OK;
}

Status MonsterDefaultVxChange(float change)
{
	defaultMonsterVel.x += change;
	return OK;
}

Status MonsterDead(GameObj* theInst)
{
	GameObj *boom1, *boom2;
	CreateOneObjAtTime(passTime + 0.1f, OTYPE_BOOM1, defaultMonsterScale * 2, theInst->posCurr, theInst->velCurr, 0.0f, theBaseList, 1, MonsterBoomPro, &boom1);
	CreateOneObjAtTime(passTime + 0.5f, OTYPE_BOOM2, defaultMonsterScale * 2, theInst->posCurr, theInst->velCurr, 0.0f, theBaseList, 1, MonsterBoomPro, &boom2);
	GameObjDelete(theInst);
	return OK;
}
