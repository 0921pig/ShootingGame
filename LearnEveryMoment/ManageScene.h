#pragma once
#include "Scene.h"

typedef struct Info_Scene
{
	SceneNo CurrentScene;
	SceneNo NextScene;

	Info_Scene()
		:NextScene(SceneNo_None),
		CurrentScene(SceneNo_None)
	{
	}
}INFO_Scene;

class CManageScene
{
private:
	CScene* m_Scene;
	INFO_Scene m_SceneInfo;

	bool isSceneChangeExist;

public:
	void initiaize();
	void changeScene(SceneReturn message);

public:
	CManageScene();
	~CManageScene();
};
