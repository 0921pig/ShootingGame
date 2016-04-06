#pragma once
#include "stdafx.h"
#include "Include.h"

CStage::CStage(SceneNo WhatStage)
{
	Initialize();
}

CStage::~CStage()
{
	Release();
}

void CStage::Initialize()
{
	LoadTexture();
	setObjProto(new CStageObjProto());

	CreateBaseObjects();

	m_Player = GET_SINGLE(CMainGame)->getPlayerInfo(); // 매 스테이지 시작 때 플레이어 정보를 가지고 온다. 이렇게하면 매번 싱글톤을 이용 할 필요 없이 한번만 쓰면 된다.
}


void CStage::KeyProcess()
{
}

SceneReturn CStage::Progress()
{
	return SceneReturn();
}

void CStage::Render()
{
}

void CStage::Release()
{
}


void CStage::LoadTexture()
{
}

void CStage::CreateBaseObjects()
{
}
