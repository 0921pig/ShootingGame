#pragma once
#include "stdafx.h"

class CScene
{
public:
	virtual HRESULT Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;

public:
	CScene();
	virtual ~CScene();
};
