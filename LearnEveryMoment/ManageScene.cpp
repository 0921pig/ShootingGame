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
	delete(m_Scene); 
	/* Delete 함수는 가리키는 포인터의 값이 NULL이면 아무것도 하지 않기 때문에
		SAFE_DEL이 필요없다. */
}

void CManageScene::initiaize()
{
	m_Scene = new CLobby();
}

void CManageScene::changeScene(SceneReturn message)
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
