/**
 * Project:		GameStateManager
 * File Name:	Level2.c
 * Author:		����
 * Date:		2017-4-22
 * Purpose:		�ؿ�2
 */
/* Project:		GProj_Asteroid
File Name:	Level1.c
Author:		���������
Date:
Purpose:		�ؿ�1  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level2.h"
#include "AEEngine.h"
#include "Input.h"
#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load2(void)
{
	srand(time(0));
	printf("Level2: Load\n");
	theBaseList = NULL;

	// ���ó���
	SetConstants();
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);

	// ��ʼ����Ϸ�������ʵ���б�

	// ���������ʵ��	

	// =======================
	// ƽ̨
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -0.05f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -0.05f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 0.05f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -0.05f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 0.05f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 0.05f, COLOR_PLAYER, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_PLATFORM, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlatForm.png"), theBaseList);

	// =======================
	// ����
	// =======================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		3.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		3.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		3.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);


	CreateGameObjBase(OTYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/background.png"), theBaseList);

	// =========================
	// ����
	// =========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLAYER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlayer.png"), theBaseList);

	// ========================
	// �ϰ���
	// ========================

	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_PLAYER, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_PLAYER, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_PLAYER, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_PLAYER, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_BLOCK, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/theBlock2.png"), theBaseList);

}

void Ini2(void)
{
	printf("Level2: Ini\n");
	Vector2D iniPosition_Player = { -200.0f, 34.0f };
	Vector2D iniVelocity_Background = { -3.0f, 0.0f };
	Vector2D iniVelocity_Platform = { -3.0f, 0.0f };

	// ����ʵ������
	pHero = CreateGameObj(OTYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, zero, iniVelocity_Background, 0, theBaseList, 0, NULL);
	CreateGameObj(OTYPE_PLATFORM, SIZE_PLATFORM, zero, iniVelocity_Platform, 0, theBaseList, 0, NULL);

}

void Update2(void)
{
	double frameTime;
	Vector2D iniPosition_Block;
	Vector2D iniVelocity_Block;

	GetWinMaxMinXY();


	// =========================
	// ��Ϸ�߼���Ӧ����
	// =========================
	KeyUpdate();

	// ======================
	// ֡ʱ�䣺Unity�е�dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	
	static int counter = 0, counterMax = 100;


	// ======================
	// ֡ʱ�䣺Unity�е�dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	counter += 1;
	if (counter == counterMax)
	{
		iniPosition_Block.x = (float)(rand() % (int)(winMaxX - winMinX)) * 0.5 + 0.5 * (winMaxX + winMinX);
		iniPosition_Block.y = (float)(rand() % (int)(winMaxY - winMinY)) * 0.5;
		iniVelocity_Block.x = (float)(rand() % (int)MOVE_MAXVELOCITY_BLOCK) * -1.0f;
		iniVelocity_Block.y = (float)(rand() % (int)MOVE_MAXVELOCITY_BLOCK) * -1.0f;
		CreateGameObj(OTYPE_BLOCK, SIZE_BLOCK, iniPosition_Block, iniVelocity_Block, 0, theBaseList, 0, NULL);
		counter = 0;
	}
	// ����Hero��Ķ���λ��
	BaseListTraverse(theBaseList, Visit_PositionUpdate);
	// ����Hero��λ��
	pHero->posCurr.x += frameTime * pHero->velCurr.x;
	pHero->posCurr.y += frameTime * pHero->velCurr.y;
	// Player����������ЧӦ
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// ====================
	// ��ײ���
	// ====================
	BaseListTraverse(theBaseList, Visit_CollisionDetect);

	// =====================================
	// �������ж����2D�任����
	// =====================================
	BaseListTraverse(theBaseList, Visit_Matrix2DCount);
}

void Draw2(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// ������ƶ����б��е����ж���
	BaseListTraverse(theBaseList, Visit_DrawObj);

}

void Free2(void)
{
	printf("Level1: free\n");
	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	BaseListTraverse(theBaseList, Visit_DestroyObj);
}

void Unload2(void)
{
	printf("Level1: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
