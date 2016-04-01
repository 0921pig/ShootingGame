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
