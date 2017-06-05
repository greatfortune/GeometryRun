#include "Platform.h"

Status PlatformLoad()
{
	// =======================
	// ƽ̨
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -0.05f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -0.05f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 0.05f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -0.05f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 0.05f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 0.05f, COLOR_DEFAULT, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLATFORM, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlatForm.png"), theBaseList);
	return OK;
}

Status PlatformStart()
{
	iniPosition_Platform = zero;
	Vector2DSet(&iniVelocity_Platform, -3.0f, 0.0f);
	return OK;
}

Status PlatformUpdate(GameObj* pInst)
{
	if (pInst->posCurr.x <= winMinX)
		pInst->posCurr.x = 0.0f;
	return OK;
}
