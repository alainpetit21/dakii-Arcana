#ifndef _MNG_RPG_ITEM_H_
#define _MNG_RPG_ITEM_H_

#include "dfcRPGEngineItems.h"
#include "dfcRPGEngineEntities.h"
#include "dfcRPGEngineSpells.h"
#include "AppArcana.h"

class CRPGItemHerbs	: public CRPGItemUsableOne
{
public:
	CRPGItemHerbs(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemHerbs(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsable::Use(p_pEntUser);
		if((m_pEntDst->m_nHP+= 71) > m_pEntDst->m_nMaxHP)
			m_pEntDst->m_nHP= m_pEntDst->m_nMaxHP;
	};
};

class CRPGItemMedicine	: public CRPGItemUsableOne
{
public:
	CRPGItemMedicine(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemMedicine(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);
		if((m_pEntDst->m_nHP+= 71) > m_pEntDst->m_nMaxHP)
			m_pEntDst->m_nHP= m_pEntDst->m_nMaxHP;
	};
};

class CRPGItemSleepingBag	: public CRPGItemUsableOne
{
public:
	CRPGItemSleepingBag(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemSleepingBag(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		m_pEntDst->m_nHP= m_pEntDst->m_nMaxHP;
		m_pEntDst->m_nMP= m_pEntDst->m_nMaxMP;
	};
};

class CRPGItemReturnRing	: public CRPGItemUsable
{
public:
	CRPGItemReturnRing(int p_nValue, char* p_strID):CRPGItemUsable(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemReturnRing(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsable::Use(p_pEntUser);		
		g_TheAppArcana->SetCurContext(CTX_CITY_GALNIA);
	};
};

class CRPGItemSilverFlask	: public CRPGItemUsableOne
{
public:
	CRPGItemSilverFlask(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemSilverFlask(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nMP+= 71) > m_pEntDst->m_nMaxMP)
			m_pEntDst->m_nMP= m_pEntDst->m_nMaxMP;
	};
};

class CRPGItemRestoreHoney	: public CRPGItemUsableOne
{
public:
	CRPGItemRestoreHoney(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemRestoreHoney(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nMaxHP+= 5) > 999)
			m_pEntDst->m_nMaxHP= 999;
	};
};

class CRPGItemMPHoney	: public CRPGItemUsableOne
{
public:
	CRPGItemMPHoney(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemMPHoney(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nMaxMP+= 5) > 999)
			m_pEntDst->m_nMaxMP= 999;
	};
};

class CRPGItemTent	: public CRPGItemSleepingBag
{
public:
	CRPGItemTent(int p_nValue, char* p_strID):CRPGItemSleepingBag(p_nValue, p_strID){};
	virtual ~CRPGItemTent(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemSleepingBag::Use(p_pEntUser);		
		//Status Petrify & Paraysis
	};
};

class CRPGItemStrengthHoney	: public CRPGItemUsableOne
{
public:
	CRPGItemStrengthHoney(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemStrengthHoney(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nStrength+= 3) > 99)
			m_pEntDst->m_nStrength= 99;
	};
};

class CRPGItemIntelligenceHoney	: public CRPGItemUsableOne
{
public:
	CRPGItemIntelligenceHoney(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemIntelligenceHoney(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nIntellect+= 3) > 99)
			m_pEntDst->m_nIntellect= 99;
	};
};

class CRPGItemEnduranceHoney	: public CRPGItemUsableOne
{
public:
	CRPGItemEnduranceHoney(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemEnduranceHoney(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nConstitution+= 3) > 99)
			m_pEntDst->m_nConstitution= 99;
	};
};

class CRPGItemAgilityHoney	: public CRPGItemUsableOne
{
public:
	CRPGItemAgilityHoney(int p_nValue, char* p_strID):CRPGItemUsableOne(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemAgilityHoney(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableOne::Use(p_pEntUser);		
		if((m_pEntDst->m_nDexterity+= 3) > 99)
			m_pEntDst->m_nDexterity= 99;
	};
};

class CRPGItemElixir	: public CRPGItemUsableList
{
public:
	CRPGItemElixir(int p_nValue, char* p_strID):CRPGItemUsableList(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemElixir(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableList::Use(p_pEntUser);
		for(int i= 0; i < m_nCptEntDst; ++i)
			if((m_pArEntDst[i]->m_nHP+= 5) > m_pArEntDst[i]->m_nMaxHP)
				m_pArEntDst[i]->m_nHP= m_pArEntDst[i]->m_nMaxHP;
	};
};

class CRPGItemFoodA	: public CRPGItemUsableList
{
public:
	CRPGItemFoodA(int p_nValue, char* p_strID):CRPGItemUsableList(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemFoodA(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableList::Use(p_pEntUser);
		for(int i= 0; i < m_nCptEntDst; ++i)
			if((m_pArEntDst[i]->m_nHP+= 10) > m_pArEntDst[i]->m_nMaxHP)
				m_pArEntDst[i]->m_nHP= m_pArEntDst[i]->m_nMaxHP;
	};
};

class CRPGItemFoodB	: public CRPGItemUsableList
{
public:
	CRPGItemFoodB(int p_nValue, char* p_strID):CRPGItemUsableList(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemFoodB(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableList::Use(p_pEntUser);
		for(int i= 0; i < m_nCptEntDst; ++i){
			if((m_pArEntDst[i]->m_nHP+= 10) > m_pArEntDst[i]->m_nMaxHP)
				m_pArEntDst[i]->m_nHP= m_pArEntDst[i]->m_nMaxHP;
			if((m_pArEntDst[i]->m_nMP+= 5) > m_pArEntDst[i]->m_nMaxMP)
				m_pArEntDst[i]->m_nMP= m_pArEntDst[i]->m_nMaxMP;
		}
	};
};

class CRPGItemCard	: public CRPGItemUsableList
{
public:
	CRPGItemCard(int p_nValue, char* p_strID):CRPGItemUsableList(p_nValue, GET_STRING(p_strID), p_strID){};
	virtual ~CRPGItemCard(){}

	virtual void Use(CRPGEntity *p_pEntUser)
	{
		CRPGItemUsableList::Use(p_pEntUser);
	};

	CRPGSpellList	*m_spellAttached;
};

#endif //_MNG_RPG_ITEM_H_
