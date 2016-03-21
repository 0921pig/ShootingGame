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
	// ���⼭ ��� �̹��� Load
	// ����� Texture Manager�� ����ؼ� �̹����� Texture�� ����ϸ� ��.
	switch (m_SceneNo)
	{
	case SceneNo_None: break;
	case SceneNo_Lobby:break;
	case SceneNo_Stage1:break;
	}
}

void CBackground::Progress()
{
	// ���⼭ ��� ������� ����
}

void CBackground::Render()
{
	// ���⼭ �̹��� �� ���� ����Ѵ�
}

void CBackground::Release()
{
}

CObj * CBackground::Clone()
{
	// ����� ��� �Ѵ�? ������ ������Ʈ�� �����ؼ� �ذ��Ѵ�.
	return nullptr;
}
