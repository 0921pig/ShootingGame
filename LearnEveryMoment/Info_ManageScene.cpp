#include "stdafx.h"
#include "Info_ManageScene.h"

CInfo_ManageScene::CInfo_ManageScene()
	:m_CurrentScene(SceneNo_None)
	, m_NextScene(SceneNo_None)
{
}

CInfo_ManageScene::~CInfo_ManageScene()
{
}

void CInfo_ManageScene::SetCurrentScene(SceneNo value)
{
	m_CurrentScene = value;
}

void CInfo_ManageScene::SetNextScene(SceneNo value)
{
	m_NextScene = value;
}
