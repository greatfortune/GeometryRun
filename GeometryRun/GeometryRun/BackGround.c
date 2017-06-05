#include "BackGround.h"

Status BackGroundLoad(int level)
{
	if (level == 0)
	{
		// =======================
		// ±³¾°
		// =======================
		AEGfxMeshStart();
		AEGfxTriAdd(
			-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
			1.0f, -1.0f, COLOR_DEFAULT, 1.0f / 12.0f, 1.0f,
			-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
		AEGfxTriAdd(
			1.0f, -1.0f, COLOR_DEFAULT, 1.0f / 12.0f, 1.0f,
			1.0f, 1.0f, COLOR_DEFAULT, 1.0f / 12.0f, 0.0f,
			-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);


		CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/level0.png"), theBaseList);
		return OK;
	}
	
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		3.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		3.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		3.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	switch (level)
	{
		case 1:
			CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/level1.png"), theBaseList);
			break;
		case 2:
			CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/level2.png"), theBaseList);
			break;
		default:
			return ERROR;
	}
	return OK;
}

Status BackGroundStart()
{
	iniPosition_Background = zero;
	Vector2DSet(&iniVelocity_Background, -3.0f, 0.0f);
	return OK;
}

Status BackGroundUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x;
	pInst->posCurr.y += pInst->velCurr.y;
	if (pInst->posCurr.x <= winMinX - winMaxX)
		pInst->posCurr.x = 0.0f;
	return OK;
}
