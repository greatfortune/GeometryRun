#include "BackGround.h"

Status BackGroundLoad()
{
	if (Current == GS_L0)
	{
		// =======================
		// 背景
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
	else if (Current == GS_Menu)
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


		CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/Menu.png"), theBaseList);
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
	switch (Current)
	{
		case GS_L1:
			CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/level1.png"), theBaseList);
			break;
		case GS_L2:
		case GS_L3:
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
	Vector2DSet(&iniVelocity_Background, -180.0f, 0.0f);
	return OK;
}

Status BackGroundUpdate(GameObj* pInst)
{
	int click;
	if (Current == GS_Menu)
	{
		click = JudgeMousPos();
		switch (click)
		{
			case BTYPE_MENU_START:
				Next = GS_L0;
				break;
			case BTYPE_MENU_CHOOSE:
				Next = GS_L0;
				break;
			case BTYPE_MENU_HELPSTAFF:
				Next = GS_L0;
				break;
			case BTYPE_MENU_EXIT:
				Next = GS_Quit;
				break;
			default:
				break;
		}
		return OK;
	}

	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if (pInst->posCurr.x <= winMinX - winMaxX)
		pInst->posCurr.x = 0.0f;
	return OK;
}

// 开始：(120, 260)->(280, 450)
// 选择关卡：(550, 260)->(700, 450)
// help|staff：(140, 510)->(260, 660)
// Exit：(570, 510)->(690, 660)
int JudgeMousPos()
{
	switch (Current)
	{
	case GS_Menu:
		if (mousPos.y <= 450 && mousPos.y >= 260)
		{
			if (mousPos.x <= 280 && mousPos.x >= 120)
				return BTYPE_MENU_START;
			else if (mousPos.x <= 700 && mousPos.x >= 550)
				return BTYPE_MENU_CHOOSE;
			else
				return -1;
		}
		else if (mousPos.y <= 660 && mousPos.y >= 510)
		{
			if (mousPos.x <= 260 && mousPos.x >= 140)
				return BTYPE_MENU_HELPSTAFF;
			if (mousPos.x <= 690 && mousPos.x >= 570)
				return BTYPE_MENU_EXIT;
			else
				return -1;
		}
		else
			return -1;
		break;
	default:
		return -1;
	}
}

