#pragma once
#include "Scene.h"
#include "Info_ManageScene.h"

class CManageScene
{
private:
	CScene* m_Scene;
	CInfo_ManageScene m_SceneInfo;

public:
	void initiaize();

	void KeyProcess();
	void Progress();
	void Render();
	void Release();

	void reserve_changeScene(SceneReturn message);
	void execute_changeScene();

public:
	CManageScene();
	~CManageScene();
};
