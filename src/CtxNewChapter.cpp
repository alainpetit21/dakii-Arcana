#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxNewChapter.h"
#include "AppArcana.h"


CCtxNewChapter::CCtxNewChapter(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxNewChapter::Activate(void)
{
	CContext::Activate();

	m_pMusic= (CMusic*)FindByID("MusNewChapter");
	m_pLabel= (CLabel*)FindByID("LblNewChapter");

	//Set Move to value
	m_pMusic->SetLoop(false);
	m_pMusic->Play();

	if(g_TheAppArcana->m_nStoryStep == 0){
		m_pLabel->SetText(GET_STRING("Chapter1"));
	}
}

void
CCtxNewChapter::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxNewChapter::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		System_Quit();
		return;
	}
	if(pMngInput->IsLogicKeyDown(IK_RETURN)){
		g_TheAppArcana->SetCurContext(CTX_CITY_GALNIA);
		return;
	}
	CContext::Manage(p_nTimeTick);
}

void
CCtxNewChapter::Update()
{
	CContext::Update();
}
