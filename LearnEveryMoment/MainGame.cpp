#include "stdafx.h"
#include "Include.h"

CInfo_Player * CMainGame::getPlayerInfo()
{
	//아직은 테스트니까 1Player만
	return m_Player[0];
}

CMainGame::CMainGame()
{
	m_Player[0] = new CInfo_Player;
	m_Player[1] = NULL; //이건 플레이어1 다 적용되면 확장
}


CMainGame::~CMainGame()
{
	Release();
}

HRESULT CMainGame::Initialize()
{
	GET_SINGLE(CTimeMgr)->InitTimeMgr();
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
	/* MainGame의 키체크 */

	/* Scene의 키체크 */
	m_ManageScene.KeyProcess();
}

void CMainGame::Release()
{
	// CInfo_Player의 객체 해제
	delete m_Player[0];
	delete m_Player[1];
	
	DESTROY_SINGLE(CDeviceMgr);
}

void CMainGame::Progress()
{
	GET_SINGLE(CAudioMgr)->run(); //AudioMgr의 run함수는 주기적으로 호출되어야 한다
	GET_SINGLE(CTimeMgr)->SetTime();
	m_ManageScene.Progress();
}

void CMainGame::Render()
{
	GET_SINGLE(CDeviceMgr)->Render_Begin();
	m_ManageScene.Render();
	GET_SINGLE(CDeviceMgr)->Render_End();
}

