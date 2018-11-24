#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxLogoHal.h"
#include "AppArcana.h"


CCtxLogoHal::CCtxLogoHal(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxLogoHal::Activate(void)
{
	CContext::Activate();


	//Get pt to Background objects
	m_pObjBackWindow		= (CBackgroundLayer*)FindByID("BkLogoHal_3");
	m_pObjBackHal			= (CBackgroundLayer*)FindByID("BkLogoHal_0");
	m_pObjBackStripeNorth	= (CBackgroundLayer*)FindByID("BkLogoHal_1");
	m_pObjBackStripeSouth	= (CBackgroundLayer*)FindByID("BkLogoHal_2");
	m_pMusic				= (CMusic*)FindByID("MusHalLogo");

	//Do the HAL logo animation
	//Set initial Position
	m_pObjBackHal->SetPos(960, 240, m_pObjBackHal->GetPosZ());
	m_pObjBackStripeNorth->SetPos(320, 480, m_pObjBackStripeNorth->GetPosZ());
	m_pObjBackStripeSouth->SetPos(320, 0, m_pObjBackStripeSouth->GetPosZ());

	//Set Move to value TODO
	m_pObjBackHal->MoveToFreely(320, 240, m_pObjBackHal->GetPosZ(), 1, 6, 0.5f, 0);
	m_pObjBackWindow->MoveToFreely(960, 240, m_pObjBackWindow->GetPosZ(), 1, 8, 0.5f, 0);
	m_pObjBackStripeNorth->MoveToFreely(320, 240, m_pObjBackStripeNorth->GetPosZ(), 1, 2.25, 0.5f, 0);
	m_pObjBackStripeSouth->MoveToFreely(320, 240, m_pObjBackStripeSouth->GetPosZ(), 1, 2.25, 0.5f, 0);

	//Set Move to value
	m_pMusic->SetLoop(false);
	m_pMusic->Play();

	m_nDelayLogoHal= 60*6;
}

void
CCtxLogoHal::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxLogoHal::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(!(--m_nDelayLogoHal)){
		g_TheAppArcana->SetCurContext(g_TheAppArcana->GetCurContextID()+1);
		return;
	}
	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		System_Quit();
		return;
	}

	CContext::Manage(p_nTimeTick);
}

void
CCtxLogoHal::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
