#include "stdafx.h"
#include "Include.h"

CMainGame::CMainGame()
{
	Initialize();
}


CMainGame::~CMainGame()
{
	Release();
}

HRESULT CMainGame::Initialize()
{
	/* Device Mgr 초기화 */

	m_Lobby = new CLobby();

	return S_OK;
}

void CMainGame::StartPhase()
{
	/* 
	순서 
	
	1. 가장 먼저 Scene 변경.
	2. 키 체크
	*/

	//m_managescene.execute_changescene(); // scene변경이 예약되어있다면 이곳에서 scene해제와 새로운 scene할당을 처리
	//get_single(ckeymgr)->processingsequence();
	//keyprocess();
}

void CMainGame::KeyProcess()
{
	/* MainGame의 키체크는 아래에서 */

	/* Scene의 키체크는 아래에서*/
	//m_ManageScene.KeyProcess();
}

void CMainGame::Release()
{
	DESTROY_SINGLE(CDeviceMgr);
}

void CMainGame::Progress()
{
	//m_Lobby->Progress();
	//
	//GET_SINGLE(CDeviceMgr)->Render_Begin();
	//m_Lobby->Render();
	//GET_SINGLE(CDeviceMgr)->Render_End();
	//m_ManageScene.Progress();
	m_Lobby->Progress();
}

void CMainGame::Render()
{
	GET_SINGLE(CDeviceMgr)->Render_Begin();
	//m_ManageScene.Render();
	m_Lobby->Render();
	GET_SINGLE(CDeviceMgr)->Render_End();
}

