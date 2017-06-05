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
	if (KeyPressed[Key1] == TRUE)
	{
		Next = GS_L1;
		return FLAG_IMPORTANTKEY;
	}
	if (KeyPressed[Key2] == TRUE)
	{
		Next = GS_L2;
		return FLAG_IMPORTANTKEY;
	}

	// ���沥�����/��������� ����Level1
	if (Current == GS_L0)
	{
		KeyPressed[KeyLButton] = GetKeyState(VK_LBUTTON);
		if (KeyPressed[KeyLButton] < 0 || xcurrentFrame>11)
		{
			Next = GS_L1;
			return FLAG_IMPORTANTKEY;
		}
	}
	return OK;
}

//���¶���
Status Visit_Update(insNode* pinsNode, GameObjList L)
{
	GameObj* pInst = &(pinsNode->gameobj);
	if (pInst->flag == FLAG_INACTIVE)
		return OK;
	switch (pInst->pObject->type)
	{
		case OTYPE_PLAYER:
			PlayerUpdate(pInst);
			break;
		case OTYPE_BACKGROUND:
			BackGroundUpdate(pInst);
			break;
		case OTYPE_PLATFORM:
			PlatformUpdate(pInst);
			break;
		case OTYPE_MONSTER:
			MonsterUpdate(pInst);
			break;
		case OTYPE_BLOCK:
			BlockUpdate(pInst);
			break;
		case OTYPE_BULLET:
			BulletUpdate(pInst);
			break;
		case OTYPE_BOSS2:
			Boss2Update(pInst);
			break;
		default:
			break;
	}
	pInst->posCurr.x += pInst->velCurr.x;
	pInst->posCurr.y += pInst->velCurr.y;
	return OK;
}

//������ײ���
static Status Visit_CollisionDetectAnother(insNode* pinsNode, GameObjList L)
{
	GameObj* pInstOther = &(pinsNode->gameobj);
	// �����ǻ���������������
	if (pInstOther->flag == FLAG_INACTIVE || (pInstOther->pObject->type == pInstForCollisionDetect->pObject->type))
		return OK;
	switch (pInstForCollisionDetect->pObject->type)
	{
		case OTYPE_PLAYER:
			PlayerCollision(pinsNode, L);
			break;
		case OTYPE_BULLET:
			BulletCollision(pinsNode, L);
			break;
		
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
	if (pInst->pObject->type == OTYPE_PLAYER)
		Matrix2DScale(&scale, pInst->scale, pInst->scale * pInst->properties->value);
	else
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

