﻿#pragma once
#include "stdafx.h"
#include "Include.h"

void CScene::setObjProto(CObjProto * inputProto)
{
	m_ObjProto = inputProto;
}

CScene::CScene()
	:m_ObjProto(NULL)
{
}

CScene::~CScene()
{
	Release();
}

void CScene::Release()
{
}
