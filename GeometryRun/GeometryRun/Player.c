#include "Player.h"

Status PlayerLoad()
{
	// =========================
	// 主角
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
	return OK;
}

Status PlayerUpdate(GameObj* pInst)
{
	double frameTime;
	// ======================
	// 帧时间：Unity中的dt
	// ======================
	frameTime = AEFrameRateControllerGetFrameTime();
	// Player跳起后的重力效应
	if (jumpCheck > 0)
		pHero->velCurr.y -= GRAVITY * frameTime;

	// 控制玩家player左右移动 及 跳跃(匀速)
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
		if (jumpCheck == -1 && !dropCheck)		// 倒挂或在平台底下
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
	if (KeyPressed[KeyJ] == TRUE || KeyPressed[KeySpace] == TRUE)
	{
		Vector2D iniBulletPos = { pHero->posCurr.x + 1.5 * SIZE_HERO, pHero->posCurr.y };
		Property properties_Bullet[BULLETPCount];
		SetProperty(&properties_Bullet[damage], "damage", 3);
		CreateGameObj(OTYPE_BULLET, SIZE_BULLET, iniBulletPos, Velocity_Bullet, 0, theBaseList, 1, &properties_Bullet);
	}
	pHero->posCurr.x += pHero->velCurr.x;
	pHero->posCurr.y += pHero->velCurr.y;
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
			// 检测位置调整主角方向
			if (pInstForCollisionDetect->posCurr.y >= 0)
			{
				pInstForCollisionDetect->properties[0].value = 1;
			}
			else
			{
				pInstForCollisionDetect->properties[0].value = -1;
			}
			//是否在平台上
			if ((pInstForCollisionDetect->posCurr.y) <= pInstForCollisionDetect->scale + PLATFORM_HEIGHT)
			{
				dropCheck = 0;
				if (jumpCheck > 0)	// 自由落体过程
				{
					jumpCheck = 0;
					pInstForCollisionDetect->velCurr.y = 0.0f;
					pInstForCollisionDetect->posCurr.y = pInstForCollisionDetect->scale + PLATFORM_HEIGHT;
				}
				else if (jumpCheck == 0)
				{
					if (pInstForCollisionDetect->posCurr.y >= pInstForCollisionDetect->scale)			// 翻转回地上过程
					{
						pInstForCollisionDetect->velCurr.y = 0.0f;
						pInstForCollisionDetect->posCurr.y = pInstForCollisionDetect->scale + PLATFORM_HEIGHT;
					}
				}
				else if (pInstForCollisionDetect->posCurr.y <= -1 * pInstForCollisionDetect->scale - PLATFORM_HEIGHT)		// 迅速下落过程
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
		break;//Player VS Platform结束

		// Player vs. Block
		case OTYPE_BLOCK:
		{
			// 碰撞检测
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// 撞上BLOCK死亡
				// 重新开始关卡
				Next = GS_Restart;
				printf("\n Collision with the Block: Pos(%.1f, %.1f)\n Restart\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
			}
		}
		break;// Player vs. Block结束

		//Player VS Monster
		case OTYPE_MONSTER:
		{
			// 碰撞检测
			if (StaticCircleToStaticCircle(&(pInstForCollisionDetect->posCurr), pInstForCollisionDetect->scale, &(pInstOther->posCurr), pInstOther->scale))
			{
				// 撞上Monster死亡
				// 重新开始关卡
				Next = GS_Restart;
				printf("\n Collision with the Monster: Pos(%.1f, %.1f)\n Restart\n", pInstOther->posCurr.x, pInstOther->posCurr.y);
			}
		}
		break;//Player VS Monster结束

		default:
			break;
	}

	return OK;
}