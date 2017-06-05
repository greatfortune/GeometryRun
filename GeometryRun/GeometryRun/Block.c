#include "Block.h"

Status BlockLoad()
{
	// ========================
	// ’œ∞≠ŒÔ
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
	CreateGameObjBase(OTYPE_BLOCK, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/theBlock2.png"), theBaseList);
	return OK;
}

Status BlockStart()
{
	Vector2DSet(&defaultBlockVel, -5.0f, 0.0f);
	return OK;
}

Status BlockUpdate(GameObj* pInst)
{
	return OK;
}

Status BlockCollision(insNode* pinsNode, GameObjList L)
{
	return OK;
}

