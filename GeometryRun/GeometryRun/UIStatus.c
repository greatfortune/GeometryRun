#include "UIStatus.h"

float defaultUIStatusScale, defaultUINumber;	// ³ß´ç

static GameObj *pUINumber_HP, *pUINumber_Bullet, *pUINumber_Score[3];

static Vector2D UIStatusPos;
static Vector2D UINumberPos_Level_HP, UINumberPos_Level_Bullet;
static Vector2D UINumberPos_Unlimited_HP, UINumberPos_Unlimited_Bullet, UINumberPos_Unlimited_Score[3];

static float iniY, HP_Level_iniX, Bullet_Level_iniX, offX;
static float HP_Unlimited_iniX, Bullet_Unlimited_iniX, Score_Unlimited_iniX;
static int UIScore[SIZE_SCORE];

Status UIStatusLoad()
{
	// ========================
	// UIStatus
	// ========================
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -0.08f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -0.08f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 0.08f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -0.08f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 0.08f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 0.08f, COLOR_DEFAULT, 0.0f, 0.0f);
	if (Current == GS_L4)
		CreateGameObjBase(OTYPE_UI_STATUS, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/background/status_unlimited.png"), theBaseList);
	else
		CreateGameObjBase(OTYPE_UI_STATUS, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/background/status_level.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_0, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number0.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_1, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number1.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_2, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number2.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_3, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number3.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_4, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number4.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_5, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number5.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_6, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number6.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_7, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number7.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_8, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number8.png"), theBaseList);
	AEGfxMeshStart();
	AEGfxTriAdd(
		-1.0f, -1.0f, COLOR_DEFAULT, 0.0f, 1.0f,
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	AEGfxTriAdd(
		1.0f, -1.0f, COLOR_DEFAULT, 1.0f, 1.0f,
		1.0f, 1.0f, COLOR_DEFAULT, 1.0f, 0.0f,
		-1.0f, 1.0f, COLOR_DEFAULT, 0.0f, 0.0f);
	CreateGameObjBase(OTYPE_UI_NUMBER_9, AEGfxMeshEnd(), AEGfxTextureLoad("source/image/number/number9.png"), theBaseList);

	return OK;
}

Status UIStatusStart()
{
	int i = 0;
	defaultUIStatusScale = 400.0f, defaultUINumber = 30.0f;
	iniY = -250.0f, HP_Level_iniX = -300.0f, Bullet_Level_iniX = 120.0f, offX = 40.0f;
	HP_Unlimited_iniX = -300.0f, Bullet_Unlimited_iniX = -40.0f, Score_Unlimited_iniX = 180.0f;
	memset(UIScore, 0, sizeof(int)* 4);
	Vector2DSet(&UIStatusPos, 0.0f, iniY);
	Vector2DSet(&UINumberPos_Level_HP, HP_Level_iniX, iniY);
	Vector2DSet(&UINumberPos_Level_Bullet, Bullet_Level_iniX, iniY);
	Vector2DSet(&UINumberPos_Unlimited_HP, HP_Unlimited_iniX, iniY);
	Vector2DSet(&UINumberPos_Unlimited_Bullet, Bullet_Unlimited_iniX, iniY);
	for (i = 0; i < SIZE_SCORE; i++)
		Vector2DSet(&UINumberPos_Unlimited_Score[i], Score_Unlimited_iniX + offX * i, iniY);
	CreateGameObj(OTYPE_UI_STATUS, defaultUIStatusScale, UIStatusPos, zero, 0, theBaseList, 0, NULL);
	if (Current == GS_L4)
	{
		pUINumber_HP = CreateGameObj(OTYPE_UI_NUMBER_0, defaultUINumber, UINumberPos_Unlimited_HP, zero, 0, theBaseList, 0, NULL);
		pUINumber_Bullet = CreateGameObj(OTYPE_UI_NUMBER_0, defaultUINumber, UINumberPos_Unlimited_Bullet, zero, 0, theBaseList, 0, NULL);
		for (i = 0; i < SIZE_SCORE; i++)
			pUINumber_Score[i] = CreateGameObj(OTYPE_UI_NUMBER_0, defaultUINumber, UINumberPos_Unlimited_Score[i], zero, 0, theBaseList, 0, NULL);
	}
	else
	{
		pUINumber_HP = CreateGameObj(OTYPE_UI_NUMBER_0, defaultUINumber, UINumberPos_Level_HP, zero, 0, theBaseList, 0, NULL);
		pUINumber_Bullet = CreateGameObj(OTYPE_UI_NUMBER_0, defaultUINumber, UINumberPos_Level_Bullet, zero, 0, theBaseList, 0, NULL);
	}

	return OK;
}

Status UIStatusUpdate()
{
	int i;
	int CurPlayerHP = PlayerHPGet();
	int CurPlayerCountBullet = PlayerBulletCountGet();
	int CurPlayerScore = PlayerScoreGet();
	if (Current != GS_L4)
	{
		if (CurPlayerHP != pUINumber_HP->pObject->type - OTYPE_UI_NUMBER_0)
		{
			GameObjDelete(pUINumber_HP);
			pUINumber_HP = CreateGameObj(OTYPE_UI_NUMBER_0 + CurPlayerHP, defaultUINumber, UINumberPos_Level_HP, zero, 0, theBaseList, 0, NULL);
		}
		if (CurPlayerCountBullet != pUINumber_Bullet->pObject->type - OTYPE_UI_NUMBER_0)
		{
			GameObjDelete(pUINumber_Bullet);
			pUINumber_Bullet = CreateGameObj(OTYPE_UI_NUMBER_0 + CurPlayerCountBullet, defaultUINumber, UINumberPos_Level_Bullet, zero, 0, theBaseList, 0, NULL);
		}
	}
	else
	{
		if (CurPlayerHP != pUINumber_HP->pObject->type - OTYPE_UI_NUMBER_0)
		{
			GameObjDelete(pUINumber_HP);
			pUINumber_HP = CreateGameObj(OTYPE_UI_NUMBER_0 + CurPlayerHP, defaultUINumber, UINumberPos_Unlimited_HP, zero, 0, theBaseList, 0, NULL);
		}
		if (CurPlayerCountBullet != pUINumber_Bullet->pObject->type - OTYPE_UI_NUMBER_0)
		{
			GameObjDelete(pUINumber_Bullet);
			pUINumber_Bullet = CreateGameObj(OTYPE_UI_NUMBER_0 + CurPlayerCountBullet, defaultUINumber, UINumberPos_Unlimited_Bullet, zero, 0, theBaseList, 0, NULL);
		}
		UIScore[0] = CurPlayerScore / 1000 % 10;
		UIScore[1] = CurPlayerScore / 100 % 10;
		UIScore[2] = CurPlayerScore / 10 % 10;
		UIScore[3] = CurPlayerScore % 10;

		for (i = 0; i < SIZE_SCORE; i++)
			if (UIScore[i] != pUINumber_Score[i]->pObject->type - OTYPE_UI_NUMBER_0)
				{
					GameObjDelete(pUINumber_Score[i]);
					pUINumber_Score[i] = CreateGameObj(OTYPE_UI_NUMBER_0 + UIScore[i], defaultUINumber, UINumberPos_Unlimited_Score[i], zero, 0, theBaseList, 0, NULL);
				}
	}
	return OK;
}

float UIStatusScaleGet()
{
	return defaultUIStatusScale;
}
