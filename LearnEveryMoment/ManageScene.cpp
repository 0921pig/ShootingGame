#include "stdafx.h"
#include "ManageScene.h"
#include "Include.h"

CManageScene::CManageScene()
	:m_Scene(NULL)
{
	initiaize();
}


CManageScene::~CManageScene()
{
	Release();
}

void CManageScene::initiaize()
{
	m_Scene = new CLobby();
}

void CManageScene::KeyProcess()
{
	m_Scene->KeyProcess();
}

void CManageScene::Progress()
{
	/* Progress 실행 결과 Scene 변경에 관련된 메세지를 받아서 변경을 예약한다. */
	SceneReturn returnMsg = m_Scene->Progress();
	reserve_changeScene(returnMsg);
}

void CManageScene::Render()
{
	m_Scene->Render();
}

void CManageScene::Release()
{
	delete(m_Scene);
	/* Delete 함수는 가리키는 포인터의 값이 NULL이면 아무것도 하지 않기 때문에
	SAFE_DEL이 필요없다. */
}

void CManageScene::reserve_changeScene(SceneReturn message)
{
	switch (message)
	{
	case SceneReturn_None:
		break;

	case SceneReturn_NextStage:
	{
		SceneNo nextScene;

		switch (m_SceneInfo.GetCurrentScene())
		{
		case SceneNo_Lobby: nextScene = SceneNo_Stage1; break;
		case SceneNo_Stage1: nextScene = SceneNo_End; break;
		}

		m_SceneInfo.SetNextScene(nextScene);
		break;
	}

	case SceneReturn_GameOver:
		m_SceneInfo.SetNextScene(SceneNo_End);
		break;
	}
}

void CManageScene::execute_changeScene()
{
	if (m_SceneInfo.GetNextScene() != SceneNo_None)
	{
		delete(m_Scene);
		m_Scene = NULL;
		
		switch (m_SceneInfo.GetNextScene())
		{
		case SceneNo_Lobby:		m_Scene = new CLobby();					m_SceneInfo.SetCurrentScene(SceneNo_Lobby);		break;
		case SceneNo_Stage1:	m_Scene = new CStage(SceneNo_Stage1);	m_SceneInfo.SetCurrentScene(SceneNo_Stage1);	break;
		}

		m_SceneInfo.SetNextScene(SceneNo_None);
	}
}
