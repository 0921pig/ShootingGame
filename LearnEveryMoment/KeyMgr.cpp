#include "stdafx.h"
#include "KeyMgr.h"

CKeyMgr::CKeyMgr()
	: prev_KeyTable(NULL)
	, curr_KeyTable(NULL)
{
	initialize();
}


CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::initialize()
{
	prev_KeyTable = new KeyState[256];
	curr_KeyTable = new KeyState[256];

	memset(prev_KeyTable, KS_None, sizeof(KeyState) * 256);
	memset(curr_KeyTable, KS_None, sizeof(KeyState) * 256);
}

void CKeyMgr::KeyCheck()
{
	for (int i = 0; i < 256; ++i)
	{
		if (prev_KeyTable[i] == KS_None || prev_KeyTable[i] == KS_KeyUp)
		{
			if (GetAsyncKeyState(i) & 0x8000)
				curr_KeyTable[i] = KS_KeyDown;
			else
				curr_KeyTable[i] = KS_None;
		}
		else if (prev_KeyTable[i] == KS_KeyDown || prev_KeyTable[i] == KS_KeyPressing)
		{
			if (GetAsyncKeyState(i) & 0x8000)
				curr_KeyTable[i] = KS_KeyPressing;
			else
				curr_KeyTable[i] = KS_KeyUp;
		}
		else
		{
			ERR_MSG(g_hWnd, L"KeyCheck()���� ���ܻ�Ȳ �߻�. ���� ���� ������ �ȵ�. ���ø��� ������");
		}

	}
}

void CKeyMgr::swapTable()
{
	KeyState* pTemp;

	pTemp = prev_KeyTable;
	prev_KeyTable = curr_KeyTable;
	curr_KeyTable = pTemp;
}

void CKeyMgr::ProcessingSequence()
{
	/*
	1. ���̺��� �ٲ۴�
	2. ���� ���̺��� ��� KS_None���� ����
	3. KeyCheck�� ���� ���� ���¸� �����Ѵ�
	*/

	swapTable();
	memset(curr_KeyTable, KS_None, sizeof(curr_KeyTable));
	KeyCheck();
}

KeyState CKeyMgr::GetKeyState(int key)
{
	return curr_KeyTable[key];
}
