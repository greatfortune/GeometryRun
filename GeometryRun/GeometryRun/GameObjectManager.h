/* Project:		GeometryRun
File Name:	GameObjectManager.h
Author:		黄嘉维
Date:
Purpose:		游戏对象管理 */

#ifndef _GameObjectManager
#define _GameObjectManager

#define OK 1
#define FLAG_ACTIVE 1
#define FLAG_INACTIVE 0

#include <stdio.h>
#include <stdbool.h>
#include "GameStateList.h"
#include "System.h"
#include "AEEngine.h"
#include "GameObjectManager.h"
#include "Vector2D.h"
#include "Matrix2D.h"
#include "Math2D.h"
#include <time.h>

typedef int Status;

#define MAXPROPERTIES 5
#define SIZE_HERO					30.0f	// 角色尺寸
#define SIZE_BLOCK					38.0f	// 障碍物尺寸
#define SIZE_BACKGROUND				400.0f	// 背景尺寸
#define SIZE_PLATFORM				1000.0f	// 平台尺寸
#define BLOCK_NUM 4
#define COLOR_PLAYER 0xFFFFFFFF
#define COLOR_BACKGROUND 0x000000FF
#define MOVE_VELOCITY_HERO 300.0f
#define JUMP_VELOCITY 200.0f
#define GRAVITY 200.0f
#define MOVE_MAXVELOCITY_BLOCK 5.0f

typedef struct
{
	char name[10];
	int value;
}Property;

enum objType
{
	TYPE_PLAYER = 0,
	TYPE_PLATFORM,
	TYPE_BACKGROUND,
	TYPE_MONSTER,
	TYPE_BLOCK,
	TYPE_BOSS,
	TYPE_COUNT
};

// 游戏对象基类/结构
typedef struct
{
	unsigned long		type;		// 游戏对象类型
	AEGfxVertexList*	pMesh;		// 形状
	AEGfxTexture*		pTex;		// 纹理
}GameObjBase;

// 游戏对象类/结构
typedef struct
{
	GameObjBase*		pObject;	// 指向基类（原始形状和类型）
	unsigned long		flag;		// 活动标志
	float				scale;		// 尺寸
	Vector2D			posCurr;	// 当前位置
	Vector2D			velCurr;	// 当前速度
	float				dirCurr;	// 当前方向
	Matrix2D			transform;	// 变换矩阵：每一帧都需要为每一个对象计算
	Property			properties[MAXPROPERTIES]; // 该对象的属性
	int					propertyCount;			   // 该对象属性的个数
}GameObj;

typedef struct INSNODE
{
	GameObj gameobj;
	struct INSNODE *next;
	struct INSNODE *pre;
}insNode;

typedef struct
{
	int count;
	insNode *head;
	insNode *tail;
}GameObjNode, *GameObjList;

typedef struct BASENODE
{
	GameObjBase gameobj_base;
	struct BASENODE *next;
	struct BASENODE *pre;
	GameObjList gameobj_list;
}baseNode;

typedef struct
{
	int count;
	baseNode *head;
	baseNode *tail;
}GameObjBaseNode, *GameObjBaseList;


// 游戏对象链表
static GameObjBaseList theBaseList;
Vector2D zero;


// Player对象：因为是Player，所以单独声明，方便程序设计
static GameObj* pHero;

static AEGfxTexture* pTex_Hero;
//jumpCheck:跳跃次数，用于二级跳
int jumpCheck;

// 用于调试输出对象类型名称
static char ObjTypeName[TYPE_COUNT][20];

void SetConstants();

Status InitialGameObjList(GameObjList *L);

Status InitialGameObjBaseList(GameObjBaseList *L);

Status DestroyGameObjList(GameObjList *L);

Status DestroyGameObjBaseList(GameObjBaseList *L);

Status ClearGameObjList(GameObjList L);

Status ClearGameObjBaseList(GameObjBaseList L);

bool ListIsEmpty(GameObjList L);

bool BaseListIsEmpty(GameObjBaseList L);

int ListLength(GameObjList L);

int BaseListLength(GameObjBaseList L);

GameObj* CreateGameObj(unsigned long theType, float scale, Vector2D Pos, Vector2D Vel, float dir, GameObjBaseList L, int thePropertyCount, Property* theProperties);

Status CreateGameObjBase(unsigned long theType, AEGfxVertexList* theMesh, AEGfxTexture* theTexture, GameObjBaseList L);

Status GameObjDelete(GameObj* theGameObj);

Status ListTraverse(GameObjList L, void(*visit)());

Status BaseListTraverse(GameObjBaseList L, void(*visit)());

#endif 
