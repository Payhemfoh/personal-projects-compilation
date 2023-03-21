#include "DPIScale.h"

float DPIScale::scaleX = 1.0f;
float DPIScale::scaleY = 1.0f;

void DPIScale::Initialize(ID2D1Factory* pFactory,HWND hwnd) {
	FLOAT dpiX, dpiY;
	dpiX = dpiY = GetDpiForWindow(hwnd);
	//pFactory->GetDesktopDpi(&dpiX, &dpiY);
	scaleX = dpiX / 96.0f;
	scaleY = dpiY / 96.0f;
}

