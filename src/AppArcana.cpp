#include "lib.h"
#include "libTypes.h"
#include "libMacros.h"
//#include "libMngMemory.h"
#include "AppArcana.h"

#include "CtxLogoDakiisoft.h"
#include "CtxLogoHal.h"
#include "CtxPrologue.h"
#include "CtxTitle.h"
#include "CtxStory.h"
#include "CtxDungeon.h"
#include "CtxNewChapter.h"
#include "CtxCity.h"


CAppArcana	*g_TheAppArcana;

CAppArcana::CAppArcana():
CApp("AppArcana.application"),
m_pRpgEngine(0),
m_nStoryStep(2),
m_guiColor(0x00000000)
{
	m_nCurChar[0]= 1;
	m_nCurChar[1]= 2;
	m_nCurChar[2]= 0;
	m_nCurChar[3]= 0;
}

CAppArcana::~CAppArcana(void)
{
	SAFE_DELETE(m_pRpgEngine);
}

void
CAppArcana::OnPostCreate(void)
{
	m_pRpgEngine= new CRPGArcana();

	Init(MAX_CTX);
	RegisterContext(CTX_DAKIISOFT, new CCtxLogoDakiisoft("CtxLogoDakiisoft.context"));
	RegisterContext(CTX_HAL, new CCtxLogoHal("CtxLogoHal.context"));
	RegisterContext(CTX_PROLOGUE, new CCtxPrologue("CtxPrologue.context"));
	RegisterContext(CTX_TITLE, new CCtxTitle("CtxTitle.context"));
	RegisterContext(CTX_STORY, new CCtxStory("CtxStory.context"));
	RegisterContext(CTX_NEW_CHAPTER, new CCtxNewChapter("CtxNewChapter.context"));
	RegisterContext(CTX_CITY_GALNIA, new CCtxCity("CtxCityGalnia.context", GET_STRING("Galnia")));
	RegisterContext(CTX_DUNGEON_BALNIA, new CCtxDungeon("CtxDungeonBalnia.context", GET_STRING("BalniaTemple1")));

	SetCurContext(CTX_DAKIISOFT);

	CApp::OnPostCreate();
}

CApp*
newGameApp(void)
{
//	GetMngMem()->SetSize(32*1024*1024);
	return g_TheAppArcana= new CAppArcana();
}


ENTRY_POINT("Arcana");
