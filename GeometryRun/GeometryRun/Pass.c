#include "Lose.h"

clock_t timeStart_level_Pass;


void Load_Pass(void)
{
	// ��ʼ��ʱ��ϵͳ
	//TimerIni(&timeStart_level_Pass);

	printf("Level_Pass: Load\n");
	theBaseList = NULL;
	// ���ó���
	SetConstants();
	// ��ʼ����Ϸ��������ʵ���б�
	InitialGameObjBaseList(&theBaseList);

	BackGroundLoad();
}

void Ini_Pass(void)
{
	printf("Level_Pass: Ini\n");
	// ��ȡ��ǰ�ؿ�ʱ��
	//timeStart_level_Pass = clock();
	BackGroundStart();

	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, iniPosition_Background, iniVelocity_Background, 0, theBaseList, 0, NULL);

}

void Update_Pass(void)
{
	Vector2D iniPosition_Block;
	Vector2D iniVelocity_Block;

	GetWinMaxMinXY();

	// =========================
	// ��Ϸ�߼���Ӧ����
	// =========================
	KeyUpdate();

	//if (endPause)
	//{
	//	// ���¼�������ͣ�ӳٵ�ʱ��
	//	timeStart_level_Pass += pauseEndTime - pauseStartTime;
	//	endPause = FALSE;
	//}

	/*if (!isPaused)
	{*/
	//TimerUpdate(timeStart_level_Pass);

	// =====================================
	// �������ж����2D�任����
	// =====================================
	BaseListTraverse(Visit_Matrix2DCount);
	//}
}

void Draw_Pass(void)
{
	// Ϊ��ʼ��������׼��
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// ������ƶ����б��е����ж���
	BaseListTraverse(Visit_DrawObj);

}

void Free_Pass(void)
{

	printf("Level_Pass: free\n");
	// ʹ�ú���gameObjDestroyɾ���б��еĶ���
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload_Pass(void)
{
	printf("Level_Pass: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
