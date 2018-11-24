#include "lib.h"
#include "libMacros.h"
#include "libTypes.h"
#include "libMngInput.h"
#include "libMngSound.h"
#include "dfcApp.h"
#include "CtxDungeon.h"
#include "CEntGUIMenuChangeColorGauge.h"
#include "AppArcana.h"

CCtxDungeon::CCtxDungeon(const char* p_pRes, const char *p_strName):
CContext(p_pRes),
m_strDungeonName(p_strName),
m_scnEngine(0)
{
}

CPhysObj*
CCtxDungeon::UserInstall(char *p_dataSource, char* p_id)
{
CPhysObj *pRet= 0;

	if(strcmp(p_id, "CLSID_CEntGUIMenuChangeColorGauge") == 0)
		pRet= new CEntGUIMenuChangeColorGauge;

	return pRet;
}

void
CCtxDungeon::Activate(void)
{
	CContext::Activate();

	m_pMusic= (CMusic*)FindByID("MusDungeonTest");
	m_pMusic->SetLoop(true);
	m_pMusic->Play();

	m_test	= (CMaze3D*)FindByID("MazeBalniaTemple");
	m_cam3D	= (CCamera3D*)FindByID("Camera3D");
	m_cam3D->SetPos(m_test->m_startingPos);
	m_cam3D->SetAngle(-HALF_PI, m_test->m_startingAngleY, 0);

	m_cam2D	= (CCamera2D*)FindByID("Camera2D");
	m_cam2D->SetPos(0, 0, -5);

	m_pBkLayer[0]= (CBackgroundLayer*)FindByID("BkDungeonTest_0");
	m_pBkLayer[1]= (CBackgroundLayer*)FindByID("BkDungeonTest_1");
	m_mngGUI.Init(this, m_strDungeonName.m_arBuffer);
}

void
CCtxDungeon::Deactivate(void)
{
	CContext::Deactivate();
	m_scnEngine= 0;
}

void
CCtxDungeon::Manage(unsigned long p_nTimeTick)
{/*
CMngInput	*pMngInput 	= GetMngInput();
int			incX, incY;
float		nextRight, nextLeft;
float		posCamX= (m_cam3D->GetPosX()>=0)?m_cam3D->GetPosX()+0.5f:m_cam3D->GetPosX()-0.5f;
float		posCamY= (m_cam3D->GetPosY()>=0)?m_cam3D->GetPosY()+0.5f:m_cam3D->GetPosY()-0.5f;

	if(ABS(m_cam3D->GetAngleY() - 0) < 0.5){	//Facing North
		incX= 0;
		incY= 1;
		nextRight= -(PI/2);
		nextLeft= (PI/2);
	}else if(ABS(m_cam3D->GetAngleY() - PI) < 0.5){	//Facing South
		incX= 0;
		incY= -1;
		nextRight= (PI/2);
		nextLeft= -(PI/2);
	}else if(ABS(m_cam3D->GetAngleY() - -(PI/2)) < 0.5){	//Facing East
		incX= -1;
		incY= 0;
		nextRight= PI;
		nextLeft= 0;
	}else if(ABS(m_cam3D->GetAngleY() - (PI/2)) < 0.5){	//Facing West
		incX= 1;
		incY= 0;
		nextRight= 0;
		nextLeft= PI;
	}

	if((!m_scnEngine || m_scnEngine->IsDone()) && (!m_mngGUI.IsMenuShown())){
		if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
			System_Quit();
			return;
		}

		if(!m_cam3D->IsRotating()){
			if(pMngInput->IsKeyDown(IK_ARROWUP)){
				switch(m_test->GetCollision(int(posCamX)+incX, int(posCamY)+incY)){
				case 2:
					g_TheAppArcana->SetCurContext(CTX_CITY_GALNIA);
					return;
				break;
				case 3:
					m_cam3D->MoveToMap(int(posCamX)+incX, int(posCamY)+incY, int(m_cam3D->GetPosZ())-1 - 0.4f, 0.05f, 0.05f, 0.5f, 0.0f);
				break;
				case 4:
					m_cam3D->MoveToMap(int(posCamX)+incX, int(posCamY)+incY, int(m_cam3D->GetPosZ())+1 - 0.4f, 0.05f, 0.05f, 0.5f, 0.0f);
				break;
				case 0:
					m_cam3D->MoveToMap(int(posCamX)+incX, int(posCamY)+incY, m_cam3D->GetPosZ(), 0.05f, 0.05f, 0.5f, 0.0f);
				break;
				}
			}else if(pMngInput->IsKeyDown(IK_ARROWDOWN)){
				switch(m_test->GetCollision(int(posCamX)-incX, int(posCamY)-incY)){
				case 2:
					g_TheAppArcana->SetCurContext(CTX_CITY_GALNIA);
					return;
				break;
				case 3:
					m_cam3D->MoveToMap(int(posCamX)-incX, int(posCamY)-incY, int(m_cam3D->GetPosZ())-1 - 0.4f, 0.05f, 0.05f, 0.5f, 0.0f);
				break;
				case 4:
					m_cam3D->MoveToMap(int(posCamX)-incX, int(posCamY)-incY, int(m_cam3D->GetPosZ())+1 - 0.4f, 0.05f, 0.05f, 0.5f);
				break;
				case 0:
					m_cam3D->MoveToMap(int(posCamX)-incX, int(posCamY)-incY, m_cam3D->GetPosZ(), 0.05f, 0.05f, 0.5f);
				break;
				}
			}
		}
		if(!m_cam3D->IsMoving() && !m_cam3D->IsRotating()){
			if(pMngInput->IsLogicKeyDown(IK_ARROWRIGHT)){
				m_cam3D->RotationMoveToFreely(m_cam3D->GetAngleX(), nextRight, m_cam3D->GetAngleZ(), 0.1f, 0.1f, 0.5f);
			}else if(pMngInput->IsLogicKeyDown(IK_ARROWLEFT)){
				m_cam3D->RotationMoveToFreely(m_cam3D->GetAngleX(), nextLeft, m_cam3D->GetAngleZ(), 0.1f, 0.1f, 0.5f);
			}
		}

		if(pMngInput->IsLogicKeyDown(IK_RETURN)){
			m_mngGUI.ShowMenu(false);
		}
	}
#ifdef _DEBUG
	if(pMngInput->IsKeyDown(IK_0))
		m_test->m_bShowDebug= !m_test->m_bShowDebug;
#endif

	m_mngGUI.Manage(p_nTimeTick);*/
	CContext::Manage(p_nTimeTick);
}

void
CCtxDungeon::Update()
{
CMngGraphic *pMngGraphic= GetMngGraphic();

	pMngGraphic->FillBitmap(pMngGraphic->GetBB(), 0);

	CContext::Update();
}
