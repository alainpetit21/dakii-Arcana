#ifndef CTX_City_H
#define CTX_City_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfc3DEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "dfcSceneEngine.h"
#include "MngGUIArcana.h"
#include "game.h"

class CCtxCity : public CContext
{
public:
	CCtxCity(const char* p_pRes, char *p_strName);
	~CCtxCity(){};

	virtual CPhysObj*	UserInstall(char *p_dataSource, char* p_id);
	virtual void		Activate(void);
	virtual void		Deactivate(void);
	virtual void		Manage(unsigned long p_nTimeTick);
	virtual void		Update(void);

	void	BuildScene(void);

	//GUI
	CMngGUIArcana		m_mngGUI;
	CMusic				*m_pMusic;
	CCamera2D			*m_pCam2D;

	//Logic
	int					m_nCurCity;
	int					m_nCptPos;
	int					m_nMaxX;
	CDString			m_strCityName;

	//Scene
	CSceneEngine		*m_scnEngine;
};

#endif //CTX_City_H
