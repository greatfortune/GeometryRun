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
	Boss2ImpactSpeed = 1.0f;
	Boss2Status = B2STATUS_ENTER;
	Boss2SkillCycle = 100.0f;
	Boss2HP = 50;
	Boss2AngerHP = 40;
	// 上下巡逻范围
	Boss2PatrolMaxY = 100.0f;
	Boss2PatrolMinY = -100.0f;
	// 进入的距离
	Boss2EnterX = 30.0f;
	Vector2DSet(&Boss2EnterVel, -2.3f, 0.0f);
	Vector2DSet(&Boss2MoveUpward, 0.0f, 1.0f);
	Vector2DSet(&Boss2MoveDownward, 0.0f, -1.0f);
	Vector2DSet(&Boss2IniPos, 500.0f, 0.0f);
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
	
	switch (Boss2Status)
	{
		case B2STATUS_ENTER:
		{
			if (pInst->posCurr.x <= winMaxX - Boss2EnterX)
			{
				Boss2Status = B2STATUS_NORMAL;
				SetObjSpeed(pInst, Boss2MoveUpward);
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
			if (pInst->posCurr.y >= Boss2PatrolMaxY)
			{
				SetObjSpeed(pBoss2, Boss2MoveDownward);
				Boss2UseSkillRandomly(passTime);
			}
			else if (pInst->posCurr.y <= Boss2PatrolMinY)
			{
				SetObjSpeed(pBoss2, Boss2MoveUpward);
				Boss2UseSkillRandomly(passTime);
			}
			break;
		}
		case B2STATUS_ANGRY:
		{
			if (pInst->posCurr.y >= Boss2PatrolMaxY)
			{
				SetObjSpeed(pBoss2, Boss2MoveDownward);
				Boss2UseSkillRandomly(passTime);
			}
			else if (pInst->posCurr.y <= Boss2PatrolMinY)
			{
				SetObjSpeed(pBoss2, Boss2MoveUpward);
				Boss2UseSkillRandomly(passTime);
			}
			break;
		}
		default:
			break;
	}
	if (Boss2HP <= 0)
		GameObjDelete(pInst);
	return OK;
}

Status Boss2Collision(insNode* pinsNode, GameObjList L)
{
	return OK;
}

Status Boss2Skill_CreateMonster(float curTime)
{
	float iniFloat = 1.0f;
	float iniMinX = winMaxX - 40.0f, iniMaxX = winMaxX, iniMinY = winMinY, iniMaxY = winMaxY, iniMinVx = -4.0f, iniMaxVx = -2.0f;
	float iniMinVy = 0.0f, iniMaxVy = 0.0f, iniMinDir = -3.0f, iniMaxDir = 3.0f;

	return CreateSomeObjAtSameTimeWithRange(curTime, 3, OTYPE_BLOCK, SIZE_BLOCK, theBaseList, 0, NULL, iniMinX, iniMaxX, iniMinY, iniMaxY, iniMinVx, iniMaxVx, iniMinVy, iniMaxVy, iniMinDir, iniMaxDir);
}

Status Boss2Skill_CreateBlock(float curTime)
{
	float iniFloat = 1.0f;
	float iniMinX = winMaxX - 40.0f, iniMaxX = winMaxX, iniMinY = winMinY, iniMaxY = winMaxY, iniMinVx = -4.0f, iniMaxVx = -2.0f;
	float iniMinVy = 0.0f, iniMaxVy = 0.0f, iniMinDir = 0.0f, iniMaxDir = 0.0f;

	return CreateSomeObjAtSameTimeWithRange(curTime, 5, OTYPE_MONSTER, SIZE_MONSTER, theBaseList, 0, NULL, iniMinX, iniMaxX, iniMinY, iniMaxY, iniMinVx, iniMaxVx, iniMinVy, iniMaxVy, iniMinDir, iniMaxDir);

}

Status Boss2Skill_Impact(float curTime)
{
	AddSpeedForObjAtTime(curTime, pBoss2, -Boss2ImpactSpeed, 0.0f);
	AddSpeedForObjAtTime(curTime + Boss2SkillCycle / 2, pBoss2, 2 * Boss2ImpactSpeed, 0.0f);
	AddSpeedForObjAtTime(curTime + Boss2SkillCycle, pBoss2, -Boss2ImpactSpeed, 0.0f);
	return OK;
}

Status Boss2Skill_GetAngey()
{
	Vector2DSet(&Boss2MoveUpward, 0.0f, 1.7f);
	Vector2DSet(&Boss2MoveDownward, 0.0f, -1.7f);
	Boss2SkillCount = 2;
	boss2skills[2] = Boss2Skill_Impact;
	return OK;
}

Status Boss2UseSkillRandomly(float curTime)
{
	int CurSkill = rand() % Boss2SkillCount;
	boss2skills[CurSkill](curTime + OFFSETTIME);
	return OK;
}

