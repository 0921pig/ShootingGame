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


	GET_SINGLE(CDeviceMgr)->InitDevice(WINMODE_WIN);
	LoadTexture();
	setObjProto(new CLobbyObjProto());
	
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
	if (FAILED(GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Daniel.jpg", L"Background", TEXTYPE_MULTI, L"Lobby", 1)))
		return;
}

void CLobby::CreateBaseObjects()
{
	GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"Background");
}
