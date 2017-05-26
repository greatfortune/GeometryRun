#include "KeyAndObjUpdate.h"

Status GetWinMaxMinXY()
{
	// ==========================================================================================
	// 获取窗口四条边的坐标，当窗口发生移动或缩放，以下值会发生变化
	// ==========================================================================================
	winMaxX = AEGfxGetWinMaxX();
	winMaxY = AEGfxGetWinMaxY();
	winMinX = AEGfxGetWinMinX();
	winMinY = AEGfxGetWinMinY();
	return OK;
}

Status KeyUpdate()
{
	// 状态切换
	if (KeyPressed[KeyR] == TRUE)
	{
		Next = GS_Restart;
		return FLAG_IMPORTANTKEY;
	}
	if (KeyPressed[KeyESC] == TRUE)
	{
		Next = GS_Quit;
		return FLAG_IMPORTANTKEY;
	}
	if (KeyPressed[Key2] == TRUE)
	{
		Next = GS_L2;
		return FLAG_IMPORTANTKEY;
	}
	KeyPressed[KeyUp] = GetKeyState(VK_UP);
	KeyPressed[KeyDown] = GetKeyState(VK_DOWN);
	KeyPressed[KeyLeft] = GetKeyState(VK_LEFT);
	KeyPressed[KeyRight] = GetKeyState(VK_RIGHT);
	KeyPressed[KeySpace] = GetKeyState(VK_SPACE);
	// 控制玩家player左右移动 及 跳跃(匀速)
	if (KeyPressed[KeyRight] < 0)
		pHero->velCurr.x = MOVE_VELOCITY_HERO;
	else if (KeyPressed[KeyLeft] < 0)
		pHero->velCurr.x = -MOVE_VELOCITY_HERO;
	else
		pHero->velCurr.x = 0.0f;

	if (KeyPressed[KeySpace] < 0)
	{
		if (jumpCheck<2)
			pHero->velCurr.y = JUMP_VELOCITY;
		jumpCheck++;
	}
	return OK;
}

Status Visit_PositionUpdate(insNode* pinsNode, GameObjList L)
{
	GameObj* pInst = &(pinsNode->gameobj);
	if (pInst->flag == FLAG_INACTIVE)
		return OK;
	switch (pInst->pObject->type)
	{
		case OTYPE_BACKGROUND:
		{
			pInst->posCurr.x += pInst->velCurr.x;
			pInst->posCurr.y += pInst->velCurr.y;
			if (pInst->posCurr.x <= winMinX - winMaxX)
				pInst->posCurr.x = 0.0f;
			break;
		}
		case OTYPE_PLATFORM:
		{
			pInst->posCurr.x += pInst->velCurr.x;
			pInst->posCurr.y += pInst->velCurr.y;
			if (pInst->posCurr.x <= winMinX)
				pInst->posCurr.x = 0.0f;
			break;
		}
		case OTYPE_BLOCK:
		{
			pInst->posCurr.x += pInst->velCurr.x;
			pInst->posCurr.y += pInst->velCurr.y;
			if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
				GameObjDelete(pInst, L);
			break;
		}
		default:
		break;
	}
	return OK;
}

static Status Visit_CollisionDetectAnother(insNode* pinsNode, GameObjList L);

static Status Visit_CollisionDetectAnother(insNode* pinsNode, GameObjList L)
{
	GameObj* pInstOther = &(pinsNode->gameobj);
	// 跳过非活动对象和自身
	if (pInstOther->flag == FLAG_INACTIVE || (pInstOther->pObject->type == pInstForCollisionDetect->pObject->type))
		return OK;
	switch (pInstForCollisionDetect->pObject->type)
	{
		case OTYPE_PLAYER:
		{
			switch (pInstOther->pObject->type)
			{
				// Player vs. Block
				case OTYPE_BLOCK:
				{
					// 碰撞检测
					if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
					{
						// 装上BLOCK死亡
						// 重新开始关卡
						Next = GS_Restart;
						printf("\n Collision with the Block: Pos(%.1f, %.1f)\n Restart\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
						break;
					}
				break;
				}
				case OTYPE_PLATFORM:
				{
					//是否在平台上
					if ((pInstForCollisionDetect->posCurr.y) <= pInstForCollisionDetect->scale + 10.0f)
					{
						jumpCheck = 0;
						pInstForCollisionDetect->velCurr.y = 0.0f;
						pInstForCollisionDetect->posCurr.y = pInstForCollisionDetect->scale + 10.0f;
					}
					break;
				}
				default:
					break;
			}
			break;
		}
		default:
			break;
	}

	return OK;
}

Status Visit_CollisionDetect(insNode* pinsNode, GameObjList L)
{
	pInstForCollisionDetect = &(pinsNode->gameobj);

	// 不处理非活动对象
	if (pInstForCollisionDetect->flag == FLAG_INACTIVE)
		return OK;

	// Player 与 background / block 的碰撞检测
	BaseListTraverse(theBaseList, Visit_CollisionDetectAnother);
	return OK;
}

Status Visit_Matrix2DCount(insNode* pinsNode, GameObjList L)
{
	GameObj* pInst = &(pinsNode->gameobj);
	Matrix2D		 trans, rot, scale;

	// 不处理非活动对象
	if ((pInst->flag & FLAG_ACTIVE) == 0)
		return OK;

	// 缩放矩阵
	Matrix2DScale(&scale, pInst->scale, pInst->scale);
	// 旋转矩阵
	Matrix2DRotDeg(&rot, pInst->dirCurr);
	// 平移矩阵
	Matrix2DTranslate(&trans, pInst->posCurr.x, pInst->posCurr.y);
	// 以正确的顺序连乘以上3个矩阵形成2维变换矩阵
	Matrix2DConcat(&(pInst->transform), &trans, &rot);
	Matrix2DConcat(&(pInst->transform), &(pInst->transform), &scale);
	return OK;
}

