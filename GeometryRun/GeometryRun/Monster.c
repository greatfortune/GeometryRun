#include "Monster.h"

Status MonsterLoad()
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
	
	return OK;
}

Status MonsterStart(float velx)
{
	Vector2DSet(&defaultMonsterVel, velx, 0.0f);
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

Status MonsterCollision(insNode* pinsNode)
{
	return OK;
}