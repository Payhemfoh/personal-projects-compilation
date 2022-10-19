#pragma once
#include "BaseWindow.h"
#include <windowsx.h>
#include "DPIScale.h"
#include<d2d1.h>
#pragma comment(lib,"d2d1")

class MainWindow : public BaseWindow<MainWindow>
{
private:
	ID2D1Factory*			pFactory;
	ID2D1HwndRenderTarget*	pRenderTarget;
	ID2D1SolidColorBrush*	pBrush;
	D2D1_ELLIPSE			ellipse;
	D2D1_POINT_2F			ptMouse;

	void CalculateLayout();
	HRESULT CreateGraphicsResources();
	void DiscardGraphicsResources();
	void OnPaint();
	void Resize();
	void OnLButtonDown(int pixelX,int pixelY,DWORD flag);
	void OnLButtonUp();
	void OnMouseMove(int pixelX, int pixelY, DWORD flag);
public:
	MainWindow();
	PCWSTR ClassName() const;
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

