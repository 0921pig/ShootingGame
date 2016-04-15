#include "stdafx.h"
#include "Include.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT, WPARAM wParam, LPARAM lParam);


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS WndClass;
	//WndClass Settings
	{    
		WndClass.cbClsExtra = 0;
		WndClass.cbWndExtra = 0;
		WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		WndClass.hCursor = LoadCursor(0, IDC_ARROW);
		WndClass.hIcon = LoadIcon(0, IDI_APPLICATION);
		WndClass.hInstance = hInstance;
		WndClass.lpfnWndProc = WndProc;
		WndClass.lpszClassName = TEXT("Client");
		WndClass.lpszMenuName = 0;
		WndClass.style = CS_VREDRAW | CS_HREDRAW;

		if (!RegisterClass(&WndClass))
			return 0;
	} 


	RECT rcWindow = { 0, 0, WINSIZEX, WINSIZEY };
	AdjustWindowRect(&rcWindow, WS_OVERLAPPEDWINDOW, false);

#define NoteBookPC

#ifdef NoteBookPC
	g_hWnd = CreateWindow(WndClass.lpszClassName, L"Window Caption", WS_OVERLAPPEDWINDOW, 1920 - WINSIZEX, 10, WINSIZEX, WINSIZEY, NULL, NULL, hInstance, NULL); 
#else
	g_hWnd = CreateWindow(WndClass.lpszClassName, L"Window Caption", WS_OVERLAPPEDWINDOW, -WINSIZEX - 20, 10, rcWindow.right - rcWindow.left , rcWindow.bottom - rcWindow.top, NULL, NULL, hInstance, NULL);
#endif

	if (!g_hWnd) // 윈도우 핸들 잘 생성되었는지 체크
		return FALSE;
	
	ShowWindow(g_hWnd, nShowCmd);
	UpdateWindow(g_hWnd);
	


	GET_SINGLE(CDeviceMgr)->InitDevice(WINMODE_WIN);
	GET_SINGLE(CAudioMgr)->initialize();

	MSG msg; //While문에서 사용할 메세지
	msg.message = WM_NULL;

	GET_SINGLE(CMainGame)->Initialize();  //CMainGame은 프로그램 전체에 하나만 존재해야하므로, 싱글톤으로 지정.

	/* 메세지 처리 루틴 */
	while (msg.message != WM_QUIT)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			GET_SINGLE(CMainGame)->StartPhase();
			GET_SINGLE(CMainGame)->Progress();
			GET_SINGLE(CMainGame)->Render();
		}
	}

	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{

	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	}

	return DefWindowProc(hWnd, message, wParam, lParam);
}
