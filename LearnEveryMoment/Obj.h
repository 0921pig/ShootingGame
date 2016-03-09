#pragma once
#include "Info_Obj.h"

class CObj
{
private:
	CInfo_Obj m_Info;
	TCHAR*	m_pObjKey;
	TCHAR*	m_pTextureObjKey;
	TCHAR*	m_pStateKey;
	
public:
	const TCHAR* getObjkey() { return m_pObjKey; }
	const TCHAR* getTexturekey() { return m_pTextureObjKey; }
	const TCHAR* getStatekey() { return m_pStateKey; }

public:
	virtual void Initialize()PURE;
	virtual void Progress()PURE;
	virtual void Render()PURE;
	virtual void Release()PURE;
	virtual CObj* Clone()PURE;

public:
	CObj();
	virtual ~CObj();
};

