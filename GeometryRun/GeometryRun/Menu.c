/**
* Project:		GeometryRun
* File Name:	Menu.c
* Author:		�Ƽ�ά
* Date:		2017-6-5
* Purpose:		�˵�����
*/
#include "Menu.h"

void Load_Menu(void)
{
	// ���հ�ȡ������̨printf("Level2: Load\n");
	theBaseList = NULL;
	// ���ó���
	SetConstants();
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);

	BackGroundLoad();
}

void Ini_Menu(void)
{
	// ���հ�ȡ������̨printf("Level2: Ini\n");

	BackGroundStart();

}

void Update_Menu(void)
{
	GetWinMaxMinXY();

	// =========================
	// ��Ϸ�߼���Ӧ����
	// =========================
	KeyUpdate();

	// ���¶���
	ObjUpdate();

	// =====================================
	// �������ж����2D�任����
	// =====================================
	BaseListTraverse(Visit_Matrix2DCount);
}

void Draw_Menu(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);

	// ������ƶ����б��е����ж���
	BaseListTraverse(Visit_DrawObj);
}

void Free_Menu(void)
{

	// ���հ�ȡ������̨printf("Level_Menu: free\n");
	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload_Menu(void)
{
	// ���հ�ȡ������̨printf("Level_Menu: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
