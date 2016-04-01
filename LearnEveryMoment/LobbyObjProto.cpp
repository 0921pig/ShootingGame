#pragma once
#include "stdafx.h"
#include "LobbyObjProto.h"
#include "Include.h"

CLobbyObjProto::CLobbyObjProto()
{
}


CLobbyObjProto::~CLobbyObjProto()
{
}

HRESULT CLobbyObjProto::InitProtoInstance()
{
	/*CInfo_Obj ObjInfo;
	ZeroMemory(&ObjInfo, sizeof(ObjInfo));
*/
	// 맵 STL 은 내부적으로 주소값으로 정렬된다.
	m_MapProto.insert(make_pair(L"Background", new CBackground(SceneNo_Lobby)));

	return S_OK;
}
