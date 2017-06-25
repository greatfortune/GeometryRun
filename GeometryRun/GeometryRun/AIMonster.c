#include "AIMonster.h"

#define MAXBOOMCOUNT 10

// 怪物默认速度（与关卡相关）
Vector2D defaultAIMonsterVel;
float defaultAIMonsterVelyABS;		// 纵轴移动速度绝对值，可更改
static float defaultAIMonsterScale;
static int boomTime;
static Property MonsterBoomPro[1];

Status AIMonsterLoad()
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
	switch(Current)
	{
	case GS_L2:
		CreateGameObjBase(OTYPE_AIMONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/StarAIMonster.png"), theBaseList);
		break;
	case GS_L3:
		CreateGameObjBase(OTYPE_AIMONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/DiamondAIMonster.png"), theBaseList);
		break;
	case GS_L4:
		CreateGameObjBase(OTYPE_AIMONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/StarAIMonster.png"), theBaseList);
		break;
	default:
		CreateGameObjBase(OTYPE_AIMONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/StarAIMonster.png"), theBaseList);
		break;
	}
	
	return OK;
}

Status AIMonsterStart()
{
	MonsterBoomPro[0].value = 0;
	strcpy(MonsterBoomPro[0].name, "boomtime");
	boomTime = 0;
	Vector2DSet(&defaultAIMonsterVel, -10.0f, 0.0f);
	defaultAIMonsterVelyABS = 100.0f;
	defaultAIMonsterScale = 30.0f;
	return OK;
}

Status AIMonsterUpdate(GameObj* pInst)
{
	Vector2D CurPlayerPos = PlayerPosGet();
	if (pInst->posCurr.y > CurPlayerPos.y)
		pInst->velCurr.y = -1 * defaultAIMonsterVelyABS;
	else
		pInst->velCurr.y = defaultAIMonsterVelyABS;

	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status AIMonsterCollision(insNode* pinsNode)
{
	return OK;
}

GameObj* AIMonsterCreateAtPos(Vector2D aimonsterPos)
{
	return CreateGameObj(OTYPE_AIMONSTER, defaultAIMonsterScale, aimonsterPos, defaultAIMonsterVel, 0, theBaseList, 0, NULL);
}

Status AIMonsterDefaultVelSet(float vx, float vy)
{
	Vector2DSet(&defaultAIMonsterVel, vx, vy);
	return OK;
}

Status AIMonsterDefaultVelyABSChange(float change)
{
	defaultAIMonsterVelyABS += change;
	return OK;
}

Status AIMonsterDefaultVxChange(float change)
{
	defaultAIMonsterVel.x += change;
	return OK;
}

Status AIMonsterDead(GameObj* theInst)
{
	GameObj *boom1, *boom2;
	CreateOneObjAtTime(passTime + 0.1f, OTYPE_BOOM1, defaultAIMonsterScale * 2, theInst->posCurr, theInst->velCurr, 0.0f, theBaseList, 1, MonsterBoomPro, &boom1);
	CreateOneObjAtTime(passTime + 0.5f, OTYPE_BOOM2, defaultAIMonsterScale * 2, theInst->posCurr, theInst->velCurr, 0.0f, theBaseList, 1, MonsterBoomPro, &boom2);
	GameObjDelete(theInst);
	return OK;
}
