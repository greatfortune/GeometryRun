#include "Bullet.h"


Status BulletLoad()
{
	// ========================
	// 子弹
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
	CreateGameObjBase(OTYPE_BULLET, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/player/playerbullet.png"), theBaseList);
	return OK;
}

Status BulletStart()
{
	Vector2DSet(&Velocity_Bullet, 400.0f, 0.0f);
	return OK;
}

Status BulletUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status BulletCollision(insNode* pinsNode)
{
	GameObj* pInstOther = &(pinsNode->gameobj);

	switch (pInstOther->pObject->type)
	{
		//BULLET VS MONSTER/AIMONSTER
		case OTYPE_MONSTER:
		case OTYPE_AIMONSTER:
		{
			// 碰撞检测
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// 撞上Monster，消灭子弹和MONSTER
				GameObjDelete(pInstOther);
				GameObjDelete(pInstForCollisionDetect);
			}
			break;//BULLET VS MONSTER/AIMONSTER结束
		}

		//BULLET VS BLOCK
		case OTYPE_BLOCK:
		{
			// 碰撞检测
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// 撞上BLOCK，消灭BULLET
				GameObjDelete(pInstForCollisionDetect);
			}
			break;//BULLET VS BLOCK结束
		}
		case OTYPE_BOSS2:
		{
			// 碰撞检测
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// 撞上BOSS2, 减血,消灭BULLET
				Boss2GetHurt();
				GameObjDelete(pInstForCollisionDetect);
			}
		}
	}
	return OK;
}
