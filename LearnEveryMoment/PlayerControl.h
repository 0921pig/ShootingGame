#pragma once
#include "Obj.h"
class CPlayerControl : public CObj
{
private:
	CPlayer_Belonging* m_Belonging;

public:
	virtual void Initialize();
	virtual void Progress();
	virtual void Render();
	virtual void Release();
	virtual CObj* Clone();

public:
	void setBelonging(CPlayer_Belonging* inputBelonging);

public:
	CPlayerControl();
	virtual ~CPlayerControl();
};

