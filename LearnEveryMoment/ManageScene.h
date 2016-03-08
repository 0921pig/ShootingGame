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
	void changeScene(SceneReturn message);

public:
	CManageScene();
	~CManageScene();
};
