#ifndef CTX_Story_H
#define CTX_Story_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "dfcSceneEngine.h"
#include "dfcSceneNodes.h"
#include "game.h"

class CCtxStory : public CContext
{
public:
	CCtxStory(const char* p_pRes);
	~CCtxStory(){};

	virtual void Activate(void);
	virtual void Deactivate(void);
	virtual void Manage(unsigned long p_nTimeTick);
	virtual void Update(void);

	CMusic				*m_pMusic;
	CBackgroundLayer	*m_pLayer;
	CSceneEngine		*m_pScnEng;

};

#endif //CTX_Story_H
