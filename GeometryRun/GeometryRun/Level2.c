/**
 * Project:		GameStateManager
 * File Name:	Level2.c
 * Author:		王晶
 * Date:		2017-4-22
 * Purpose:		关卡2
 */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Input.h"
#include "Level2.h"
#include "AEEngine.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Structures:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Variables:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Private Variables:
//------------------------------------------------------------------------------
static AEGfxVertexList*	pMesh2;				// 对象2的网格(mesh)模型
static float obj2X, obj2Y;		// 对象2的位置

//------------------------------------------------------------------------------
// Private Function Declarations:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	// 开始添加对象2
	AEGfxMeshStart();
	AEGfxTriAdd(
		-25.5f, -25.5f, 0xFFFF0000, 0.0f, 0.0f,
		25.5f, 0.0f, 0x00FF0000, 0.0f, 0.0f,
		-25.5f, 25.5f, 0xFFFFFF00, 0.0f, 0.0f);
	pMesh2 = AEGfxMeshEnd();
	AE_ASSERT_MESG(pMesh2, "Failed to create mesh 2!!");

	// 签到
	fprintf(fp, "Level2:Load\n");
}

void Ini2(void)
{
	// 对象2的初始位置
	obj2X = 0.0f;
	obj2Y = 0.0f;

	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);   // 背景色RGB
	AEGfxSetBlendMode(AE_GFX_BM_BLEND);

	// 签到
	fprintf(fp, "Level2:Initialize\n");
}

void Update2(void)
{
	// 状态切换
	if (KeyPressed[KeyR])
		Next = GS_Restart;
	if (KeyPressed[KeyESC])
		Next = GS_Quit;
	if (KeyPressed[Key1])
		Next = GS_L1;

	// 输入重置
	Input_Initialize();

	// 签到
	fprintf(fp, "Level2:Update\n");
}

void Draw2(void)
{
	// 画对象2
	AEGfxSetRenderMode(AE_GFX_RM_COLOR);
	AEGfxSetPosition(obj2X, obj2Y);
	AEGfxTextureSet(NULL, 0, 0);
	AEGfxSetTransparency(2);
	AEGfxSetBlendColor(0.0f, 0.0f, 0.0, 0.0f);
	AEGfxMeshDraw(pMesh2, AE_GFX_MDM_TRIANGLES);

	// 签到
	fprintf(fp, "Level2:Draw\n");
}

void Free2(void)
{
	// 签到
	fprintf(fp, "Level2:Free\n");
}

void Unload2(void)
{
	AEGfxMeshFree(pMesh2);		// 注销创建的对象

								// 签到
	fprintf(fp, "Level2:Unload\n");
}

//------------------------------------------------------------------------------
// Private Functions:
//------------------------------------------------------------------------------