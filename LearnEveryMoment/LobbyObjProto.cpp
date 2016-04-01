#pragma once
#include "stdafx.h"
#include "LobbyObjProto.h"
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
	m_MapProto.insert(make_pair(L"Background", new CBackground(SceneNo_Lobby)));

	return S_OK;
}
