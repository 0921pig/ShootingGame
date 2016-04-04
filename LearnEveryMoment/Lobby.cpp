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

	m_selected = PA_SuperHornet;
	m_select_fighter[m_selected]->select(true); //초기 세팅
}

void CLobby::KeyProcess()
{
	if (GET_SINGLE(CKeyMgr)->GetKeyState(VK_LEFT) == KS_KeyDown)
		moveSelect(DIR4_LEFT);

	if (GET_SINGLE(CKeyMgr)->GetKeyState(VK_RIGHT) == KS_KeyDown)
		moveSelect(DIR4_RIGHT);
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
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Background/Lobby/back_number.png", L"Background", L"Lobby", L"Number", L"Normal", 1); 

	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/UI/Lobby/SelectMark/Normal/%02d.png", L"UI", L"Lobby", L"SelectMark", L"Normal", 1);
	
	// Harrier
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Normal/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Boost/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Body/Big/%02d.png", L"Aircraft", L"Harrier", L"Body", L"Big", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Code/Normal/%02d.png", L"Aircraft", L"Harrier", L"Code", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Code/Shadow/%02d.png", L"Aircraft", L"Harrier", L"Code", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Nickname/Normal/%02d.png", L"Aircraft", L"Harrier", L"Nickname", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/Nickname/Shadow/%02d.png", L"Aircraft", L"Harrier", L"Nickname", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Harrier/WeaponInfo/Normal/%02d.png", L"Aircraft", L"Harrier", L"WeaponInfo", L"Normal", 1);


	// Stealth
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Normal/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Boost/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Body/Big/%02d.png", L"Aircraft", L"Stealth", L"Body", L"Big", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Code/Normal/%02d.png", L"Aircraft", L"Stealth", L"Code", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Code/Shadow/%02d.png", L"Aircraft", L"Stealth", L"Code", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Nickname/Normal/%02d.png", L"Aircraft", L"Stealth", L"Nickname", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/Nickname/Shadow/%02d.png", L"Aircraft", L"Stealth", L"Nickname", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Stealth/WeaponInfo/Normal/%02d.png", L"Aircraft", L"Stealth", L"WeaponInfo", L"Normal", 1);

	// Raptor
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Normal/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Boost/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Body/Big/%02d.png", L"Aircraft", L"Raptor", L"Body", L"Big", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Code/Normal/%02d.png", L"Aircraft", L"Raptor", L"Code", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Code/Shadow/%02d.png", L"Aircraft", L"Raptor", L"Code", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Nickname/Normal/%02d.png", L"Aircraft", L"Raptor", L"Nickname", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/Nickname/Shadow/%02d.png", L"Aircraft", L"Raptor", L"Nickname", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Raptor/WeaponInfo/Normal/%02d.png", L"Aircraft", L"Raptor", L"WeaponInfo", L"Normal", 1);

	// Phantom
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Normal/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Boost/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Body/Big/%02d.png", L"Aircraft", L"Phantom", L"Body", L"Big", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Code/Normal/%02d.png", L"Aircraft", L"Phantom", L"Code", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Code/Shadow/%02d.png", L"Aircraft", L"Phantom", L"Code", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Nickname/Normal/%02d.png", L"Aircraft", L"Phantom", L"Nickname", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/Nickname/Shadow/%02d.png", L"Aircraft", L"Phantom", L"Nickname", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/Phantom/WeaponInfo/Normal/%02d.png", L"Aircraft", L"Phantom", L"WeaponInfo", L"Normal", 1);

	//SuperHornet
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Normal/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Normal", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Boost/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Boost", 7);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Body/Big/%02d.png", L"Aircraft", L"SuperHornet", L"Body", L"Big", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Code/Normal/%02d.png", L"Aircraft", L"SuperHornet", L"Code", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Code/Shadow/%02d.png", L"Aircraft", L"SuperHornet", L"Code", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Nickname/Normal/%02d.png", L"Aircraft", L"SuperHornet", L"Nickname", L"Normal", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/Nickname/Shadow/%02d.png", L"Aircraft", L"SuperHornet", L"Nickname", L"Shadow", 1);
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Aircraft/SuperHornet/WeaponInfo/Normal/%02d.png", L"Aircraft", L"SuperHornet", L"WeaponInfo", L"Normal", 1);
}

void CLobby::CreateBaseObjects()
{
	m_background = (CBack_Lobby*) GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"Background");
	
	m_select_fighter[PA_SuperHornet]	= (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_SuperHornet",	D3DXVECTOR3(096.f, 780.f, 0.f));
	m_select_fighter[PA_Stealth]		= (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Stealth",		D3DXVECTOR3(218.f, 780.f, 0.f));
	m_select_fighter[PA_Raptor]			= (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Raptor",		D3DXVECTOR3(341.f, 780.f, 0.f));
	m_select_fighter[PA_Harrier]		= (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Harrier",		D3DXVECTOR3(462.f, 780.f, 0.f));
	m_select_fighter[PA_Phantom]		= (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Phantom",		D3DXVECTOR3(584.f, 780.f, 0.f));
	m_select_fighter[PA_Random]			= (CSelect_Aircraft*)GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"SA_Random",		D3DXVECTOR3(707.f, 780.f, 0.f));



}

void CLobby::moveSelect(DIR4 direction)
{
	if (direction == DIR4_LEFT)
	{
		m_select_fighter[m_selected]->select(false); //선택 해제

		switch (m_selected)
		{
		case PA_SuperHornet:
			m_selected = PA_Random;
			break;
		case PA_Stealth:
			m_selected = PA_SuperHornet;
			break;
		case PA_Raptor:
			m_selected = PA_Stealth;
			break;
		case PA_Harrier:
			m_selected = PA_Raptor;
			break;
		case PA_Phantom:
			m_selected = PA_Harrier;
			break;
		case PA_Random:
			m_selected = PA_Phantom;
			break;
		}

		m_select_fighter[m_selected]->select(true); //선택
	}
	else if (direction == DIR4_RIGHT)
	{
		m_select_fighter[m_selected]->select(false); //선택 해제

		switch (m_selected)
		{
		case PA_SuperHornet:
			m_selected = PA_Stealth;
			break;
		case PA_Stealth:
			m_selected = PA_Raptor;
			break;
		case PA_Raptor:
			m_selected = PA_Harrier;
			break;
		case PA_Harrier:
			m_selected = PA_Phantom;
			break;
		case PA_Phantom:
			m_selected = PA_Random;
			break;
		case PA_Random:
			m_selected = PA_SuperHornet;
			break;
		}

		m_select_fighter[m_selected]->select(true); //선택
	}
	else
	{
		TRACE(L"CLobby moveSelect()에서 이상상황 발생");
	}
}
