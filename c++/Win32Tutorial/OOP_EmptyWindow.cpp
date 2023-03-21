#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>
#include <new>

template<class Derived>
class BaseWindow {
protected:
	HWND m_hwnd;
	virtual PCWSTR ClassName() const = 0;
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;

public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		Derived* ptr = NULL;

		switch (uMsg) {
		case WM_NCCREATE:
			CREATESTRUCT* pStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
			ptr = reinterpret_cast<Derived*>(pStruct->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ptr);

			ptr->m_hwnd = hwnd;
			break;
		default:
			ptr = reinterpret_cast<Derived*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
			if (ptr) {
				return ptr->HandleMessage(uMsg, wParam, lParam);
			}
			else {
				return DefWindowProc(hwnd, uMsg, wParam, lParam);
			}

		}
	}

	BaseWindow() :m_hwnd(NULL) {}

	BOOL Create(
		PCWSTR lpWindowName,
		DWORD dwStyle,
		DWORD dwExStyle = 0,
		int x = CW_USEDEFAULT,
		int y = CW_USEDEFAULT,
		int nWidth = CW_USEDEFAULT,
		int nHeight = CW_USEDEFAULT,
		HWND hwndParent = 0,
		HMENU hMenu = 0
	){
		WNDCLASS wc = { 0 };
		wc.lpfnWndProc = Derived::Window_Proc;
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpszClassName = ClassName();

		RegisterClass(&wc);

		m_hwnd = CreateWindowEx(
			dwExStyle,ClassName(),lpWindowName,dwStyle,x,y,nWidth,nHeight,hwndParent,hMenu,GetModuleHandle(NULL),this
		)

		return (m_hwnd ? TRUE : FALSE);
	}

	HWND Window() const { return m_hwnd; }
};


class MainWindow : public BaseWindow<MainWindow> {
public:
	PCWSTR ClassName() const { return L"Sample Window"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
		switch (uMsg) {
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(m_hwnd, &ps);
			FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
			EndPaint(m_hwnd, &ps);
		}
		break;
		default:
			return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
		}

		return 0;
	}
};

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow) {
	MainWindow win;

	if (!win.Create(L"Learn to Program Windows", WS_OVERLAPPEDWINDOW)) {
		return 0;
	}

	ShowWindow(win.Window(), nCmdShow);

	MSG msg = {};

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}