#include "stdafx.h"
#include "Background.h"


CBackground::CBackground(SceneNo SceneNum)
	: m_SceneNo(SceneNum)
{
	Initialize();
}

CBackground::~CBackground()
{
}

void CBackground::Initialize()
{
	// 여기서 배경 이미지 Load
	// 방법은 Texture Manager를 등록해서 이미지를 Texture로 등록하면 됨.
	switch (m_SceneNo)
	{
	case SceneNo_None: break;
	case SceneNo_Lobby:break;
	case SceneNo_Stage1:break;
	}
}

void CBackground::Progress()
{
	// 여기서 어디를 출력할지 세팅
}

void CBackground::Render()
{
	// 여기서 이미지 한 장을 출력한다
}

void CBackground::Release()
{
}

CObj * CBackground::Clone()
{
	// 여기는 어떻게 한다? 지난번 프로젝트를 참고해서 해결한다.
	return nullptr;
}
