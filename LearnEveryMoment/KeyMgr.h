#pragma once
#include "Include.h"

enum KeyState;

class CKeyMgr
{
	DECLARE_SINGLETON(CKeyMgr);

private:
	KeyState* prev_KeyTable;
	KeyState* curr_KeyTable;

public:
	void initialize();
	void KeyCheck(); 
	void swapTable();
	void ProcessingSequence();

	KeyState GetKeyState(int key);
public:
	CKeyMgr();
	~CKeyMgr();
};

enum KeyState
{
	KS_None,
	KS_KeyDown,
	KS_KeyPressing,
	KS_KeyUp,
};