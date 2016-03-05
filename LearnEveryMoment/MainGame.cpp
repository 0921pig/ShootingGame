#include "stdafx.h"
#include "MainGame.h"

CMainGame::CMainGame()
:m_Scene(NULL)
{
	Initialize();
}


CMainGame::~CMainGame()
{
	Release();
}

HRESULT CMainGame::Initialize()
{
	/* Device Mgr �ʱ�ȭ */
	if (FAILED(GET_SINGLE(CDeviceMgr)->InitDevice(WINMODE_WIN)))
		ERR_MSG(g_hWnd, L"InitDevice ����");



	return S_OK;
}

void CMainGame::Release()
{
	DESTROY_SINGLE(CDeviceMgr);
}

void CMainGame::Progress()
{

}

void CMainGame::Render()
{
	GET_SINGLE(CDeviceMgr)->Render_Begin();

	GET_SINGLE(CDeviceMgr)->Render_End();
}

