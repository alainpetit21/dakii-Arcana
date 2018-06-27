#ifndef CTX_NewChapter_H
#define CTX_NewChapter_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "game.h"

class CCtxNewChapter : public CContext
{
public:
	CCtxNewChapter(const char* p_pRes);
	~CCtxNewChapter(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);

	CMusic	*m_pMusic;
	CLabel	*m_pLabel;
};

#endif //CTX_NewChapter_H
