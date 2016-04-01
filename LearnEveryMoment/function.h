#pragma once
#include <tchar.h>

template<typename T>
void SAFE_DELETE(T& Pointer)
{
	delete Pointer;
	Pointer = NULL;
}

template<typename T>
void SAFE_DELETE_ARRAY(T& Pointer)
{
	delete[] Pointer;
	Pointer = NULL;
}
