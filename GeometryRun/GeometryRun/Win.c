#include "Lose.h"

clock_t timeStart_level_Win;


void Load_Win(void)
{
	// ��ʼ��ʱ��ϵͳ
	//TimerIni(&timeStart_level_Win);

	printf("Level_Win: Load\n");
	theBaseList = NULL;
	// ���ó���
	SetConstants();
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);

	BackGroundLoad();
}

void Ini_Win(void)
{
	printf("Level_Win: Ini\n");
	// ��ȡ��ǰ�ؿ�ʱ��
	//timeStart_level_Win = clock();
	BackGroundStart();

	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, iniPosition_Background, iniVelocity_Background, 0, theBaseList, 0, NULL);

}

void Update_Win(void)
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

void Draw_Win(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// ������ƶ����б��е����ж���
	BaseListTraverse(Visit_DrawObj);

}

void Free_Win(void)
{

	printf("Level_Win: free\n");
	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload_Win(void)
{
	printf("Level_Win: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
