#include "stdafx.h"
#include "Include.h"

CPlayerControl::CPlayerControl()
	:m_Belonging(NULL)
{
}


CPlayerControl::~CPlayerControl()
{
}

void CPlayerControl::Initialize()
{

}

void CPlayerControl::Progress()
{

}

void CPlayerControl::Render()
{

}

void CPlayerControl::Release()
{

}

CObj* CPlayerControl::Clone()
{
	return new CPlayerControl(*this);
}

void CPlayerControl::setBelonging(CPlayer_Belonging* inputBelonging)
{
	m_Belonging = inputBelonging;
}