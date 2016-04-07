#pragma once
#include "stdafx.h"
#include "Include.h"

CLobbyObjProto::CLobbyObjProto()
{
	InitProtoInstance();
}


CLobbyObjProto::~CLobbyObjProto()
{
}

HRESULT CLobbyObjProto::InitProtoInstance()
{
	m_MapProto.insert(make_pair(L"Background", new CBack_Lobby()));

	m_MapProto.insert(make_pair(L"SA_Harrier", new CSelect_Aircraft(PA_Harrier)));
	m_MapProto.insert(make_pair(L"SA_Stealth", new CSelect_Aircraft(PA_Stealth)));
	m_MapProto.insert(make_pair(L"SA_Raptor", new CSelect_Aircraft(PA_Raptor)));
	m_MapProto.insert(make_pair(L"SA_Phantom", new CSelect_Aircraft(PA_Phantom)));
	m_MapProto.insert(make_pair(L"SA_SuperHornet", new CSelect_Aircraft(PA_SuperHornet)));
	m_MapProto.insert(make_pair(L"SA_Random", new CSelect_Aircraft(PA_Random)));


	return S_OK;
}
