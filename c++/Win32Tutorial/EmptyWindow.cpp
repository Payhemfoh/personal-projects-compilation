#ifndef UNICODE
#define UNICODE
#endif

//win32 api
#include <Windows.h>
#include <new> //std::nothrow

//Sample Data Structure
struct StateInfo
{

};


//used to define the behaviour of window
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
StateInfo* GetAppInfo(HWND hwnd);
void OnSize(HWND hwnd, UINT flag, int width, int height);




//program entry point -- similar to main in console application
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	//Register window class (window class have similar behaviour -- eg: buttons)
	const wchar_t CLASS_NAME[] = L"Sample Window Class";

	WNDCLASS windowClass = {};
	windowClass.lpszClassName = CLASS_NAME;		//string to identify window class
	windowClass.lpfnWndProc = WindowProc;		//function to define behaviour of window class
	windowClass.hInstance = hInstance;			//handle to application instance

	//register the window class
	RegisterClass(&windowClass);


	//create sample data structure for data passing
	StateInfo* pState = new (std::nothrow) StateInfo;

	if (pState == NULL) {
		return -1;
	}

	//create window
	HWND hwnd = CreateWindowEx(
		0,						//Optional Window Style
		CLASS_NAME,				//Window Class
		L"Sample Window",		//Window Title
		WS_OVERLAPPEDWINDOW,	//Window Style

		//Size and position
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

		NULL,		//Parent Window
		NULL,		//Menu
		hInstance,	//Instance handle
		pState		//Additional Application data
	);

	//check if window created successfully
	if (hwnd == NULL) {
		return -1;
	}

	ShowWindow(hwnd, nCmdShow);

	//get message from operating system queue
	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0) > 0) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}


	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	StateInfo* pState;

	switch (uMsg) {
	case WM_CREATE:
		{
			CREATESTRUCT* pCreate = reinterpret_cast<CREATESTRUCT*>(lParam);
			pState = reinterpret_cast<StateInfo*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)pState);
		}
		break;
	/*
	case WM_SIZE:	//handle window resize
		{
			pState = GetAppInfo(hwnd);
			int width = LOWORD(lParam);
			int height = HIWORD(lParam);
			OnSize(hwnd, (UINT)wParam, width, height);
		}
		break;
	*/
	case WM_PAINT:	//handle window painting event
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hwnd, &ps);

			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));

			EndPaint(hwnd,&ps);	
		}
		break;
	case WM_CLOSE:	//handle close window action
		{
			if (MessageBox(hwnd, L"Are you sure?", L"Confirm Quit?", MB_OKCANCEL) == IDOK) {
				DestroyWindow(hwnd);
			}
		}
		break;
	case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}

void OnSize(HWND hwnd, UINT flag, int width, int height) {
	
}

StateInfo* GetAppInfo(HWND hwnd) {
	LONG_PTR ptr = GetWindowLongPtr(hwnd, GWLP_USERDATA);
	StateInfo* pState = reinterpret_cast<StateInfo*>(ptr);
	return pState;
}