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

	m_MapProto.insert(make_pair(L"SA_Harrier", new CSelect_Aircraft(AT_Harrier)));
	m_MapProto.insert(make_pair(L"SA_Stealth", new CSelect_Aircraft(AT_Stealth)));
	m_MapProto.insert(make_pair(L"SA_Raptor", new CSelect_Aircraft(AT_Raptor)));
	m_MapProto.insert(make_pair(L"SA_Phantom", new CSelect_Aircraft(AT_Phantom)));
	m_MapProto.insert(make_pair(L"SA_SuperHornet", new CSelect_Aircraft(AT_SuperHornet)));
	m_MapProto.insert(make_pair(L"SA_Random", new CSelect_Aircraft(AT_Random)));


	return S_OK;
}
