#ifndef BOSS2_H
#define BOSS2_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "TimeManager.h"
#include "Block.h"
#include "Monster.h"
#include "AIMonster.h"

#define SIZE_BOSS2 40.0f		// boss尺寸

// Boss对象：在一定时间后产生且独特，故单独声明，生成Boss对象时需为pBoss赋值
GameObj* pBoss2;

// Boss2的状态
int Boss2Alive;		// Boss生存状态，Level4中用到
int Boss2Status;
float Boss2SkillCycle;
int Boss2HP, Boss2AngerHP, Boss2MaxHP;
// 上下巡逻范围
float Boss2PatrolMaxY, Boss2PatrolMinY;
// 进入的距离
float Boss2EnterX, Boss2ImpactX;
Vector2D Boss2IniPos;
Vector2D Boss2EnterVel, Boss2MoveUpward, Boss2MoveDownward;
Vector2D Boss2ImpactVelLeft, Boss2ImpactVelRight;
float Boss2ImpactSpeed;

// Boss2上一次使用的技能
int Boss2LastSkill;

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
	//B2STATUS_
	B2STATUS_ENTER,
	B2STATUS_NORMAL,
	B2STATUS_ANGRY,
	B2STATUS_IMPACTL,
	B2STATUS_IMPACTR,
	B2STATUS_Count
};

Status Boss2Load();

Status Boss2Ini();

Status Boss2Start(int bossMaxHP);

Status Boss2Update(GameObj* pInst);

Status Boss2Collision(insNode* pinsNode);

Status Boss2SkillLoad();

Status Boss2Skill_CreateMonster(float curTime);

Status Boss2Skill_CreateBlock(float curTime);

Status Boss2Skill_GetAngey();

Status Boss2Skill_Impact(float curTime);

Status Boss2UseSkillRandomly(float curTime);

Status Boss2Dead();

Status Boss2GetHurt();

#endif