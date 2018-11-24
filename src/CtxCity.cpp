#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "dfcSceneEngine.h"
#include "dfcSceneNodes.h"
#include "CtxCity.h"
#include "CEntGUIMenuChangeColorGauge.h"
#include "AppArcana.h"

#define MAX_DOORS	5
const int g_nPosDoorCities[1][MAX_DOORS]=
{	//Galnia
	{1, 590, 950, 1390, 1950},
};

CCtxCity::CCtxCity(const char* p_pRes, char *p_strName):
CContext(p_pRes),
m_strCityName(p_strName),
m_scnEngine(0)
{
}

void
CCtxCity::BuildScene(void)
{
	switch(g_TheAppArcana->m_nStoryStep)
	{
	case 0:
		m_scnEngine= new CSceneEngine;
		m_scnEngine->LoadInstance("ScnCityGalnia000.scene");
		AddChild(m_scnEngine, false);

		m_pMusic= (CMusic*)FindByID("MusBackgroundStory");
		m_pMusic->Play();

		((CBackgroundLayer*)FindByID("BkCityGalnia_0"))->Hide();
		((CBackgroundLayer*)FindByID("BkCityGalnia_1"))->Hide();
		((CBackgroundLayer*)FindByID("BkCityGalnia_2"))->Hide();
		((CBackgroundLayer*)FindByID("BkCityGalnia_3"))->Hide();
		((CBackgroundLayer*)FindByID("BkCityGalnia_4"))->Hide();
		((CBackgroundLayer*)FindByID("BkCityGalnia_5"))->Hide();
		((CNodeIncVariable*)m_scnEngine->GetNode(24))->SetVarU32(&g_TheAppArcana->m_nStoryStep);
		((CNodeIncVariable*)m_scnEngine->GetNode(159))->SetVarU32(&g_TheAppArcana->m_nStoryStep);
		m_scnEngine->Run(m_scnEngine->GetNodeRoot()->m_arChilds[0]);
	break;
	case 1:
		m_scnEngine= new CSceneEngine;
		m_scnEngine->LoadInstance("ScnCityGalnia000.scene");
		AddChild(m_scnEngine, false);
		((CNodeIncVariable*)m_scnEngine->GetNode(159))->SetVarU32(&g_TheAppArcana->m_nStoryStep);
	default:
		m_pMusic= (CMusic*)FindByID("MusTown");
		m_pMusic->Play();
	break;
	}
}

CPhysObj*
CCtxCity::UserInstall(char *p_dataSource, char* p_id)
{
CPhysObj *pRet= 0;

	if(strcmp(p_id, "CLSID_CEntGUIMenuChangeColorGauge") == 0)
		pRet= new CEntGUIMenuChangeColorGauge;

	return pRet;
}

void
CCtxCity::Activate(void)
{
	CContext::Activate();
	BuildScene();

	m_pCam2D= (CCamera2D*)FindByID("Camera2D");

	//Look for the last backgroundlayer ->City
	int nFounded= -1;
	for(u32 i= 0; i < GetNbChilds(); ++i){
		CObj *pObj= GetChild(i);

		if(pObj->IsKindOf(CLSID_CBackgroundLayer))
			nFounded= i;
	}
	m_nMaxX= GetMngGraphic()->GetWidth(((CBackgroundLayer*)GetChild(nFounded))->m_bitmap);
	m_nCptPos= 0;
	m_nCurCity= 0;

	m_mngGUI.Init(this, m_strCityName.m_arBuffer);
}

void
CCtxCity::Deactivate(void)
{
	CContext::Deactivate();
	m_scnEngine= 0;
}

void
CCtxCity::Manage(unsigned long p_nTimeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if((!m_scnEngine || m_scnEngine->IsDone()) && (!m_mngGUI.IsMenuShown())){
		if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
			System_Quit();
			return;
		}

		if(pMngInput->IsLogicKeyDown(IK_ARROWUP)){
			if((g_TheAppArcana->m_nStoryStep == 1) && (m_nCptPos == 0)){
				m_scnEngine->Run(m_scnEngine->GetNodeRoot()->m_arChilds[1]);
			}else if(m_nCptPos == 0){
				g_TheAppArcana->SetCurContext(CTX_DUNGEON_BALNIA);
				return;
			}

		}

		if(pMngInput->IsLogicKeyDown(IK_ARROWRIGHT)){
			float DoLoopXAdd= 0;

			if((--m_nCptPos) < 0){
				m_nCptPos= MAX_DOORS - 1;
				DoLoopXAdd-= m_nMaxX;
			}

			m_pCam2D->MoveToFreely(int(g_nPosDoorCities[m_nCurCity][m_nCptPos] + DoLoopXAdd), 0, -30, 0.05f, 10.0f, 1.0f, 0.0f);
		}
		if(pMngInput->IsLogicKeyDown(IK_ARROWLEFT)){
			float DoLoopXAdd= 0;

			if((++m_nCptPos) >= MAX_DOORS){
				m_nCptPos= 0;
				DoLoopXAdd+= m_nMaxX;
			}

			m_pCam2D->MoveToFreely(float(g_nPosDoorCities[m_nCurCity][m_nCptPos]) + DoLoopXAdd, 0, -30, 0.05f, 10.0f, 1.0f, 0.0f);
		}

		if(pMngInput->IsLogicKeyDown(IK_RETURN)){
			m_mngGUI.ShowMenu(true);
		}
	}

	if(m_pCam2D->m_pos[0] > m_nMaxX){
		m_pCam2D->m_pos[0]-= m_nMaxX;
		m_pCam2D->m_posTo[0]-= m_nMaxX;
	}
	if(m_pCam2D->m_pos[0] < 0){
		m_pCam2D->m_pos[0]+= m_nMaxX;
		m_pCam2D->m_posTo[0]+= m_nMaxX;
	}

	m_mngGUI.Manage(p_nTimeTick);
	CContext::Manage(p_nTimeTick);
}

void
CCtxCity::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	m_mngGUI.Update();
	CContext::Update();
}
