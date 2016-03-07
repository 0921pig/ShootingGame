#pragma once
#include "Include.h"

class CDeviceMgr
{
	DECLARE_SINGLETON(CDeviceMgr);

private:
	//��ġ�� ������ �����Ѵ�. m_pDevice �������ش�.
	LPDIRECT3D9			m_p3D;

	//��ġ�� ��ǥ�ϴ� ��ü
	LPDIRECT3DDEVICE9			m_pDevice;
	LPD3DXSPRITE				m_pSprite;
	LPD3DXFONT					m_pFont;
	LPD3DXLINE			m_pLine;
public:
	LPD3DXLINE GetLine() { return m_pLine; }
	LPD3DXFONT GetFont() { return m_pFont; }
	LPD3DXSPRITE GetSprite() { return m_pSprite; }
	LPDIRECT3DDEVICE9 GetDevice() { return m_pDevice; }
public:
	HRESULT InitDevice(WINMODE Mode);

public:
	void Render_Begin();
	void Render_End();
	void Release();

private:
	CDeviceMgr();
public:
	~CDeviceMgr();
};

