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
	//m_MapProto.insert(make_pair(L"Background", new CBack_Lobby(SceneNo_Lobby)));

	return S_OK;
}
