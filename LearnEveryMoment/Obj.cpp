#include "Obj.h"
#include "Base.h"

CObj::CObj()
	:m_pObjKey(NULL), m_pObjName(NULL), m_pTextureKey(NULL), m_pStateKey(NULL), m_SortID(SortID_None)
{
}


CObj::~CObj()
{
}

void CObj::setSortID(SortID inputSortID)
{
	m_SortID = inputSortID;
}

void CObj::setObjKey(TCHAR * inputKey)
{
	m_pObjKey = inputKey;
}

void CObj::setObjName(TCHAR * inputName)
{
	m_pObjName = inputName;
}

void CObj::setStateKey(TCHAR * inputStateKey)
{
	m_pStateKey = inputStateKey;
}

void CObj::setTextrueKey(TCHAR * inputKey)
{
	m_pTextureKey = inputKey;
}
