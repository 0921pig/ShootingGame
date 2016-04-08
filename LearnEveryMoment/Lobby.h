#pragma once
#include "Include.h"

#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

class CScene;
class CBack_Lobby;
class CObj;
class CSelect_Aircraft;

class CLobby : public CScene
{
	CBack_Lobby* m_background;

	AircraftTypeOfPlayer m_selected;
	CSelect_Aircraft* m_select_fighter[6];

	bool isSelect;

public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyProcess();
	virtual void Render();
	virtual void Release();

private:
	virtual void LoadTexture();
	virtual void CreateBaseObjects();
	void moveCursor(DIR4 direction);
	void selectAircraft(AircraftTypeOfPlayer aircraft);

public:
	CLobby();
	virtual ~CLobby();
};

