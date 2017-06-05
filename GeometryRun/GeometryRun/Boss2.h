#ifndef BOSS2_H
#define BOSS2_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "TimeManager.h"
#include "Block.h"
#include "Monster.h"

#define SIZE_BOSS2 40.0f		// boss尺寸

// Boss对象：在一定时间后产生且独特，故单独声明
GameObj* pBoss2;

// Boss2的状态
int Boss2Status;
float Boss2SkillCycle;
int Boss2HP, Boss2AngerHP;
// 上下巡逻范围
float Boss2PatrolMaxY, Boss2PatrolMinY;
// 进入的距离
float Boss2EnterX;
Vector2D Boss2IniPos;
Vector2D Boss2EnterVel, Boss2MoveUpward, Boss2MoveDownward;
float Boss2ImpactSpeed;

// Boss2的技能
enum boss2Skills{
	B2SKILL_CREATEMONSTERS,
	B2SKILL_CREATEBLOCKS,
	B2SKILL_IMPACT,
	B2SKILL_Count
};

typedef Status (*BossSkills)(float curTime);
BossSkills boss2skills[B2SKILL_Count];
int Boss2SkillCount;

// Boss2的状态
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