#ifndef CTX_LogoDakiisoft_H
#define CTX_LogoDakiisoft_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "game.h"

class CCtxLogoDakiisoft : public CContext
{
public:
	CCtxLogoDakiisoft(const char* p_pRes):CContext(p_pRes){};
	~CCtxLogoDakiisoft(){};

	virtual void Activate(void);
	virtual void Manage(unsigned long p_nTimeTick);

	int	m_nDelayLogoDakiisoft;
};

#endif //CTX_TITLE_H
