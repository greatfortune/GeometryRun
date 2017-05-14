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

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------
//Player
#define MOVE_VELOCITY_HERO 130.0f
#define MOVE_VELOCITY_ENEMY 75.0f
#define JUMP_VELOCITY 100.0f
#define GRAVITY 100.0f

Vector2D zero = { 0.0f, 0.0f };

// Player������Ϊ��Player�����Ե�������������������
static GameObj* pHero;

static AEGfxTexture* pTex_Hero;
//jumpCheck:��Ծ���������ڶ�����
int jumpCheck = 0;


//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load1(void)
{
	printf("Level1: Load\n");
	GameObjBase* pObjBase;
	theBaseList = NULL;

	// ���õ�����Ϣ
	SetObjTypeName();
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


	CreateGameObjBase(TYPE_PLATFORM, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlatForm.png"), theBaseList);

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


	CreateGameObjBase(TYPE_BACKGROUND, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/background.png"), theBaseList);

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

	CreateGameObjBase(TYPE_PLAYER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlayer.png"), theBaseList);

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
	CreateGameObjBase(TYPE_BLOCK, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/theBlock.png"), theBaseList);

}

void Ini1(void)
{
	printf("Level1: Ini\n");
	GameObj* pObj;
	int i;
	Vector2D iniPosition_Player = { -200.0f, 34.0f };
	Vector2D iniPosition_Block[BLOCK_NUM];
	Vector2D iniVelocity_Background = { -3.0f, 0.0f };
	Vector2D iniVelocity_Platform = { -3.0f, 0.0f };
	Vector2D iniVelocity_Block[BLOCK_NUM];
	iniPosition_Block[0].x = -70.0f;
	iniPosition_Block[0].y = 170.0f;
	iniPosition_Block[1].x = 120.0f;
	iniPosition_Block[1].y = 100.0f;
	iniPosition_Block[2].x = 40.0f;
	iniPosition_Block[2].y = 240.0f;
	iniPosition_Block[3].x = 80.0f;
	iniPosition_Block[3].y = 180.0f;

	iniVelocity_Block[0].x = -2.0f;
	iniVelocity_Block[0].y = 1.0f;
	iniVelocity_Block[1].x = -1.5f;
	iniVelocity_Block[1].y = -0.5f;
	iniVelocity_Block[2].x = 1.5f;
	iniVelocity_Block[2].y = -1.0f;
	iniVelocity_Block[3].x = 0.5f;
	iniVelocity_Block[3].y = 1.5f;


	// ����ʵ������
	// ��Ҷ���ʵ����
	pHero = CreateGameObj(TYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	AE_ASSERT(pHero);
	// ��������ʵ����
	pObj = CreateGameObj(TYPE_BACKGROUND, SIZE_BACKGROUND, zero, iniVelocity_Background, 0, theBaseList, 0, NULL);
	// ƽ̨����ʵ����
	pObj = CreateGameObj(TYPE_PLATFORM, SIZE_PLATFORM, zero, iniVelocity_Platform, 0, theBaseList, 0, NULL);
	AE_ASSERT(pHero);
	// ����ʵ���� �� ��ʼ��
	for (i = 0; i < BLOCK_NUM; i++)
	{
		// ʵ����
		pObj = CreateGameObj(TYPE_BLOCK, SIZE_BLOCK, iniPosition_Block[i], iniVelocity_Block[i], 0, theBaseList, 0, NULL);
		AE_ASSERT(pObj);
	}

}

void Update1(void)
{
	unsigned long i;
	baseNode *pbasenode, *pbasenode2;
	insNode *pinsnode, *pinsnode2;
	GameObjList tlist, tlist2;
	float winMaxX, winMaxY, winMinX, winMinY;
	double frameTime;
	int deathFlag = 0;

	// ==========================================================================================
	// ��ȡ���������ߵ����꣬�����ڷ����ƶ������ţ�����ֵ�ᷢ���仯
	// ==========================================================================================
	winMaxX = AEGfxGetWinMaxX();
	winMaxY = AEGfxGetWinMaxY();
	winMinX = AEGfxGetWinMinX();
	winMinY = AEGfxGetWinMinY();

	// ======================
	// ֡ʱ�䣺Unity�е�dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	// =========================
	// ��Ϸ�߼���Ӧ����
	// =========================

	// ״̬�л�
	if (KeyPressed[KeyR] == TRUE)
	{
		Next = GS_Restart;
		return;
	}
	if (KeyPressed[KeyESC] == TRUE)
	{
		Next = GS_Quit;
		return;
	}
	if (KeyPressed[Key2] == TRUE)
	{
		Next = GS_L2;
		return;
	}

	// ����Hero��Ķ���λ��
	for (pbasenode = theBaseList->head->next; pbasenode != theBaseList->tail; pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
		{
			GameObj* pInst = &(pinsnode->gameobj);
			if (pinsnode->gameobj.flag == FLAG_INACTIVE)
				continue;
			switch (pbasenode->gameobj_base.type)
			{
			case TYPE_BACKGROUND:
			{
									pInst->posCurr.x += pInst->velCurr.x;
									pInst->posCurr.y += pInst->velCurr.y;
									if (pInst->posCurr.x <= winMinX - winMaxX)
										pInst->posCurr.x = 0.0f;
									break;
			}
			case TYPE_PLATFORM:
			{
								  pInst->posCurr.x += pInst->velCurr.x;
								  pInst->posCurr.y += pInst->velCurr.y;
								  if (pInst->posCurr.x <= winMinX)
									  pInst->posCurr.x = 0.0f;
								  break;
			}
			case TYPE_BLOCK:
			{
							   pInst->posCurr.x += pInst->velCurr.x;
							   pInst->posCurr.y += pInst->velCurr.y;
							   if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
								   GameObjDelete(pInst);
							   break;
			}
			}


		}

		if (pbasenode->gameobj_base.type == TYPE_BACKGROUND)
		{
			tlist = pbasenode->gameobj_list;
			for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
			{

			}
		}

	}



	// �������player�����ƶ� �� ��Ծ(����)
	if (KeyPressed[KeyRight] == TRUE)
	{
		pHero->velCurr.x = MOVE_VELOCITY_HERO;
	}
	else
	if (KeyPressed[KeyLeft] == TRUE)
	{
		pHero->velCurr.x = -MOVE_VELOCITY_HERO;
	}
	else
		pHero->velCurr.x = 0.f;
	if (KeyPressed[KeySpace] == TRUE)
	{

		if (jumpCheck<2)
			pHero->velCurr.y = JUMP_VELOCITY;
		jumpCheck++;
	}
	pHero->posCurr.x += frameTime * pHero->velCurr.x;
	pHero->posCurr.y += frameTime * pHero->velCurr.y;
	// Player����������ЧӦ
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// ====================
	// ��ײ���
	// ====================
	for (pbasenode = theBaseList->head->next; (pbasenode != theBaseList->tail) && (deathFlag == 0); pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; (pinsnode != tlist->tail) && (deathFlag == 0); pinsnode = pinsnode->next)
		{
			GameObj* pInst = pHero;
			GameObj* pInstOther = &(pinsnode->gameobj);

			// ������ǻ����
			if (pInst->flag == FLAG_INACTIVE)
				continue;

			// Player �� background / block ����ײ���
			if (pInst->pObject->type == TYPE_PLAYER)
			{
				for (pbasenode2 = theBaseList->head->next; (pbasenode2 != theBaseList->tail) && (deathFlag == 0); pbasenode2 = pbasenode2->next)
				{
					tlist2 = pbasenode2->gameobj_list;
					for (pinsnode2 = tlist2->head->next; (pinsnode2 != tlist2->tail) && (deathFlag == 0); pinsnode2 = pinsnode2->next)
					{
						pInstOther = &(pinsnode2->gameobj);

						// �����ǻ���������
						if ((pInstOther->flag & FLAG_ACTIVE) == 0 || (pInstOther->pObject->type == TYPE_PLAYER))
							continue;

						// Player vs. Block
						if (pInstOther->pObject->type == TYPE_BLOCK)
						{
							// ��ײ���
							if (StaticCircleToStaticCircle(&(pInst->posCurr), pInst->scale, &(pInstOther->posCurr), pInstOther->scale))
							{
								// װ��BLOCK����
								// ���¿�ʼ�ؿ�
								Next = GS_Restart;
								deathFlag = 1;
								printf("\n Collision with the Block: Pos(%.1f, %.1f)\n Restart\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
								break;
							}
							continue;
						}

						// Player vs. Platform
						if (pInstOther->pObject->type == TYPE_PLATFORM)
						{
							//�Ƿ���ƽ̨��
							if ((pInst->posCurr.y) <= pInst->scale + 10.0f)
							{
								jumpCheck = 0;
								pInst->velCurr.y = 0.0f;
								pInst->posCurr.y = pInst->scale + 10.0f;
							}
						}
					}
				}
			}
		}
	}

	// =====================================
	// �������ж����2D�任����
	// =====================================
	for (pbasenode = theBaseList->head->next; pbasenode != theBaseList->tail; pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
		{
			GameObj* pInst = &(pinsnode->gameobj);
			Matrix2D		 trans, rot, scale;

			// ������ǻ����
			if ((pInst->flag & FLAG_ACTIVE) == 0)
				continue;

			// ���ž���
			Matrix2DScale(&scale, pInst->scale, pInst->scale);
			// ��ת����
			Matrix2DRotDeg(&rot, pInst->dirCurr);
			// ƽ�ƾ���
			Matrix2DTranslate(&trans, pInst->posCurr.x, pInst->posCurr.y);
			// ����ȷ��˳����������3�������γ�2ά�任����
			Matrix2DConcat(&(pInst->transform), &trans, &rot);
			Matrix2DConcat(&(pInst->transform), &(pInst->transform), &scale);
		}
	}
}

void Draw1(void)
{
	baseNode *pbasenode;
	insNode *pinsnode;
	GameObjList tlist;
	char strBuffer[1024];
	unsigned long i;
	double frameTime;

	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// ������ƶ����б��е����ж���
	for (pbasenode = theBaseList->head->next; pbasenode != theBaseList->tail; pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
		{
			GameObj* pInst = &(pinsnode->gameobj);

			// �����ǻ����
			if ((pInst->flag & FLAG_ACTIVE) == 0)
				continue;
			// ��������
			AEGfxTextureSet(pInst->pObject->pTex, 0, 0);
			// ���ö����2D�任����ʹ�ú�����AEGfxSetTransform
			AEGfxSetTransform(pInst->transform.m);
			// ���Ƶ�ǰ����ʹ�ú�����AEGfxMeshDraw
			AEGfxMeshDraw(pInst->pObject->pMesh, AE_GFX_MDM_TRIANGLES);
		}
	}
}

void Free1(void)
{
	printf("Level1: free\n");
	int i = 0;
	baseNode *pbasenode;
	insNode *pinsnode;
	GameObjList tlist;

	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	for (pbasenode = theBaseList->head->next; pbasenode != theBaseList->tail; pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
		{
			GameObj* pInst = &(pinsnode->gameobj);
			if (pInst->flag == FLAG_ACTIVE)
				GameObjDelete(pInst);
		}
	}
}

void Unload1(void)
{
	printf("Level1: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
