#pragma once
#include "Include.h"
#include "ManageScene.h"

class CMainGame
{
private:
	CManageScene m_ManageScene;

public:
	HRESULT Initialize();
	void StartPhase();
	void KeyCheck();
	void Progress();
	void Render();
	void Release();

public:
	CMainGame();
	~CMainGame();
};

