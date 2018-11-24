#include "lib.h"
#include "MngGUIArcana.h"
#include "AppArcana.h"
#include "libMngInput.h"

const int POS_CURSOR_MAIN[9][2]=
{
	{-175, 110}, {-65, 110}, {45, 110}, {-175, 140}, {-65, 140}, {45, 140}, {-175, 170}, {-65, 170}, {45, 170}
};

const int POS_CURSOR_CHANGE_COLOR[3][2]=
{
	{-175, 130},
	{-175, 160},
	{-175, 190},
};

CMngGUIArcana::CMngGUIArcana()
{
}

CMngGUIArcana::~CMngGUIArcana()
{
}

void
CMngGUIArcana::Init(CContext *p_pContext, char* p_strNamePlace)
{
CMngGraphic	*pRenderer	= GetMngGraphic();

	m_pContext= p_pContext;

	//GUI
	m_pCam2D					= (CCamera2D*)m_pContext->FindByID("Camera2D");
	m_pGUIPhysObj				= (CPhysObj*)m_pContext->FindByID("PhysObjGUI");
	m_pBitmapGUI				= ((CBackgroundLayer*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "BkGUI"))->m_bitmap;
	m_pGUIMenuPhysObj			= (CPhysObj*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "PhysObjGUIMenuNonBattle");
	m_pGUIMenuChangeColorPhysObj= (CPhysObj*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "GUIMenuChangeColor");
	m_pGUIMenuCursor			= (CEntity*)m_pContext->FindByIDUnder(m_pGUIMenuPhysObj, "EntGUIMenuCursor");
	m_pGUIPane					= (CEntity*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "EntGUIPane");
	m_pGUITxt					= (CLabelGradual*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "LblGUITxt");
	m_pCharacter[0]				= (CEntity*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "EntGUICharNonBattle00");
	m_pCharacter[1]				= (CEntity*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "EntGUICharNonBattle01");
	m_pCharacter[2]				= (CEntity*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "EntGUICharNonBattle02");
	m_pCharacter[3]				= (CEntity*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "EntGUICharNonBattle03");
	m_pEntColor[0]				= (CEntGUIMenuChangeColorGauge*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "EntGUIMenuChangeColorGauge00");
	m_pEntColor[1]				= (CEntGUIMenuChangeColorGauge*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "EntGUIMenuChangeColorGauge01");
	m_pEntColor[2]				= (CEntGUIMenuChangeColorGauge*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "EntGUIMenuChangeColorGauge02");
	m_pLblColorValue[0]			= (CLabel*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "LblGUIMenuChangeColorRedValue");
	m_pLblColorValue[1]			= (CLabel*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "LblGUIMenuChangeColorGreenValue");
	m_pLblColorValue[2]			= (CLabel*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "LblGUIMenuChangeColorBlueValue");
	m_pGUIMenuChangeColorCursor	= (CEntity*)m_pContext->FindByIDUnder(m_pGUIMenuChangeColorPhysObj, "EntGUIMenuCursor");
	m_pGUIMenuPhysObj->Hide();

	//Detach the GUI and attach it to the cam
	m_pCam2D->AddChild(m_pContext->RemoveChild(m_pContext->FindByID("PhysObjGUI")), true);

	((CLabel*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "LblGUIPlaceName"))->SetText(p_strNamePlace);
	((CEntity*)m_pContext->FindByIDUnder(m_pGUIPhysObj, "EntGUICharNonBattleSpeaking"))->Hide();

	m_nCptTxtEmpty				= 0;
	m_bInCity					= false;
	m_bShowMenu					= false;
	m_bShowMenuColor			= false;
	m_nPosCursor				= 0;
	m_nPosCursorMenuChangeColor	= 0;

	m_pEntColor[0]->m_nValue= float((g_TheAppArcana->m_guiColor&0x00FF0000)>>20);
	m_pEntColor[1]->m_nValue= float((g_TheAppArcana->m_guiColor&0x0000FF00)>>12);
	m_pEntColor[2]->m_nValue= float((g_TheAppArcana->m_guiColor&0x000000FF)>>4);

	pRenderer->FillRect(m_pBitmapGUI, 138, 333, 501, 456, g_TheAppArcana->m_guiColor);
}

void
CMngGUIArcana::ShowMenu(bool p_bCity)
{
	m_bInCity= p_bCity;

	m_bShowMenu= true;
}


void
CMngGUIArcana::ManageMenuChangeColor(u32 p_timeTick)
{
CMngInput	*pMngInput 	= GetMngInput();
CMngGraphic	*pRenderer	= GetMngGraphic();

	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		m_bShowMenuColor= false;
	}else if(pMngInput->IsLogicKeyDown(IK_ARROWUP)){
		--m_nPosCursorMenuChangeColor;
	}else if(pMngInput->IsLogicKeyDown(IK_ARROWDOWN)){
		++m_nPosCursorMenuChangeColor;
	}else if(pMngInput->IsKeyDown(IK_ARROWLEFT)){
		m_pEntColor[m_nPosCursorMenuChangeColor]->m_nValue-= 0.1f;
	}else if(pMngInput->IsKeyDown(IK_ARROWRIGHT)){
		m_pEntColor[m_nPosCursorMenuChangeColor]->m_nValue+= 0.1f;
	}

	if(m_nPosCursorMenuChangeColor >= 3)
		m_nPosCursorMenuChangeColor-= 3;
	if(m_nPosCursorMenuChangeColor < 0)
		m_nPosCursorMenuChangeColor+= 3;
	if(m_pEntColor[m_nPosCursorMenuChangeColor]->m_nValue > 8)
		m_pEntColor[m_nPosCursorMenuChangeColor]->m_nValue= 8;
	if(m_pEntColor[m_nPosCursorMenuChangeColor]->m_nValue < 0)
		m_pEntColor[m_nPosCursorMenuChangeColor]->m_nValue= 0;

	m_pGUIMenuChangeColorCursor->SetPos(float(POS_CURSOR_CHANGE_COLOR[m_nPosCursorMenuChangeColor][0]), float(POS_CURSOR_CHANGE_COLOR[m_nPosCursorMenuChangeColor][1]), m_pGUIMenuChangeColorCursor->GetPosZ());

	m_pLblColorValue[0]->SetText(int(m_pEntColor[0]->m_nValue));
	m_pLblColorValue[1]->SetText(int(m_pEntColor[1]->m_nValue));
	m_pLblColorValue[2]->SetText(int(m_pEntColor[2]->m_nValue));

	g_TheAppArcana->m_guiColor= (int(m_pEntColor[0]->m_nValue)<<20)|
								(int(m_pEntColor[1]->m_nValue)<<12)|
								(int(m_pEntColor[2]->m_nValue)<<4);

	pRenderer->FillRect(m_pBitmapGUI, 138, 333, 501, 456, g_TheAppArcana->m_guiColor);
}


void
CMngGUIArcana::ManageMenu(u32 p_timeTick)
{
CMngInput	*pMngInput 	= GetMngInput();

	if(pMngInput->IsLogicKeyDown(IK_ESCAPE)){
		m_bShowMenu= false;
		m_pGUIMenuPhysObj->Hide();
	}

	if(pMngInput->IsLogicKeyDown(IK_RETURN)){
		if(m_nPosCursor == 7)
			m_bShowMenuColor= true;
	}else if(pMngInput->IsLogicKeyDown(IK_ARROWLEFT)){
		--m_nPosCursor;
	}else if(pMngInput->IsLogicKeyDown(IK_ARROWRIGHT)){
		++m_nPosCursor;
	}else if(pMngInput->IsLogicKeyDown(IK_ARROWUP)){
		m_nPosCursor-= 3;;
	}else if(pMngInput->IsLogicKeyDown(IK_ARROWDOWN)){
		m_nPosCursor+= 3;
	}

	if(m_nPosCursor >= 9)
		m_nPosCursor-= 9;
	if(m_nPosCursor < 0)
		m_nPosCursor+= 9;

	m_pGUIMenuCursor->SetPos(float(POS_CURSOR_MAIN[m_nPosCursor][0]), float(POS_CURSOR_MAIN[m_nPosCursor][1]), m_pGUIMenuCursor->GetPosZ());
}


void
CMngGUIArcana::ManageNonBattle(u32 p_timeTick)
{
	if(m_bShowMenuColor)
		ManageMenuChangeColor(p_timeTick);
	else if(m_bShowMenu)
		ManageMenu(p_timeTick);

	for(int i= 0; i < 4; ++i)
		m_pCharacter[i]->SetState(g_TheAppArcana->m_nCurChar[i]);

	if(!m_pGUITxt->IsEmpty())
		m_nCptTxtEmpty= 0;
	else
		++m_nCptTxtEmpty;

	m_pGUIMenuChangeColorPhysObj->Show(m_bShowMenuColor);
	m_pGUIMenuPhysObj->Show(m_bShowMenu && !m_bShowMenuColor);
	m_pGUIPane->Show(!m_bShowMenu && (m_nCptTxtEmpty > 2));
}

void
CMngGUIArcana::Manage(u32 p_timeTick)
{
	ManageNonBattle(p_timeTick);
}

void
CMngGUIArcana::Update()
{
}

