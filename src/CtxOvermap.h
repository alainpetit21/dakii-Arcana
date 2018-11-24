#ifndef CTX_Overmap_H
#define CTX_Overmap_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "game.h"

class CCtxOvermap : public CContext
{
public:
	CCtxOvermap(const char* p_pRes);
	~CCtxOvermap(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);
};

#endif //CTX_Overmap_H
