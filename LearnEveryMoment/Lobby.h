#pragma once
#include "Include.h"

class CScene;
class CBack_Lobby;
class CObj;
class CSelect_Aircraft;

class CLobby : public CScene
{
	CBack_Lobby* m_background;

	PlayableAircraft m_selected;
	CSelect_Aircraft* m_select_fighter[6];

public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyProcess();
	virtual void Render();
	virtual void Release();

private:
	virtual void LoadTexture();
	virtual void CreateBaseObjects();
	void moveSelect(DIR4 direction);

public:
	CLobby();
	virtual ~CLobby();
};

