#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "CEntGUIMenuChangeColorGauge.h"
#include "AppArcana.h"


CEntGUIMenuChangeColorGauge::CEntGUIMenuChangeColorGauge():
CEntity()
{
}

CEntGUIMenuChangeColorGauge::~CEntGUIMenuChangeColorGauge(void)
{
}

void
CEntGUIMenuChangeColorGauge::Update(void)
{
CMngGraphic	*pRenderer	= GetMngGraphic();
int i;

	Show(int(m_nValue));

	if(!m_isShown)
		return;

	CCamera2D::GetCurrent()->Project(this);
	for(i= 0; i < int(m_nValue); ++i)
		pRenderer->DrawFrame(pRenderer->GetBB(), s32(m_posProjected[0]+(i*16)), s32(m_posProjected[1]), 0, m_zoom, 0, &m_pCurAnim[(int)m_indexFrame]);

	CPhysObj::Update();
}
