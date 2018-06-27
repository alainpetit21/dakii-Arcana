#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxPrologue.h"
#include "AppArcana.h"


CCtxPrologue::CCtxPrologue(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxPrologue::Activate(void)
{
	CContext::Activate();

	m_pLblText= (CLabelGradual*)FindByID("LblPrologue");	//Little hack to gain speed get the pt to label and give it a new one empty wich we are going to fill letter by letter

	m_pLblText->SetSpeed(0.75f);


	m_nDelayLogoPrologue= 60;
}

void
CCtxPrologue::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxPrologue::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		System_Quit();
		return;
	}
	if(pMngInput->IsLogicKeyDown(IK_RETURN)){
		g_TheAppArcana->SetCurContext(g_TheAppArcana->GetCurContextID()+1);
		return;
	}

	if(m_pLblText->IsDone())
		if(!(--m_nDelayLogoPrologue)){
			g_TheAppArcana->SetCurContext(g_TheAppArcana->GetCurContextID()+1);
			return;
		}
//	if(m_pLblText->IsDone()){
//		m_pLblText->AppendText(" Bon je vais tester quelque petit truc la");
//	}


	CContext::Manage(p_nTimeTick);
}

void
CCtxPrologue::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
