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
	GET_SINGLE(CTextureMgr)->InsertTexture(L"resource/image/Daniel.jpg", L"Background", L"Lobby", L"Main", L"Normal", 10);
}

void CLobby::CreateBaseObjects()
{
	GET_SINGLE(CObjMgr)->AddObject(getObjProto(), L"Background");
}
