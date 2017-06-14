#include "BossBullet.h"


Status BossBulletLoad()
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
	CreateGameObjBase(OTYPE_BOSSBULLET, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/enemy/bossbullet.png"), theBaseList);
	return OK;
}

Status BossBulletStart(float BossBulletVelABS)
{
	Velocity_BossBulletABS = BossBulletVelABS;
	return OK;
}

Status BossBulletIni()
{
	Vector2DSet(&iniBossBulletPos, pBoss2->posCurr.x - 1.5 * SIZE_BOSS2, pBoss2->posCurr.y);
	BossBulletDir = Vector2DAngle(&iniBossBulletPos, &pHero->posCurr);
	Vector2DSet(&Velocity_BossBullet, Velocity_BossBulletABS * cosf(BossBulletDir / 180 * PI), Velocity_BossBulletABS * sinf(BossBulletDir / 180 * PI));
	printf("  vel : %.1f   %.1f\n", Velocity_BossBullet.x, Velocity_BossBullet.y);
	return OK;
}

Status BossBulletUpdate(GameObj* pInst)
{
	pInst->posCurr.x += pInst->velCurr.x * frameTime;
	pInst->posCurr.y += pInst->velCurr.y * frameTime;
	if ((pInst->posCurr.x < winMinX) || (pInst->posCurr.x > winMaxX) || (pInst->posCurr.y < winMinY) || (pInst->posCurr.y > winMaxY))
		GameObjDelete(pInst);
	return OK;
}

Status BossBulletCollision(insNode* pinsNode)
{
	GameObj* pInstOther = &(pinsNode->gameobj);
	if (pInstOther->pObject->type == OTYPE_PLAYER)
	{
		//BossBullet VS Player
		// Åö×²¼ì²â
		if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
		{
			// ×²ÉÏPlayer£¬PlayerµôÑª
			if (!isProtected)
				PlayerGetHurt(1);
			printf("\n Collision with the %s: Pos(%.1f, %.1f)\n Restart\n", ObjTypeName[pInstOther->pObject->type], pInstOther->posCurr.x, pInstOther->posCurr.y);
			GameObjDelete(pInstForCollisionDetect);
		}
		return OK;
	}
}
