#ifndef _Arcana_APP_H_
#define _Arcana_APP_H_

#include "dfcApp.h"
#include "dfcFont.h"
#include "MngArcanaRPG.h"

#define CTX_DAKIISOFT		0
#define CTX_HAL				1
#define CTX_PROLOGUE		2
#define CTX_TITLE			3
#define CTX_STORY			4
#define CTX_NEW_CHAPTER		5
#define CTX_CITY_GALNIA		6
#define CTX_DUNGEON_BALNIA	7
#define MAX_CTX				8


class CAppArcana : public CApp
{
public:
	CAppArcana(void);
	virtual ~CAppArcana(void);

	virtual void OnPostCreate(void);

	CRPGArcana	*m_pRpgEngine;

	u32	m_nStoryStep;
	s32	m_nCurChar[4];
	u32	m_guiColor;
};

extern CAppArcana *g_TheAppArcana;

#endif //_Arcana_APP_H_
