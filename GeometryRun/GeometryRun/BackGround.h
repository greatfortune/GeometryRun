#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "GameObjectManager.h"
#include "KeyAndObjUpdate.h"

#define SIZE_BACKGROUND 400.0f	// �����ߴ�

// ����Level0�п��ƶ�������
GameObj* pImage;
int xcurrentFrame;
float elpasedTime;

// ��ʼ���꼰�ٶ�
Vector2D iniPosition_Background;
Vector2D iniVelocity_Background;

Status BackGroundLoad(int level);

Status BackGroundStart();

Status BackGroundUpdate(GameObj* pInst);

#endif