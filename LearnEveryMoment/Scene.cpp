#pragma once
#include "stdafx.h"
#include "Scene.h"


CScene::CScene()
	:m_ProtoType(NULL)
{
}

CScene::~CScene()
{
	Release();
}

void CScene::Release()
{
}
