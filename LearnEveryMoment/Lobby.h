#pragma once

class CScene;
class CBack_Lobby;
class CObj;
class CSelect_Aircraft;

class CLobby : public CScene
{
	CBack_Lobby* m_background;
	
	CObj* m_fighterPicture;
	CObj* m_fighterNameInfo;
	CObj* m_fighterWeaponInfo;

	CObj* m_selecting_cursor;
	CSelect_Aircraft* m_select_fighter[6];

public:
	virtual void Initialize();
	virtual SceneReturn Progress();
	virtual void KeyProcess();
	virtual void Render();
	virtual void Release();

	virtual void LoadTexture();
	virtual void CreateBaseObjects();
public:
	CLobby();
	virtual ~CLobby();
};

