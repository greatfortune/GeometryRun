/**
* Project:		GeometryRun
* File Name:	AddLife.c
* Author:		�ƽ�ˮ
* Date:		2017-6-17
*/
#include "AddLife.h"

// ����Ĭ���ٶȣ���ؿ���أ�
static Vector2D defaultAddLifeVel;
static float defaultAddLifeScale;

Status AddLifeLoad()
{
	// ========================
	// ��������ֵ�ĵ���
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_ADDLIFE, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/player/AddLife.png"), theBaseList);
	return OK;
}

Status AddLifeStart()
{
	defaultAddLifeScale = 9.0f;
	Vector2DSet(&defaultAddLifeVel, -10.0f, 0.0f);
	return OK;
}

Status AddLifeUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status AddLifeCollision(insNode* pinsNode)
{
	GameObj* pInstOther = &(pinsNode->gameobj);
	if (pInstOther->pObject->type == OTYPE_PLAYER)
	{
		//prop VS Player
		// ��ײ���
		if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
		{
			// ײ��Player��Player��Ѫ
			// hero HP+1
			PlayerAddLife(1);
			printf("\n AddLife with the prop: Pos(%.1f, %.1f)\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
			GameObjDelete(pInstForCollisionDetect);
		}
	}
	return OK;
}

GameObj* AddLifeCreateAtPosWithVel(Vector2D AddLifePos, Vector2D AddLifeVel)
{
	return CreateGameObj(OTYPE_ADDLIFE, defaultAddLifeScale, AddLifePos, AddLifeVel, 0, theBaseList, 0, NULL);
}

GameObj* AddLifeCreateAtPos(Vector2D AddLifePos)
{
	return CreateGameObj(OTYPE_ADDLIFE, defaultAddLifeScale, AddLifePos, defaultAddLifeVel, 0, theBaseList, 0, NULL);
}

float AddLifeScaleGet()
{
	return defaultAddLifeScale;
}

Status AddLifeDefaultVelSet(float vx, float vy)
{
	Vector2DSet(&defaultAddLifeVel, vx, vy);
	return OK;
}

Status AddLifeDefaultVxChange(float change)
{
	defaultAddLifeVel.x += change;
	return OK;
}

