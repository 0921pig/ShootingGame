#pragma once
#include "stdafx.h"
#include "StageObjProto.h"
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
	//m_MapProto.insert(make_pair(L"Background", new CBackground(SceneNo_Lobby)));

	return S_OK;
}
