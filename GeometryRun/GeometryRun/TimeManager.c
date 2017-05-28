#include "TimeManager.h"

static Status SetCreateRange(Timer *pTimer, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir);

static Status SetBaseObjToCreate(Timer *pTimer, unsigned long theType, AEGfxVertexList* theMesh, AEGfxTexture* theTexture, GameObjBaseList L);

static Status SetObjToCreate(Timer *pTimer, unsigned long theType, float scale, GameObjBaseList L, int thePropertyCount, Property* theProperties);

static float GetRanFloatFromTo(float min, float max);

static Status GetRandomPosVelAndDir(Vector2D* thePos, Vector2D* theVel, float *theDir, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir);

Status TimerIni(time_t* LevelTime)
{
	int i;
	time(LevelTime);
	for (i = 0; i < MaxTimers; i++)
		Timers[i].flag = FLAG_INACTIVE;
	timerCount = 0;
	srand(time(0));
	return OK;
}

static Status SetCreateRange(Timer *pTimer, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir)
{
	pTimer->properties.iniMaxX = theIniMinX;
	pTimer->properties.iniMaxX = theIniMaxX;
	pTimer->properties.iniMinY = theIniMinY;
	pTimer->properties.iniMaxY = theIniMaxY;
	pTimer->properties.iniMinVx = theIniMinVx;
	pTimer->properties.iniMaxVx = theIniMaxVx;
	pTimer->properties.iniMinVy = theIniMinVy;
	pTimer->properties.iniMaxVy = theIniMaxVy;
	pTimer->properties.iniMinDir = theIniMinDir;
	pTimer->properties.iniMaxDir = theIniMaxDir;
	return OK;
}

static Status SetBaseObjToCreate(Timer *pTimer, unsigned long theType, AEGfxVertexList* theMesh, AEGfxTexture* theTexture, GameObjBaseList L)
{
	pTimer->properties.t_BaseType = theType;
	pTimer->properties.t_Mesh = theMesh;
	pTimer->properties.t_Texture = theTexture;
	pTimer->properties.t_L = L;
	return OK;
}

Status CreateBaseObjAtTime(unsigned long theType, AEGfxVertexList* theMesh, AEGfxTexture* theTexture, GameObjBaseList L, float theTime)
{
	int i;
	for (i = 0; i < MaxTimers; i++)
	{
		if (Timers[i].flag == FLAG_INACTIVE)
		{
			timerCount++;
			Timers[i].flag = FLAG_ACTIVE;
			Timers[i].type = TTYPE_BASEOBJ;
			Timers[i].time = theTime;
			SetBaseObjToCreate(&Timers[i], theType, theMesh, theTexture, L);
		}
	}
	return ERROR;
}

static Status SetObjToCreate(Timer *pTimer, unsigned long theType, float scale, GameObjBaseList L, int thePropertyCount, Property* theProperties)
{
	int i;
	pTimer->properties.t_Type = theType;
	pTimer->properties.t_Scale = scale;
	pTimer->properties.t_L = L;
	pTimer->properties.t_PropertyCount = thePropertyCount;
	for (i = 0; i < thePropertyCount; i++)
		pTimer->properties.t_Properties[i] = theProperties[i];
	return OK;
}

Status CreateOneObjAtTime(float theTime, unsigned long theType, float scale, Vector2D Pos, Vector2D Vel, float dir, GameObjBaseList L, int thePropertyCount, Property* theProperties)
{
	int i;
	for (i = 0; i < MaxTimers; i++)
	{
		if (Timers[i].flag == FLAG_INACTIVE)
		{
			timerCount++;
			Timers[i].flag = FLAG_ACTIVE;
			Timers[i].type = TTYPE_OBJ;
			Timers[i].time = theTime;
			Timers[i].properties.t_Pos = Pos;
			Timers[i].properties.t_Vel = Vel;
			Timers[i].properties.t_Dir = dir;
			SetObjToCreate(&Timers[i], theType, scale, L, thePropertyCount, theProperties);
			return OK;
		}
	}
	return ERROR;
}

Status CreateOneObjAtTimeWithRange(float theTime, unsigned long theType, float scale, GameObjBaseList L, int thePropertyCount, Property* theProperties, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir)
{
	int i;
	for (i = 0; i < MaxTimers; i++)
	{
		if (Timers[i].flag == FLAG_INACTIVE)
		{
			timerCount++;
			Timers[i].flag = FLAG_ACTIVE;
			Timers[i].type = TTYPE_OBJ_RANDOM;
			Timers[i].time = theTime;
			SetCreateRange(&Timers[i], theIniMinX, theIniMaxX, theIniMinY, theIniMaxY, theIniMinVx, theIniMaxVx, theIniMinVy, theIniMaxVy, theIniMinDir, theIniMaxDir);
			SetObjToCreate(&Timers[i], theType, scale, L, thePropertyCount, theProperties);
			return OK;
		}
	}
	return ERROR;
}

Status CreateSomeObjAtSameTimeWithRange(float theTime, int theAmountToCreate, unsigned long theType, float scale, GameObjBaseList L, int thePropertyCount, Property* theProperties, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir)
{
	int i;
	for (i = 0; i < MaxTimers; i++)
	{
		if (Timers[i].flag == FLAG_INACTIVE)
		{
			timerCount++;
			Timers[i].flag = FLAG_ACTIVE;
			Timers[i].type = TTYPE_SOMEOBJ;
			Timers[i].time = theTime;
			Timers[i].properties.amountToCreate = theAmountToCreate;
			SetCreateRange(&Timers[i], theIniMinX, theIniMaxX, theIniMinY, theIniMaxY, theIniMinVx, theIniMaxVx, theIniMinVy, theIniMaxVy, theIniMinDir, theIniMaxDir);
			SetObjToCreate(&Timers[i], theType, scale, L, thePropertyCount, theProperties);
			return OK;
		}
	}
	return ERROR;
}

static float GetRanFloatFromTo(float min, float max)
{
	float f;
	int i;
	i = rand() % 1000;
	f = min + (max - min) * ((float)i / 1000.0f);
	return f;
}

static Status GetRandomPosVelAndDir(Vector2D* thePos, Vector2D* theVel, float *theDir, float theIniMinX, float theIniMaxX, float theIniMinY, float theIniMaxY, float theIniMinVx, float theIniMaxVx, float theIniMinVy, float theIniMaxVy, float theIniMinDir, float theIniMaxDir)
{
	thePos->x = GetRanFloatFromTo(theIniMinX, theIniMaxX);
	thePos->y = GetRanFloatFromTo(theIniMinY, theIniMaxY);
	theVel->x = GetRanFloatFromTo(theIniMinVx, theIniMaxVx);
	theVel->y = GetRanFloatFromTo(theIniMinVy, theIniMaxVy);
	*theDir = GetRanFloatFromTo(theIniMinDir, theIniMaxDir);
	return OK;
}

Status TimerUpdate(time_t LevelTime)
{
	int i, dealTimers = 0, j;
	double passTime;
	time_t poiTime;
	Vector2D iniPos, iniVel;
	float iniDir;
	time(&poiTime);
	passTime = difftime(poiTime, LevelTime);

	for (i = 0; i < MaxTimers && dealTimers < timerCount; i++)
	{
		if (Timers[i].flag == FLAG_INACTIVE)
			continue;
		else
		{
			dealTimers++;
			if (passTime >= Timers[i].time)
			{
				switch (Timers[i].type)
				{
				case TTYPE_BASEOBJ:
				{
					CreateGameObjBase(Timers[i].properties.t_Type, Timers[i].properties.t_Mesh, Timers[i].properties.t_Texture, Timers[i].properties.t_L);
					Timers[i].flag = FLAG_INACTIVE;
					break;
				}
				case TTYPE_OBJ:
				{
					CreateGameObj(Timers[i].properties.t_Type, Timers[i].properties.t_Scale, Timers[i].properties.t_Pos, Timers[i].properties.t_Vel, Timers[i].properties.t_Dir, Timers[i].properties.t_L, Timers[i].properties.t_PropertyCount, Timers[i].properties.t_Properties);
					Timers[i].flag = FLAG_INACTIVE;
					break;
				}
				case TTYPE_OBJ_RANDOM:
				{
					GetRandomPosVelAndDir(&iniPos, &iniVel, &iniDir, Timers[i].properties.iniMinX, Timers[i].properties.iniMaxX, Timers[i].properties.iniMinY, Timers[i].properties.iniMaxY, Timers[i].properties.iniMinVx, Timers[i].properties.iniMaxVx, Timers[i].properties.iniMinVy, Timers[i].properties.iniMaxVy, Timers[i].properties.iniMinDir, Timers[i].properties.iniMaxDir);
					CreateGameObj(Timers[i].properties.t_Type, Timers[i].properties.t_Scale, iniPos, iniVel, iniDir, Timers[i].properties.t_L, Timers[i].properties.t_PropertyCount, Timers[i].properties.t_Properties);
					Timers[i].flag = FLAG_INACTIVE;
					break;
				}
				case TTYPE_SOMEOBJ:
				{
					for (j = 0; j < Timers[i].properties.amountToCreate; j++)
					{
						GetRandomPosVelAndDir(&iniPos, &iniVel, &iniDir, Timers[i].properties.iniMinX, Timers[i].properties.iniMaxX, Timers[i].properties.iniMinY, Timers[i].properties.iniMaxY, Timers[i].properties.iniMinVx, Timers[i].properties.iniMaxVx, Timers[i].properties.iniMinVy, Timers[i].properties.iniMaxVy, Timers[i].properties.iniMinDir, Timers[i].properties.iniMaxDir);
						CreateGameObj(Timers[i].properties.t_Type, Timers[i].properties.t_Scale, iniPos, iniVel, iniDir, Timers[i].properties.t_L, Timers[i].properties.t_PropertyCount, Timers[i].properties.t_Properties);
					}
					Timers[i].flag = FLAG_INACTIVE;
					break;
				}
				default:
						break;
				}
			}
		}
	}
	return OK;
}

Status TimerFree()
{
	int i;
	timerCount = 0;
	for (i = 0; i < MaxTimers; i++)
		Timers[i].flag = FLAG_INACTIVE;
	return OK;
}
