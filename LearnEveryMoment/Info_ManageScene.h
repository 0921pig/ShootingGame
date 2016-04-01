#pragma once
#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

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

