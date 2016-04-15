#pragma once
#include "stdafx.h"
#include "Data_Attack.h"

class CAttackPattern
{
private:
	list<CData_Attack> m_AttackList;

public:
	CAttackPattern();
	~CAttackPattern();
};

