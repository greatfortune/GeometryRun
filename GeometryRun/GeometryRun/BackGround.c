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
	else if (Current == GS_Menu || Current == GS_Win || Current == GS_Lose || Current == GS_Pass)
	{
		AEGfxMeshStart();
		AEGfxTriAdd(
			-1.0f, -0.75f, COLOR_DEFAULT, 0.0f, 1.0f,
			1.0f, -0.75f, COLOR_DEFAULT, 1.0f, 1.0f,
			-1.0f, 0.75f, COLOR_DEFAULT, 0.0f, 0.0f);
		AEGfxTriAdd(
			1.0f, -0.75f, COLOR_DEFAULT, 1.0f, 1.0f,
			1.0f, 0.75f, COLOR_DEFAULT, 1.0f, 0.0f,
			-1.0f, 0.75f, COLOR_DEFAULT, 0.0f, 0.0f);

		switch (Current)
		{
			case GS_Menu:
				CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/Menu.png"), theBaseList);
				break;
			case GS_Win:
				CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/win_over_2.png"), theBaseList);
				break;
			case GS_Lose:
				CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/lose1.png"), theBaseList);
				break;
			case GS_Pass:
				CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/win_pass_1.png"), theBaseList);
				break;
			default:
				return -1;
		}

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
		case GS_L4:
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
	if (Current <= GS_Pass)
	{
		int click;
		if (KeyPressed[KeyLButton] == FALSE)
			return OK;

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
			case BTYPE_PASS_NEXT:
			Next = Previous + 1;
			break;
			case BTYPE_PASS_MENU:
			Next = GS_Menu;
			break;
			case BTYPE_WIN_RESTART:
			Next = GS_Restart;
			break;
			case BTYPE_WIN_MENU:
			Next = GS_Menu;
			break;
			case BTYPE_LOSE_RESTART:
			Next = Previous;
			break;
			case BTYPE_LOSE_MENU:
			Next = GS_Menu;
			break;
			default:
			break;
		}
	}
	else
	{
		pInst->posCurr.x += pInst->velCurr.x * frameTime;
		pInst->posCurr.y += pInst->velCurr.y * frameTime;
		if (pInst->posCurr.x <= winMinX - winMaxX)
			pInst->posCurr.x = 0.0f;
	}

	return OK;
}

Status mousIsInRect(int minX, int minY, int maxX, int maxY)
{
	if (mousPos.x <= maxX && mousPos.x >= minX && mousPos.y <= maxY && mousPos.y >= minY)
		return TRUE;
	else
		return FALSE;
}

int JudgeMousPos()
{
	switch (Current)
	{
	case GS_Menu:
	{
		// Menu:
		// 开始：(120, 185)->(280, 335)
		// 选择关卡：(550, 185)->(700, 335)
		// help|staff：(140, 375)->(260, 500)
		// Exit：(570, 375)->(690, 500)
		if (mousIsInRect(120, 185, 280, 335))
			return BTYPE_MENU_START;
		else if (mousIsInRect(550, 185, 700, 335))
			return BTYPE_MENU_CHOOSE;
		else if (mousIsInRect(140, 375, 260, 500))
			return BTYPE_MENU_HELPSTAFF;
		else if (mousIsInRect(570, 375, 690, 500))
			return BTYPE_MENU_EXIT;
		else 
			return BTYPE_FALSE;
	}
	case GS_Pass:
	{
		// Pass:
		// Next: (540, 160)->(630, 255)
		// Menu: (535, 450)->(635, 550)
		if (mousIsInRect(540, 160, 630, 255))
			return BTYPE_PASS_NEXT;
		else if (mousIsInRect(535, 450, 635, 550))
			return BTYPE_PASS_MENU;
		else
			return BTYPE_FALSE;
	}

	case GS_Win:
	{
		// Win:
		// Re: (60, 150)->(155, 250)
		// Menu: (210, 150)->(300, 550)
		if (mousIsInRect(60, 150, 155, 250))
			return BTYPE_WIN_RESTART;
		else if (mousIsInRect(210, 150, 300, 550))
			return BTYPE_WIN_MENU;
		else
			return BTYPE_FALSE;
	}
	case GS_Lose:
	{
		// Lose:
		// Re: (570, 485)->(650, 560)
		// Menu: (680, 485)->(750, 560)
		if (mousIsInRect(570, 485, 650, 560))
			return BTYPE_LOSE_RESTART;
		else if (mousIsInRect(680, 485, 750, 560))
			return BTYPE_LOSE_MENU;
		else
			return BTYPE_FALSE;
	}
	default:
		return -1;
	}
}

