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

	return S_OK;
}
