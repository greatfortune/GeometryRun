#include "Pause.h"

/**
* Project:		Geometry Run
* File Name:	Pause.c
* Author:		Íõ¾§
* Date:			2017-6-7
* Purpose:		realize pause function
*/


Status PauseLoad()
{
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_PAUSE, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/pauseButton.png"), theBaseList);
	return OK;
}

Status PauseStart()
{
	pPause = NULL;
	isPaused = FALSE;
	endPause = FALSE;
	pauseCreated = FALSE;
	Vector2DSet(&iniPosition_Pause, 0.0f, 150.0f);
	return OK;
}
