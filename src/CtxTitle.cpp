#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxTitle.h"
#include "AppArcana.h"


CCtxTitle::CCtxTitle(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxTitle::Activate(void)
{
	CContext::Activate();

	m_pMusic= (CMusic*)FindByID("MusTitle");
	m_pMusic->SetLoop(true);
	m_pMusic->Play();
}

void
CCtxTitle::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxTitle::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		System_Quit();
		return;
	}
	if(pMngInput->IsLogicKeyDown(IK_RETURN)){
		g_TheAppArcana->SetCurContext(CTX_STORY);
		return;
	}
	CContext::Manage(p_nTimeTick);
}

void
CCtxTitle::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
