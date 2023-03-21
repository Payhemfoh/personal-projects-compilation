#ifndef UNICODE
#define UNICODE
#endif

#include<Windows.h>
#include "MainWindow.h"

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	MainWindow wd;

	if (!wd.Create(L"Circle", WS_OVERLAPPEDWINDOW)) {
		return -1;
	}
	ShowWindow(wd.Window(), nCmdShow);

	MSG msg = {};
	while (GetMessage(&msg, wd.Window(), 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return 0;
}
