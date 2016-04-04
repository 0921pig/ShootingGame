#pragma once
#ifndef HEADER_Base
	#define HEADER_Base
	#include "Base.h"
#endif

#ifndef HEADER_Info_Obj
	#define HEADER_Info_Obj
	#include "Info_Obj.h"
#endif

class CObj
{
private:
	CInfo_Obj m_Info;
	SortID	m_SortID;

	TCHAR*	m_pObjType;
	TCHAR*	m_pObjName;
	TCHAR*	m_pTextureKey;
	TCHAR*	m_pStateKey;
	
public:
	CInfo_Obj*	 getObjInfo() { return &m_Info; }
	SortID		 getSortID() { return m_SortID; }
	const TCHAR* getObjkey() { return m_pObjType; }
	const TCHAR* getObjName() { return m_pObjName; }
	const TCHAR* getTexturekey() { return m_pTextureKey; }
	const TCHAR* getStatekey() { return m_pStateKey; }

	void setSortID(SortID inputSortID);
	void setObjKey(TCHAR* inputKey);
	void setObjName(TCHAR* inputName);
	void setTextrueKey(TCHAR* inputName);
	void setStateKey(TCHAR* inputStateKey);
	void setPosition(D3DXVECTOR3 inputPos);

	void calculateMatworld(CInfo_Obj* pInfo, D3DXVECTOR3 inputPos, D3DXVECTOR3 inputScale);
	void drawTexture(CInfo_Obj* inputInfo, RefPos option_RF, int iCnt, 
		const TCHAR* in_pObjType, const TCHAR* in_pObjName, const TCHAR* in_pTextureName, const TCHAR* in_pStateKey, int opacity = 255, D3DXVECTOR3 pPos = D3DXVECTOR3(0.f, 0.f, 0.f));

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

