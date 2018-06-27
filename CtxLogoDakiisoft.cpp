#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "CtxLogoDakiisoft.h"
#include "AppArcana.h"


void
CCtxLogoDakiisoft::Activate(void)
{
	CContext::Activate();

	m_nDelayLogoDakiisoft= 120;
}

void
CCtxLogoDakiisoft::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(!(--m_nDelayLogoDakiisoft)){
		g_TheAppArcana->SetCurContext(g_TheAppArcana->GetCurContextID()+1);
		return;
	}
	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		System_Quit();
		return;
	}

	CContext::Manage(p_nTimeTick);
}

