#pragma once
#include "stdafx.h"
#include "Base.h"
#include "Stage.h"

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
