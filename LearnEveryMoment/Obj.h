#pragma once
#include "Info_Obj.h"
#include "Base.h"

class CObj
{
private:
	CInfo_Obj m_Info;
	SortID	m_SortID;

	TCHAR*	m_pObjKey;
	TCHAR*	m_pObjName;
	TCHAR*	m_pTextureKey;
	TCHAR*	m_pStateKey;
	
public:
	CInfo_Obj*	 getObjInfo() { return &m_Info; }
	SortID		 getSortID() { return m_SortID; }
	const TCHAR* getObjkey() { return m_pObjKey; }
	const TCHAR* getObjName() { return m_pObjName; }
	const TCHAR* getTexturekey() { return m_pTextureKey; }
	const TCHAR* getStatekey() { return m_pStateKey; }

	void setSortID(SortID inputSortID);
	void setObjKey(TCHAR* inputKey);
	void setObjName(TCHAR* inputName);
	void setTextrueKey(TCHAR* inputName);
	void setStateKey(TCHAR* inputStateKey);

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

