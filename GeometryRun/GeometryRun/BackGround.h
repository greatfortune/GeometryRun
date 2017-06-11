#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"
#include "GameStateList.h"
#include "input.h"

#define SIZE_BACKGROUND 400.0f	// �����ߴ�

enum {
	BTYPE_MENU_START = 0,
	BTYPE_MENU_CHOOSE,
	BTYPE_MENU_HELPSTAFF,
	BTYPE_MENU_EXIT,
	BTYPE_PASS_NEXT,
	BTYPE_PASS_MENU,
	BTYPE_WIN_RESTART,
	BTYPE_WIN_MENU,
	BTYPE_LOSE_RESTART,
	BTYPE_LOSE_MENU,
	BTYPE_FALSE,
	BTYPE_COUNT
};

// ����Level0�п��ƶ�������
GameObj* pImage;
int xcurrentFrame;
float elpasedTime;

// ��ʼ���꼰�ٶ�
Vector2D iniPosition_Background;
Vector2D iniVelocity_Background;

Status BackGroundLoad();

Status BackGroundStart();

Status BackGroundUpdate(GameObj* pInst);

int JudgeMousPos();

#endif