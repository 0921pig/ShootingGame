#pragma once

#ifndef HEADER_Info_ManageScene
	#define HEADER_Info_ManageScene
	#include "Info_ManageScene.h"
#endif

#ifndef HEADER_Scene
	#define HEADER_Scene
	#include "Scene.h"
#endif

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
