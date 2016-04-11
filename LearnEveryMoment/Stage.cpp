#pragma once
#include "stdafx.h"
#include "Include.h"

CStage::CStage(SceneNo WhatStage)
	:isClear_ThisStage(false)
	, m_background(NULL)
	, m_PlayerControl(NULL)
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

	m_PlayerControl = new CPlayerControl();
	m_PlayerControl->setBelonging(GET_SINGLE(CMainGame)->getPlayerBelonging()); // 매 스테이지 시작 때 플레이어 정보를 가지고 온다. 이렇게하면 매번 싱글톤을 이용 할 필요 없이 한번만 쓰면 된다.


	GET_SINGLE(CAudioMgr)->playCue(STAGE1);
}


void CStage::KeyProcess()
{
}

SceneReturn CStage::Progress()
{
	GET_SINGLE(CObjMgr)->Progress();

	if (isClear_ThisStage == true)
		return SceneReturn_NextStage;
	else
		return SceneReturn_None;
}

void CStage::Render()
{
	GET_SINGLE(CObjMgr)->Render();
}

void CStage::Release()
{
}


void CStage::LoadTexture()
{
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Background/Stage_01/Stage01.png", L"Background", L"Stage_01", L"Main", L"Big", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Background/Stage_01/Stage01_%03d.png", L"Background", L"Stage_01", L"Main", L"Small", 183);

	// Harrier
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Normal/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Boost/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Boost", 7);


	// Stealth
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Normal/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Boost/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Boost", 7);

	// Raptor
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Normal/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Boost/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Boost", 7);

	// Phantom
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Normal/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Boost/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Boost", 7);

	//SuperHornet
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Normal/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Boost/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Boost", 7);
}

void CStage::CreateBaseObjects()
{
	m_background = (CBack_Stage*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"Background");
}
