#include "Player.h"

Status PlayerLoad()
{
	// =========================
	// ����
	// =========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);

	CreateGameObjBase(OTYPE_PLAYER, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/thePlayer.png"), theBaseList);
	return OK;
}

Status PlayerStart()
{
	Vector2DSet(&iniPosition_Player, -250.0f, 40.0f);
	jumpCheck = 1;
	dropCheck = 0;
	PlayerHP = 3;
	ProtectCur = 0;
	MaxProtectCur = 70;

	MaxBulletCount = 8;
	CurSupplyTime = 0;
	SupplyTime = 30;
	BulletCount = 4;

	return OK;
}

Status PlayerUpdate(GameObj* pInst)
{

	// Player����������ЧӦ
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// �������player�����ƶ� �� ��Ծ(����)
	if (KeyPressed[KeyRight] == TRUE)
	{
		pHero->velCurr.x = MOVE_VELOCITY_HERO;
	} else
	if (KeyPressed[KeyLeft] == TRUE)
	{
		pHero->velCurr.x = -MOVE_VELOCITY_HERO;
	}
	else
		pHero->velCurr.x = 0.f;
	if (KeyPressed[KeyDown] == TRUE || KeyPressed[KeyS] == TRUE)
	{
		if (jumpCheck > 0)
		{
			jumpCheck = -1;
			dropCheck = 1;
			pHero->velCurr.y = -DROP_VELOCITY;
		}
		else if (jumpCheck == 0)
		{
			jumpCheck = -1;
			dropCheck = 0;
			pHero->velCurr.y = -DROP_VELOCITY;
		}
	}
	if (KeyPressed[KeyW] == TRUE || KeyPressed[KeyUp] == TRUE)
	{
		printf("Input : up\n");
		if (jumpCheck == -1 && !dropCheck)		// ���һ���ƽ̨����
		{
			jumpCheck = 0;
			pHero->velCurr.y = DROP_VELOCITY;
		}
		else if (jumpCheck < 2 && !dropCheck)
		{
			pHero->velCurr.y = JUMP_VELOCITY;
			jumpCheck++;
		}
	}
	if (CurSupplyTime <= SupplyTime)
	{
		CurSupplyTime++;
	}
	else
	{
		if (BulletCount < MaxBulletCount)
			BulletCount++;
		CurSupplyTime = 0;
	}
	if (KeyPressed[KeyJ] == TRUE || KeyPressed[KeySpace] == TRUE)
	{
		Vector2D iniBulletPos = { pHero->posCurr.x + 1.5 * SIZE_HERO, pHero->posCurr.y };
		if (BulletCount > 0)
		{
			BulletCount--;
		}
		else
		{
			return OK;
		}
		CreateGameObj(OTYPE_BULLET, SIZE_BULLET, iniBulletPos, Velocity_Bullet, 0, theBaseList, 0, NULL);
	}
	pHero->posCurr.x += pHero->velCurr.x * frameTime;
	pHero->posCurr.y += pHero->velCurr.y * frameTime;
	return OK;
}

Status PlayerCollision(insNode* pinsNode)
{
	GameObj* pInstOther = &(pinsNode->gameobj);
	switch (pInstOther->pObject->type)
	{
			// Player vs. Platform
		case OTYPE_PLATFORM:
		{
			// ���λ�õ������Ƿ���
			if (pInstForCollisionDetect->posCurr.y >= 0)
			{
				pInstForCollisionDetect->properties[0].value = 1;
			}
			else
			{
				pInstForCollisionDetect->properties[0].value = -1;
			}
			//�Ƿ���ƽ̨��
			if ((pInstForCollisionDetect->posCurr.y) <= pInstForCollisionDetect->scale + PLATFORM_HEIGHT)
			{
				dropCheck = 0;
				if (jumpCheck > 0)	// �����������
				{
					jumpCheck = 0;
					pInstForCollisionDetect->velCurr.y = 0.0f;
					pInstForCollisionDetect->posCurr.y = pInstForCollisionDetect->scale + PLATFORM_HEIGHT;
				}
				else if (jumpCheck == 0)
				{
					if (pInstForCollisionDetect->posCurr.y >= pInstForCollisionDetect->scale)			// ��ת�ص��Ϲ���
					{
						pInstForCollisionDetect->velCurr.y = 0.0f;
						pInstForCollisionDetect->posCurr.y = pInstForCollisionDetect->scale + PLATFORM_HEIGHT;
					}
				}
				else if (pInstForCollisionDetect->posCurr.y <= -1 * pInstForCollisionDetect->scale - PLATFORM_HEIGHT)		// Ѹ���������
				{
					pInstForCollisionDetect->velCurr.y = 0.0f;
					pInstForCollisionDetect->posCurr.y = -1 * pInstForCollisionDetect->scale - PLATFORM_HEIGHT;
				}
			}
			else
			{
				if (jumpCheck == 0)
				{
					pInstForCollisionDetect->velCurr.y = 0.0f;
					pInstForCollisionDetect->posCurr.y = pInstForCollisionDetect->scale + PLATFORM_HEIGHT;
				}
			}
		}
		break;//Player VS Platform����

		// Player vs. Block/Monster/AIMonster
		case OTYPE_BLOCK:
		case OTYPE_MONSTER:
		case OTYPE_AIMONSTER:
		{
			// ��ײ���
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// ײ��BLOCK����
				// ���¿�ʼ�ؿ�
				if (!isProtected)
					PlayerGetHurt(1);
				printf("\n Collision with the %s: Pos(%.1f, %.1f)\n Restart\n", ObjTypeName[pInstOther->pObject->type], pInstOther->posCurr.x, pInstOther->posCurr.y);
			}
		}
		break;// Player vs. Block/Monster/AIMonster����

		case OTYPE_BOSS2:
		// ��ײ���
		if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
		{
			// hero HP-1
			if (!isProtected)
				PlayerGetHurt(2);
			printf("\n Collision with the Boss2: Pos(%.1f, %.1f)\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
		}
		break;
		default:
			break;
	}

	return OK;
}

Status PlayerGetHurt(int hurt)
{
	PlayerHP -= hurt;
	if (PlayerHP <= 0)
		PlayerDead();
	else
	{
		isProtected = 1;
	}
	return OK;
}

Status PlayerDead()
{
	GameObjDelete(pHero);
	Next = GS_Lose;
	return OK;
}