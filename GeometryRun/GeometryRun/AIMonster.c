#include "AIMonster.h"
#include "Player.h"

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
	CreateGameObjBase(OTYPE_AIMONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/star.png"), theBaseList);
	// 待更新新的AImonster贴图
	return OK;
}

Status AIMonsterStart(float velx)
{
	Vector2DSet(&defaultAIMonsterVel, velx, 0.0f);
	return OK;
}

Status AIMonsterUpdate(GameObj* pInst)
{
	if (pInst->posCurr.y > pHero->posCurr.y)
		pInst->velCurr.y = -100.0f;
	else
		pInst->velCurr.y = 100.0f;

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