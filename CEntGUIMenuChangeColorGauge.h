#ifndef _ENTITY_GUI_MENU_CHANGE_COLOR_GAUGE_H_
#define _ENTITY_GUI_MENU_CHANGE_COLOR_GAUGE_H_

#include "dfcEntity.h"
#include "game.h"

class CEntGUIMenuChangeColorGauge : public CEntity
{
public:
	CEntGUIMenuChangeColorGauge();
	~CEntGUIMenuChangeColorGauge();
	IMPLEMENT_RTTI(EntGUIMenuChangeColorGauge, Entity);

	virtual void Update(void);

	float	m_nValue;
};

#endif //_ENTITY_GUI_MENU_CHANGE_COLOR_GAUGE_H_
