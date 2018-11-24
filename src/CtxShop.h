#ifndef CTX_Shop_H
#define CTX_Shop_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "game.h"

class CCtxShop : public CContext
{
public:
	CCtxShop(const char* p_pRes);
	~CCtxShop(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);
};

#endif //CTX_Shop_H
