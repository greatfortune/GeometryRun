#include "Choose.h"

void Load_Choose(void)
{
	// 初始化时间系统
	//TimerIni(&timeStart_level_Lose);

	printf("Level_Choose: Load\n");
	theBaseList = NULL;
	// 设置常量
	SetConstants();
	// 初始化游戏对象基类的实例列表
	InitialGameObjBaseList(&theBaseList);

	BackGroundLoad();
}

void Ini_Choose(void)
{
	printf("Level_Choose: Ini\n");
	// 获取当前关卡时间
	//timeStart_level_Lose = clock();
	BackGroundStart();

	CreateGameObj(OTYPE_BACKGROUND, SIZE_BACKGROUND, iniPosition_Background, iniVelocity_Background, 0, theBaseList, 0, NULL);



}

void Update_Choose(void)
{
	GetWinMaxMinXY();

	// =========================
	// 游戏逻辑响应输入
	// =========================
	KeyUpdate();

	// 更新对象
	ObjUpdate();

	// =====================================
	// 计算所有对象的2D变换矩阵
	// =====================================
	BaseListTraverse(Visit_Matrix2DCount);
}

void Draw_Choose(void)
{
	// 为开始画对象做准备
	AEGfxSetBackgroundColor(0.0f, 0.0f, 0.0f);
	AEGfxSetBlendMode(AE_GFX_RM_TEXTURE);
	AEGfxSetRenderMode(AE_GFX_RM_TEXTURE);
	// 逐个绘制对象列表中的所有对象
	BaseListTraverse(Visit_DrawObj);

}

void Free_Choose(void)
{

	printf("Level_Choose: free\n");
	// 使用函数gameObjDestroy删除列表中的对象
	BaseListTraverse(Visit_DestroyObj);
	TimerFree();
}

void Unload_Choose(void)
{
	printf("Level_Choose: Unload\n");
	DestroyGameObjBaseList(&theBaseList);
}
