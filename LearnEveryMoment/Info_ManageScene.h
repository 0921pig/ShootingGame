#pragma once
#include "Base.h"

class CInfo_ManageScene
{
private:
	SceneNo m_CurrentScene;
	SceneNo m_NextScene;

public:
	SceneNo GetCurrentScene() { return m_CurrentScene; }
	SceneNo GetNextScene() { return m_NextScene; }
	void SetCurrentScene(SceneNo value);
	void SetNextScene(SceneNo value);

public:
	CInfo_ManageScene();
	~CInfo_ManageScene();
};

