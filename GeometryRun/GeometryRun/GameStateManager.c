/**
 * Project:		GameStateManager
 * File Name:	GameStateManager.c
 * Author:		王晶
 * Date:		2017-4-4
 * Purpose:		游戏状态管理模块
 */

#include "System.h"
#include "GameStateList.h"
#include "Menu.h"
#include "Level0.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

void (*pLoad)(void);

void (*pIni)(void);

void (*pUpdate)(void);

void (*pDraw)(void);

void (*pFree)(void);

void (*pUnload)(void);

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void GSM_Initialize(int cur)
{
	Previous = cur;
	Current = cur;
	Next = cur;
	fprintf(fp, "GSM: Initialize\n");
}

void GSM_Update(void)
{
	switch (Current)
	{
		case GS_Menu: {
			pLoad = Load_Menu;
			pIni = Ini_Menu;
			pUpdate = Update_Menu;
			pDraw = Draw_Menu;
			pFree = Free_Menu;
			pUnload = Unload_Menu;
			break;
		}
    	case GS_L0: {
	    	pLoad = Load0;
		    pIni = Ini0;
		    pUpdate = Update0;
		    pDraw = Draw0;
		    pFree = Free0;
		    pUnload = Unload0;
		    break;
	    }
		case GS_L1: {
			pLoad = Load1;
			pIni = Ini1;
			pUpdate = Update1;
			pDraw = Draw1;
			pFree = Free1;
			pUnload = Unload1;
			break;
		}
		case GS_L2: {
			pLoad = Load2;
			pIni = Ini2;
			pUpdate = Update2;
			pDraw = Draw2;
			pFree = Free2;
			pUnload = Unload2;
			break;
		}
		case GS_L3: {
			pLoad = Load3;
			pIni = Ini3;
			pUpdate = Update3;
			pDraw = Draw3;
			pFree = Free3;
			pUnload = Unload3;
			break;
		}
	}
	fprintf(fp, "GSM: Update\n");
	printf("GSM: Update\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------
