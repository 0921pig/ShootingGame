#include "Util.h"

void TRACE(LPCTSTR lpszFormat, ...)
{
	TCHAR lpszBuffer[0x160]; //���� ũ��.
	va_list fmtList;
	va_start(fmtList, lpszFormat);
	_vstprintf_s(lpszBuffer, lpszFormat, fmtList);
	va_end(fmtList);
	::OutputDebugString(lpszBuffer);
}