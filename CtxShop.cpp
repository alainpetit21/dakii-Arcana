#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxShop.h"
#include "AppArcana.h"


CCtxShop::CCtxShop(const char* p_pRes):
CContext(p_pRes)
{
}

void
CCtxShop::Activate(void)
{
	CContext::Activate();
}

void
CCtxShop::Deactivate(void)
{
	CContext::Deactivate();
}

void
CCtxShop::Manage(unsigned long p_nTimeTick)
{

	CContext::Manage(p_nTimeTick);
}

void
CCtxShop::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
