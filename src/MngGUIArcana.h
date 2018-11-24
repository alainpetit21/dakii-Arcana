#ifndef _MNG_GUI_ARCANA_H_
#define _MNG_GUI_ARCANA_H_

#include "dfcContext.h"
#include "dfcLabel.h"
#include "CEntGUIMenuChangeColorGauge.h"

class CMngGUIArcana
{
public :
	CMngGUIArcana();
	~CMngGUIArcana();

	void Init(CContext *p_pContext, char* p_strNamePlace);
	void Manage(u32 p_timeTick);
	void ManageNonBattle(u32 p_timeTick);
	void ManageMenu(u32 p_timeTick);
	void ManageMenuChangeColor(u32 p_timeTick);

	void Update(void);

	void ShowMenu(bool p_bCity);
	bool IsMenuShown(void)		{return m_bShowMenu;};

	CContext *m_pContext;

	//GUI
	CEntity			*m_pCharacter[4];
	CPhysObj		*m_pGUIPhysObj;
	CPhysObj		*m_pGUIMenuPhysObj;
	CEntity			*m_pGUIPane;
	CLabelGradual	*m_pGUITxt;
	CCamera2D		*m_pCam2D;
	CEntity			*m_pGUIMenuCursor;
	void			*m_pBitmapGUI;

	//Logic
	bool			m_bInCity;
	bool			m_bShowMenu;
	bool			m_bShowMenuColor;
	int				m_nPosCursor;
	int				m_nCptTxtEmpty;

	//Menu Color
	CPhysObj					*m_pGUIMenuChangeColorPhysObj;
	CLabel						*m_pLblColorValue[3];
	CEntGUIMenuChangeColorGauge	*m_pEntColor[3];
	CEntity						*m_pGUIMenuChangeColorCursor;
	int							m_nPosCursorMenuChangeColor;
};


#endif //_MNG_GUI_ARCANA_H_
