#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxStory.h"
#include "AppArcana.h"


CCtxStory::CCtxStory(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxStory::Activate(void)
{
	CContext::Activate();

	m_pMusic= (CMusic*)FindByID("MusStory");
	m_pMusic->SetLoop(true);
	m_pMusic->Play();

	m_pScnEng= (CSceneEngine*)FindByID("ScnStory");

	((CEntity*)FindByID("EntStoryCloudLightning00"))->Hide();
	((CEntity*)FindByID("EntStoryCloudLightning01"))->Hide();
	((CEntity*)FindByID("EntStoryCloudLightning02"))->Hide();
	((CEntity*)FindByID("EntStoryCloudLightning03"))->Hide();
	((CEntity*)FindByID("EntStoryCloudLightning04"))->Hide();

	m_pScnEng->Run(m_pScnEng->GetNodeRoot()->m_arChilds[0]);
//	m_pScnEng->Run(20);
}

void
CCtxStory::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxStory::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		System_Quit();
		return;
	}
	if(m_pScnEng->IsDone()){
		g_TheAppArcana->SetCurContext(g_TheAppArcana->GetCurContextID()+1);
		return;
	}

	CContext::Manage(p_nTimeTick);
}

void
CCtxStory::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
