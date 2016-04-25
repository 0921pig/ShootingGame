#pragma once
#include "stdafx.h"
#include "Include.h"

CStageObjProto::CStageObjProto()
{
	InitProtoInstance();
}

CStageObjProto::~CStageObjProto()
{
}

HRESULT CStageObjProto::InitProtoInstance()
{
	m_MapProto.insert(make_pair(L"Background", new CBack_Stage()));
	m_MapProto.insert(make_pair(L"Player_Harrier", new CHarrier()));
	m_MapProto.insert(make_pair(L"Enemy01", new CEnemy01()));

	return S_OK;
}
