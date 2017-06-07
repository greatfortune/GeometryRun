#include "Pause.h"

Status PauseLoad()
{
	//AEGfxMeshStart();
	//AEGfxTriAdd(
	//	-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
	//	1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
	//	-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	//AEGfxTriAdd(
	//	1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
	//	1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
	//	-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	//CreateGameObjBase(OTYPE_PAUSE, AEGfxMeshEnd(), AEGfxTextureLoad(""), theBaseList);
	return OK;
}

Status PauseStart()
{
	isPaused = FALSE;
	endPause = FALSE;
	return OK;
}
