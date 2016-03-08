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
		m_SceneInfo.NextScene = (SceneNo)(m_SceneInfo.CurrentScene + 1);
		break;
	case SceneReturn_GameOver:
		break;
	}
}
