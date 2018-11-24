#ifndef CTX_Prologue_H
#define CTX_Prologue_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "game.h"

class CCtxPrologue : public CContext
{
public:
	CCtxPrologue(const char* p_pRes);
	~CCtxPrologue(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);

	CLabelGradual	*m_pLblText;

	int				m_nDelayLogoPrologue;
};

#endif //CTX_TITLE_H
