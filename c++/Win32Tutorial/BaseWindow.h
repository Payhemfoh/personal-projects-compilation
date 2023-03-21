#pragma once
#ifndef UNICODE
#define UNICODE
#endif

#include <Windows.h>

template <class Derived>
class BaseWindow
{
protected:
	HWND m_hwnd;
	virtual PCWSTR ClassName() const = 0;
	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) = 0;
public:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
		Derived* ptr = NULL;
		if (uMsg == WM_NCCREATE) {
			CREATESTRUCT* pStruct = reinterpret_cast<CREATESTRUCT*>(lParam);
			ptr = reinterpret_cast<Derived*>(pStruct->lpCreateParams);
			SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(ptr));
			ptr->m_hwnd = hwnd;
		}
		else {
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

	BOOL Create(PCWSTR lpWindowName, DWORD dwStyle, DWORD dwExtraStyle = 0,
		int x = CW_USEDEFAULT, int y = CW_USEDEFAULT, int nWidth = CW_USEDEFAULT, int nHeight = CW_USEDEFAULT,
		HWND parentWindow = 0, HMENU hMenu = 0) {
		WNDCLASS c = { 0 };
		c.lpfnWndProc = this->WindowProc;
		c.hInstance = GetModuleHandle(NULL);
		c.lpszClassName = this->ClassName();

		RegisterClass(&c);

		this->m_hwnd = CreateWindowEx(dwExtraStyle, this->ClassName(), lpWindowName, dwStyle,
			x, y, nWidth, nHeight,
			parentWindow, hMenu, GetModuleHandle(NULL), this);

		return this->m_hwnd ? TRUE : FALSE;
	}

	HWND Window() const {
		return this->m_hwnd;
	};
};

