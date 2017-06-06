#include "Bullet.h"


Status BulletLoad()
{
	// ========================
	// ×Óµ¯
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
	CreateGameObjBase(OTYPE_BULLET, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/bullet.png"), theBaseList);
	return OK;
}

Status BulletStart()
{
	Vector2DSet(&Velocity_Bullet, 4.0f, 0.0f);
	return OK;
}

Status BulletUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x;
	pInst->posCurr.y += pInst->velCurr.y;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status BulletCollision(insNode* pinsNode)
{
	GameObj* pInstOther = &(pinsNode->gameobj);

	switch (pInstOther->pObject->type)
	{
			//BULLET VS MONSTER
		case OTYPE_MONSTER:
		{
			// Åö×²¼ì²â
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ×²ÉÏMonster£¬ÏûÃð×Óµ¯ºÍMONSTER
				GameObjDelete(pInstOther);
				GameObjDelete(pInstForCollisionDetect);
			}
			break;//BULLET VS MONSTER½áÊø
		}

		//BULLET VS BLOCK
		case OTYPE_BLOCK:
		{
			// Åö×²¼ì²â
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ×²ÉÏBLOCK£¬ÏûÃðBULLET
				GameObjDelete(pInstForCollisionDetect);
			}
			break;//BULLET VS BLOCK½áÊø
		}
		case OTYPE_BOSS2:
		{
			// Åö×²¼ì²â
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ×²ÉÏBOSS2, ¼õÑª,ÏûÃðBULLET
				Boss2GetHurt(pInstForCollisionDetect->properties[damage].value);
				GameObjDelete(pInstForCollisionDetect);
			}
		}
	}
	return OK;
}
