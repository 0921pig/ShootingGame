#pragma once
#include "stdafx.h"
#include "Include.h"

enum SceneReturn;

class CScene
{
private:
	CObjProto* m_ObjProto;

public:
	virtual void Initialize()PURE;
	virtual SceneReturn Progress()PURE;
	virtual void KeyProcess()PURE;
	virtual void Render()PURE;
	virtual void Release();

	virtual void LoadTexture()PURE;
	virtual void CreateBaseObjects()PURE;

public:
	CObjProto* getObjProto() { return m_ObjProto; }

protected:
	void setObjProto(CObjProto* inputProto);


public:
	CScene();
	virtual ~CScene();
};

enum SceneReturn
{
	SceneReturn_None,
	SceneReturn_NextStage,
	SceneReturn_GameOver
};
