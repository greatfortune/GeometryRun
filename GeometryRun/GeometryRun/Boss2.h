#ifndef BOSS2_H
#define BOSS2_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "TimeManager.h"
#include "Block.h"
#include "Monster.h"

#define SIZE_BOSS2 40.0f		// boss�ߴ�

// Boss������һ��ʱ�������Ҷ��أ��ʵ�������
GameObj* pBoss2;

// Boss2��״̬
int Boss2Status;
float Boss2SkillCycle;
int Boss2HP, Boss2AngerHP;
// ����Ѳ�߷�Χ
float Boss2PatrolMaxY, Boss2PatrolMinY;
// ����ľ���
float Boss2EnterX;
Vector2D Boss2IniPos;
Vector2D Boss2EnterVel, Boss2MoveUpward, Boss2MoveDownward;
float Boss2ImpactSpeed;

// Boss2�ļ���
enum boss2Skills{
	B2SKILL_CREATEMONSTERS,
	B2SKILL_CREATEBLOCKS,
	B2SKILL_IMPACT,
	B2SKILL_Count
};

typedef Status (*BossSkills)(float curTime);
BossSkills boss2skills[B2SKILL_Count];
int Boss2SkillCount;

// Boss2��״̬
enum boss2Status
{
	B2STATUS_ENTER,
	B2STATUS_NORMAL,
	B2STATUS_ANGRY,
	B2STATUS_Count
};

Status Boss2Load();

Status Boss2Start();

Status Boss2Update(GameObj* pInst);

Status Boss2Collision(insNode* pinsNode);

Status Boss2SkillLoad();

Status Boss2Skill_CreateMonster(float curTime);

Status Boss2Skill_CreateBlock(float curTime);

Status Boss2Skill_GetAngey();

Status Boss2Skill_Impact(float curTime, float impactSpeed);

Status Boss2UseSkillRandomly();

#endif