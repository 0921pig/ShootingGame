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
	if (FAILED(GET_SINGLE(CDeviceMgr)->InitDevice(WINMODE_WIN)))
		ERR_MSG(g_hWnd, L"InitDevice 실패");

	return S_OK;
}

void CMainGame::StartPhase()
{
	/* 
	순서 
	
	1. 가장 먼저 Scene 변경.
	2. 키 체크
	*/

	m_ManageScene.execute_changeScene(); // Scene변경이 예약되어있다면 이곳에서 Scene해제와 새로운 Scene할당을 처리
	GET_SINGLE(CKeyMgr)->ProcessingSequence();
	KeyProcess();
}

void CMainGame::KeyProcess()
{
	/* MainGame의 키체크는 아래에서 */

	/* Scene의 키체크는 아래에서*/
	m_ManageScene.KeyProcess();
}

void CMainGame::Release()
{
	DESTROY_SINGLE(CDeviceMgr);
}

void CMainGame::Progress()
{
	m_ManageScene.Progress();
}

void CMainGame::Render()
{
	GET_SINGLE(CDeviceMgr)->Render_Begin();
	m_ManageScene.Render();
	GET_SINGLE(CDeviceMgr)->Render_End();
}

