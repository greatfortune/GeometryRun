/* Project:		
   File Name:	Level1.c
   Author:		闷声发大财
   Date:		
   Purpose:		关卡1  */

#include <stdio.h>
#include "GameStateList.h"
#include "System.h"
#include "Level1.h"
#include "AEEngine.h"
#include "Input.h"
#include "GameObjectManager.h"

//------------------------------------------------------------------------------
// Private Consts:
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Public Functions:
//------------------------------------------------------------------------------

void Load1(void)
{
	printf("Level1: Load\n");
	GameObjBase* pObjBase;
	theBaseList = NULL;

	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);

	// 初始化游戏对象类的实例列表

	// 创建基类的实例	

	// =======================
	// 平台
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
	// 背景
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
	// 主角
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
	// 障碍物
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
	Vector2D iniPosition_Player = {-200.0f, 34.0f};
	Vector2D iniPosition_Block[BLOCK_NUM];
	Vector2D iniVelocity_Background = {-3.0f, 0.0f};
	Vector2D iniVelocity_Platform = {-3.0f, 0.0f };
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
	

	// 对象实例化：
	// 玩家对象实例化
	pHero = CreateGameObj(TYPE_PLAYER, SIZE_HERO, iniPosition_Player, zero, 0, theBaseList, 0, NULL);
	AE_ASSERT(pHero);
	// 背景对象实例化
	pObj = CreateGameObj(TYPE_BACKGROUND, SIZE_BACKGROUND, zero, iniVelocity_Background, 0, theBaseList, 0, NULL);
	// 平台对象实例化
	pObj = CreateGameObj(TYPE_PLATFORM, SIZE_PLATFORM, zero, iniVelocity_Platform, 0, theBaseList, 0, NULL);
	AE_ASSERT(pHero);
	// 对象实例化 并 初始化
	for (i = 0; i < BLOCK_NUM; i++)
	{
		// 实例化
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
	// 获取窗口四条边的坐标，当窗口发生移动或缩放，以下值会发生变化
	// ==========================================================================================
	winMaxX = AEGfxGetWinMaxX();
	winMaxY = AEGfxGetWinMaxY();
	winMinX = AEGfxGetWinMinX();
	winMinY = AEGfxGetWinMinY();

	// ======================
	// 帧时间：Unity中的dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();

	// =========================
	// 游戏逻辑响应输入
	// =========================

	// 状态切换
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

	// 更新Hero外的对象位置
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



	// 控制玩家player左右移动 及 跳跃(匀速)
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
	// Player跳起后的重力效应
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// ====================
	// 碰撞检测
	// ====================
	for (pbasenode = theBaseList->head->next; (pbasenode != theBaseList->tail) && (deathFlag == 0); pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; (pinsnode != tlist->tail) && (deathFlag == 0); pinsnode = pinsnode->next)
		{
			GameObj* pInst = pHero;
			GameObj* pInstOther = &(pinsnode->gameobj);

			// 不处理非活动对象
			if (pInst->flag == FLAG_INACTIVE)
				continue;

			// Player 与 background / block 的碰撞检测
			if (pInst->pObject->type == TYPE_PLAYER)
			{
				for (pbasenode2 = theBaseList->head->next; (pbasenode2 != theBaseList->tail) && (deathFlag == 0); pbasenode2 = pbasenode2->next)
				{
					tlist2 = pbasenode2->gameobj_list;
					for (pinsnode2 = tlist2->head->next; (pinsnode2 != tlist2->tail) && (deathFlag == 0); pinsnode2 = pinsnode2->next)
					{
						pInstOther = &(pinsnode2->gameobj);

						// 跳过非活动对象和自身
						if ((pInstOther->flag & FLAG_ACTIVE) == 0 || (pInstOther->pObject->type == TYPE_PLAYER))
							continue;

						// Player vs. Block
						if (pInstOther->pObject->type == TYPE_BLOCK)
						{
							// 碰撞检测
							if (StaticCircleToStaticCircle(&(pInst->posCurr), pInst->scale, &(pInstOther->posCurr), pInstOther->scale))
							{
								// 装上BLOCK死亡
								// 重新开始关卡
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
							//是否在平台上
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
	// 计算所有对象的2D变换矩阵
	// =====================================
	for (pbasenode = theBaseList->head->next; pbasenode != theBaseList->tail; pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
		{
			GameObj* pInst = &(pinsnode->gameobj);
			Matrix2D		 trans, rot, scale;

			// 不处理非活动对象
			if ((pInst->flag & FLAG_ACTIVE) == 0)
				continue;

			// 缩放矩阵
			Matrix2DScale(&scale, pInst->scale, pInst->scale);
			// 旋转矩阵
			Matrix2DRotDeg(&rot, pInst->dirCurr);
			// 平移矩阵
			Matrix2DTranslate(&trans, pInst->posCurr.x, pInst->posCurr.y);
			// 以正确的顺序连乘以上3个矩阵形成2维变换矩阵
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

	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// 逐个绘制对象列表中的所有对象
	for (pbasenode = theBaseList->head->next; pbasenode != theBaseList->tail; pbasenode = pbasenode->next)
	{
		tlist = pbasenode->gameobj_list;
		for (pinsnode = tlist->head->next; pinsnode != tlist->tail; pinsnode = pinsnode->next)
		{
			GameObj* pInst = &(pinsnode->gameobj);

			// 跳过非活动对象
			if ((pInst->flag & FLAG_ACTIVE) == 0)
				continue;
			// 设置纹理
			AEGfxTextureSet(pInst->pObject->pTex, 0, 0);
			// 设置对象的2D变换矩阵，使用函数：AEGfxSetTransform
			AEGfxSetTransform(pInst->transform.m);
			// 绘制当前对象，使用函数：AEGfxMeshDraw
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

	// 使用函数gameObjDestroy删除列表中的对象
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
	
	printf ("atry");
}
