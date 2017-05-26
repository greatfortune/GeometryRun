#include "KeyAndObjUpdate.h"

Status GetWinMaxMinXY()
{
	// ==========================================================================================
	// ��ȡ���������ߵ����꣬�����ڷ����ƶ������ţ�����ֵ�ᷢ���仯
	// ==========================================================================================
	winMaxX = AEGfxGetWinMaxX();
	winMaxY = AEGfxGetWinMaxY();
	winMinX = AEGfxGetWinMinX();
	winMinY = AEGfxGetWinMinY();
	return OK;
}

Status KeyUpdate()
{
	// ״̬�л�
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
	// �������player�����ƶ� �� ��Ծ(����)
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
	// �����ǻ���������
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
					// ��ײ���
					if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
					{
						// װ��BLOCK����
						// ���¿�ʼ�ؿ�
						Next = GS_Restart;
						printf("\n Collision with the Block: Pos(%.1f, %.1f)\n Restart\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
						break;
					}
				break;
				}
				case OTYPE_PLATFORM:
				{
					//�Ƿ���ƽ̨��
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

	// ������ǻ����
	if (pInstForCollisionDetect->flag == FLAG_INACTIVE)
		return OK;

	// Player �� background / block ����ײ���
	BaseListTraverse(theBaseList, Visit_CollisionDetectAnother);
	return OK;
}

Status Visit_Matrix2DCount(insNode* pinsNode, GameObjList L)
{
	GameObj* pInst = &(pinsNode->gameobj);
	Matrix2D		 trans, rot, scale;

	// ������ǻ����
	if ((pInst->flag & FLAG_ACTIVE) == 0)
		return OK;

	// ���ž���
	Matrix2DScale(&scale, pInst->scale, pInst->scale);
	// ��ת����
	Matrix2DRotDeg(&rot, pInst->dirCurr);
	// ƽ�ƾ���
	Matrix2DTranslate(&trans, pInst->posCurr.x, pInst->posCurr.y);
	// ����ȷ��˳����������3�������γ�2ά�任����
	Matrix2DConcat(&(pInst->transform), &trans, &rot);
	Matrix2DConcat(&(pInst->transform), &(pInst->transform), &scale);
	return OK;
}

