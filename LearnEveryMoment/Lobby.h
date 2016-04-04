#pragma once

class CScene;
class CBack_Lobby;
class CObj;

class CLobby : public CScene
{
	CBack_Lobby* background;
	
	CObj* info_fighterPicture;
	CObj* info_fighterName;
	CObj* info_fighterWeapon;

	CObj * selecting_cursor;
	CObj* select_fighter[6];

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

