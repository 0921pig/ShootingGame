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
			ERR_MSG(g_hWnd, L"KeyCheck()에서 예외상황 발생. 여긴 절대 들어오면 안됨. 들어올리가 없지만");
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
	1. 테이블을 바꾼다
	2. 현재 테이블을 모두 KS_None으로 세팅
	3. KeyCheck를 통해 눌린 상태를 조사한다
	*/

	swapTable();
	memset(curr_KeyTable, KS_None, sizeof(curr_KeyTable));
	KeyCheck();
}

KeyState CKeyMgr::GetKeyState(int key)
{
	return curr_KeyTable[key];
}
