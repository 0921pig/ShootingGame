#pragma once
#include "stdafx.h"
#include "Include.h"

CLobby::CLobby()
{
	Initialize();
}

CLobby::~CLobby()
{
	Release();
}

void CLobby::Initialize()
{
	LoadTexture();
	setObjProto(new CLobbyObjProto()); //프로토타입 등록
	
	CreateBaseObjects();
}

void CLobby::KeyProcess()
{
}

SceneReturn CLobby::Progress()
{
	GET_SINGLE(CObjMgr)->Progress();

	return SceneReturn_None;
}

void CLobby::Render()
{
	GET_SINGLE(CObjMgr)->Render();
}

void CLobby::Release()
{
}


void CLobby::LoadTexture()
{
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Background/Lobby/back_Lobby.png", L"Background", L"Lobby", L"Main", L"Normal", 1);
	
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Boost/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Normal/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Normal", 7);
	
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Boost/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Normal/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Normal", 7);

	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Boost/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Normal/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Normal", 7);

	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Boost/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Normal/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Normal", 7);

	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Boost/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Normal/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Normal", 7);
}

void CLobby::CreateBaseObjects()
{
	m_background = (CBack_Lobby*) GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"Background");
	
	m_select_fighter[4] = (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_SuperHornet", D3DXVECTOR3(96.f, 777.f, 0.f));
	m_select_fighter[0] = (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Harrier", D3DXVECTOR3(462.f, 777.f, 0.f));
	m_select_fighter[1] = (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Stealth", D3DXVECTOR3(218.f, 777.f, 0.f));
	m_select_fighter[2] = (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Raptor", D3DXVECTOR3(341.f, 777.f, 0.f));
	m_select_fighter[3] = (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Phantom", D3DXVECTOR3(584.f, 777.f, 0.f));
	m_select_fighter[5] = (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Random", D3DXVECTOR3(707.f, 777.f, 0.f));



}
