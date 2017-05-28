#include <time.h>
#include "GameObjectManager.h"
#include <stdlib.h>
#include <math.h>

#define MaxTimers 1000

enum TimerType{
	TTYPE_BASEOBJ,
	TTYPE_OBJ_RANDOM,
	TTYPE_OBJ,
	TTYPE_SOMEOBJ
};

typedef struct{
	unsigned long t_BaseType, t_Type;
	AEGfxVertexList* t_Mesh;
	AEGfxTexture* t_Texture;
	GameObjBaseList t_L;
	float t_Scale, t_Dir;
	Vector2D t_Pos, t_Vel;
	int t_PropertyCount, amountToCreate;
	Property t_Properties[MAXPROPERTIES];
	float iniMinX, iniMaxX, iniMinY, iniMaxY, iniMinVx, iniMaxVx, iniMinVy, iniMaxVy, iniMinDir, iniMaxDir;
}TimerProperties;
// 此处结构体过大，应拆分

typedef struct{
	int flag;
	int type;
	float time;
	TimerProperties properties;
}Timer;

Timer Timers[MaxTimers];
int timerCount;

Status TimerIni(time_t* LevelTime);

Status CreateBaseObjAtTime(unsigned long theType, AEGfxVertexList* theMesh, AEGfxTexture* theTexture, GameObjBaseList L, float theTime);

Status CreateOneObjAtTime(float theTime, unsigned long theType, float scale, Vector2D Pos, Vector2D Vel, float dir, GameObjBaseList L, int thePropertyCount, Property* theProperties);

Status CreateOneObjAtTimeWithRange(float theTime, unsigned long theType, float scale, GameObjBaseList L, int thePropertyCount, Property* theProperties, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir);

Status CreateSomeObjAtSameTimeWithRange(float theTime, int theAmountToCreate, unsigned long theType, float scale, GameObjBaseList L, int thePropertyCount, Property* theProperties, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir);

Status TimerUpdate(time_t LevelTime);

Status TimerFree();
