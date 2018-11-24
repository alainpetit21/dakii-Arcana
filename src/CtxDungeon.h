#ifndef CTX_Dungeon_H
#define CTX_Dungeon_H

#include "dfcContext.h"
#include "dfcEntity.h"
#include "dfcLabel.h"
#include "dfcSound.h"
#include "dfcMusic.h"
#include "dfc3DMaze.h"
#include "dfcSceneEngine.h"
#include "MngGUIArcana.h"
#include "game.h"


class CCtxDungeon : public CContext
{
public:
	CCtxDungeon(const char* p_pRes, const char *p_strName);
	~CCtxDungeon(){};

	virtual CPhysObj*	UserInstall(char *p_dataSource, char* p_id);
	virtual void		Activate(void);
	virtual void		Deactivate(void);
	virtual void		Manage(unsigned long p_nTimeTick);
	virtual void		Update(void);

	void Build3DTest(void);

	//GUI
	CMngGUIArcana		m_mngGUI;
	CMusic				*m_pMusic;
	CMaze3D				*m_test;
	CCamera3D			*m_cam3D;
	CCamera2D			*m_cam2D;
	CBackgroundLayer	*m_pBkLayer[2];

	//Logic
	int				nCptFrame;
	CDString		m_strDungeonName;

	//Scene
	CSceneEngine		*m_scnEngine;
};

#endif //CTX_Dungeon_H
