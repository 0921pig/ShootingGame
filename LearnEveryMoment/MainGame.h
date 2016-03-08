#pragma once
#include "Include.h"
#include "Scene.h"

class CMainGame
{
private:
	CScene* m_Scene;

public:
	HRESULT Initialize();
	void KeyCheck();
	void Progress();
	void Render();
	void Release();

public:
	CMainGame();
	~CMainGame();
};

