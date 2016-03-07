#include "stdafx.h"
#include "Execution.h"

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
	
	g_hWnd = CreateWindow(WndClass.lpszClassName, L"Window Caption", WS_OVERLAPPEDWINDOW, -WINSIZEX, 10, WINSIZEX, WINSIZEY, NULL, NULL, hInstance, NULL); 
	if (!g_hWnd) // 윈도우 핸들 잘 생성되었는지 체크
		return FALSE;

	ShowWindow(g_hWnd, nShowCmd);
	UpdateWindow(g_hWnd);
	
	
	MSG msg; //While문에서 사용할 메세지
	msg.message = WM_NULL;
	CMainGame MainGame; // 생성자에서 Initialize() 실행

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
			MainGame.Progress();
			MainGame.Render();
		}
	}

	return msg.wParam;
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
