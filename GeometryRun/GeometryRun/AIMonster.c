#include "AIMonster.h"
#include "Player.h"

Status AIMonsterLoad()
{
	// ========================
	// ¹ÖÎï
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
		CreateGameObjBase(OTYPE_AIMONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/DiamondMonster.png"), theBaseList);
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

Status AIMonsterStart(float velx)
{
	Vector2DSet(&defaultAIMonsterVel, velx, 0.0f);
	defaultAIMonsterVelyABS = 100.0f;
	return OK;
}

Status AIMonsterUpdate(GameObj* pInst)
{
	if (pInst->posCurr.y > pHero->posCurr.y)
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