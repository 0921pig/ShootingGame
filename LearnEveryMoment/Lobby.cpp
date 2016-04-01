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
	setObjProto(new CLobbyObjProto());
	
	CreateBaseObjects();
}

void CLobby::KeyProcess()
{
}

SceneReturn CLobby::Progress()
{
	//return SceneReturn_NextStage;
	return SceneReturn();
}

void CLobby::Render()
{
}

void CLobby::Release()
{
}


void CLobby::LoadTexture()
{
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/back_Lobby.png", L"Background", L"Background", L"Main", L"Nomral", 1);
}

void CLobby::CreateBaseObjects()
{
	GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"Background");
}
