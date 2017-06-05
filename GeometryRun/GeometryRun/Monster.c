#include "Monster.h"

Status MonsterLoad()
{
	// ========================
	// π÷ŒÔ
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
	CreateGameObjBase(OTYPE_MONSTER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/star.png"), theBaseList);
	return OK;
}

Status MonsterStart()
{
	return OK;
}

Status MonsterUpdate(GameObj* pInst)
{
	return OK;
}

Status MonsterCollision(insNode* pinsNode, GameObjList L)
{
	return OK;
}