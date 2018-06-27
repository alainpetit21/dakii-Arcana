#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxOvermap.h"
#include "AppArcana.h"


CCtxOvermap::CCtxOvermap(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxOvermap::Activate(void)
{
	CContext::Activate();
}

void
CCtxOvermap::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxOvermap::Manage(unsigned long p_nTimeTick)
{

	CContext::Manage(p_nTimeTick);
}

void
CCtxOvermap::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
