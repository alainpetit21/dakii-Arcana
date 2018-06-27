#ifndef CTX_Title_H
#define CTX_Title_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "game.h"

class CCtxTitle : public CContext
{
public:
	CCtxTitle(const char* p_pRes);
	~CCtxTitle(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);

	CMusic				*m_pMusic;
};

#endif //CTX_TITLE_H
