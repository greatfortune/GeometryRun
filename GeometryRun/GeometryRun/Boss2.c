#include "Boss2.h"

Status Boss2Load()
{
	// ========================
	// boss2
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
	CreateGameObjBase(OTYPE_BOSS2, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/boss.png"), theBaseList);
	return OK;
}

Status Boss2Start()
{
	pBoss2 = NULL;
	Boss2LastSkill = B2SKILL_CREATEBLOCKS;
	Boss2ImpactSpeed = 60.0f;
	Boss2Status = B2STATUS_ENTER;
	Boss2SkillCycle = 100.0f;
	Boss2HP = 80;
	Boss2AngerHP = 50;
	// 上下巡逻范围
	Boss2PatrolMaxY = 100.0f;
	Boss2PatrolMinY = -100.0f;
	// 进入的距离
	Boss2EnterX = 30.0f;
	// 冲撞至的x
	Boss2ImpactX = -400.0f;
	Vector2DSet(&Boss2EnterVel, -138.0f, 0.0f);
	Vector2DSet(&Boss2MoveUpward, 0.0f, 60.0f);
	Vector2DSet(&Boss2MoveDownward, 0.0f, -60.0f);
	Vector2DSet(&Boss2IniPos, 500.0f, 0.0f);
	Vector2DSet(&Boss2ImpactVelLeft, -600.0f, 0.0f);
	Vector2DSet(&Boss2ImpactVelRight, 600.0f, 0.0f);
	Boss2SkillLoad();
	return OK;
}

Status Boss2SkillLoad()
{
	Boss2SkillCount = 2;
	boss2skills[0] = Boss2Skill_CreateMonster;
	boss2skills[1] = Boss2Skill_CreateBlock;
	
	return OK;
}

Status Boss2Update(GameObj* pInst)
{
	pBoss2->posCurr.x += pBoss2->velCurr.x * frameTime;
	pBoss2->posCurr.y += pBoss2->velCurr.y * frameTime;
	switch (Boss2Status)
	{
		case B2STATUS_ENTER:
		{
			if (pBoss2->posCurr.x <= winMaxX - Boss2EnterX)
			{
 				Boss2Status = B2STATUS_NORMAL;
				SetObjSpeed(pBoss2, Boss2MoveUpward);
				break;
			}
			break;
		}
		case B2STATUS_NORMAL:
		{
			if (Boss2HP <= Boss2AngerHP)
			{
				Boss2Status = B2STATUS_ANGRY;
				Boss2Skill_GetAngey();
				break;
			}
			if (pBoss2->posCurr.y >= Boss2PatrolMaxY)
			{
				SetObjSpeed(pBoss2, Boss2MoveDownward);
				Boss2UseSkillRandomly(passTime);
			}
			else if (pBoss2->posCurr.y <= Boss2PatrolMinY)
			{
				SetObjSpeed(pBoss2, Boss2MoveUpward);
				Boss2UseSkillRandomly(passTime);
			}
			break;
		}
		case B2STATUS_ANGRY:
		{
			if (pBoss2->posCurr.y >= Boss2PatrolMaxY)
			{
				SetObjSpeed(pBoss2, Boss2MoveDownward);
				Boss2UseSkillRandomly(passTime);
			}
			else if (pBoss2->posCurr.y <= Boss2PatrolMinY)
			{
				SetObjSpeed(pBoss2, Boss2MoveUpward);
				Boss2UseSkillRandomly(passTime);
			}
			break;
		}
		case B2STATUS_IMPACTL:
		{
			if (pBoss2->posCurr.x <= Boss2ImpactX)
			{
				SetObjSpeed(pBoss2, Boss2ImpactVelRight);
				Boss2Status = B2STATUS_IMPACTR;
			}
			break;
		}
		case B2STATUS_IMPACTR:
		{
			if (pBoss2->posCurr.x >= winMaxX - Boss2EnterX)
			{
				if (pBoss2->posCurr.y <= 0)
					SetObjSpeed(pBoss2, Boss2MoveUpward);
				else
					SetObjSpeed(pBoss2, Boss2MoveDownward);
				Boss2Status = B2STATUS_ANGRY;
			}
			break;
		}
		default:
			break;
	}
	if (Boss2HP <= 0)
		Boss2Dead();
	return OK;
}

Status Boss2Collision(insNode* pinsNode)
{
	return OK;
}

Status Boss2Skill_CreateMonster(float curTime)
{
	float iniFloat = 1.0f;
	float iniMinX = winMaxX - 300.0f, iniMaxX = winMaxX, iniMinY = winMinY + 140.0f, iniMaxY = winMaxY - 140.0f, iniMinVx = -400.0f, iniMaxVx = -300.0f;
	float iniMinVy = 0.0f, iniMaxVy = 0.0f, iniMinDir = -3.0f, iniMaxDir = 3.0f;

	return CreateSomeObjAtSameTimeWithRange(curTime, 7, OTYPE_MONSTER, SIZE_MONSTER, theBaseList, 0, NULL, iniMinX, iniMaxX, iniMinY, iniMaxY, iniMinVx, iniMaxVx, iniMinVy, iniMaxVy, iniMinDir, iniMaxDir);
}

Status Boss2Skill_CreateBlock(float curTime)
{
	float iniFloat = 1.0f;
	float iniMinX = winMaxX - 300.0f, iniMaxX = winMaxX, iniMinY = winMinY + 140.0f, iniMaxY = winMaxY - 140.0f, iniMinVx = -240.0f, iniMaxVx = -120.0f;
	float iniMinVy = 0.0f, iniMaxVy = 0.0f, iniMinDir = 0.0f, iniMaxDir = 0.0f;

	return CreateSomeObjAtSameTimeWithRange(curTime, 4, OTYPE_BLOCK, SIZE_BLOCK, theBaseList, 0, NULL, iniMinX, iniMaxX, iniMinY, iniMaxY, iniMinVx, iniMaxVx, iniMinVy, iniMaxVy, iniMinDir, iniMaxDir);

}

Status Boss2Skill_Impact(float curTime)
{
	Boss2Status = B2STATUS_IMPACTL;
	SetObjSpeed(pBoss2, Boss2ImpactVelLeft);
	return OK;
}

Status Boss2Skill_GetAngey()
{
	Vector2DSet(&Boss2MoveUpward, 0.0f, 102.0f);
	Vector2DSet(&Boss2MoveDownward, 0.0f, -102.0f);
	Boss2SkillCount = 3;
	boss2skills[2] = Boss2Skill_Impact;
	return OK;
}

Status Boss2UseSkillRandomly(float curTime)
{
	int CurSkill;
// 确保boss使用的技能每次都不同
	while ((CurSkill = rand() % Boss2SkillCount) == Boss2LastSkill);
	Boss2LastSkill = CurSkill;
	boss2skills[CurSkill](curTime + OFFSETTIME);
	return OK;
}

Status Boss2GetHurt(int hurt)
{
	Boss2HP -= hurt;
	if (PlayerHP <= 0)
		PlayerDead();
}

Status Boss2Dead(){
	GameObjDelete(pBoss2);
}
