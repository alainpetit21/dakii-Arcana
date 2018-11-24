#ifndef CTX_LogoHal_H
#define CTX_LogoHal_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "dfcBackground.h"
#include "game.h"

class CCtxLogoHal : public CContext
{
public:
	CCtxLogoHal(const char* p_pRes);
	~CCtxLogoHal(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);

	//Gui shortcut
	CBackgroundLayer	*m_pObjBackWindow;
	CBackgroundLayer	*m_pObjBackHal;
	CBackgroundLayer	*m_pObjBackStripeNorth;
	CBackgroundLayer	*m_pObjBackStripeSouth;
	CMusic				*m_pMusic;

	int	m_nDelayLogoHal;
};

#endif //CTX_TITLE_H
