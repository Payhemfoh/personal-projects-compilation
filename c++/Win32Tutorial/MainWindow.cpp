#include "MainWindow.h"

template <class T> void SafeRelease(T** ppT) {
	if (*ppT) {
		(*ppT)->Release();
		*ppT = NULL;
	}
}

void MainWindow::CalculateLayout() {
	if (this->pRenderTarget != NULL) {
		D2D1_SIZE_F size = this->pRenderTarget->GetSize();
		const float x = size.width / 2;
		const float y = size.height / 2;
		const float radius = min(x, y);
		this->ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
	}
}

void MainWindow::OnLButtonDown(int pixelX, int pixelY, DWORD flag) {
	SetCapture(this->m_hwnd);
	ellipse.point = ptMouse = DPIScale::PixelsToDips(pixelX, pixelY);
	ellipse.radiusX = ellipse.radiusY = 1.0f;
	InvalidateRect(this->m_hwnd, NULL, FALSE);
}

void MainWindow::OnLButtonUp() {
	ReleaseCapture();
}

void MainWindow::OnMouseMove(int pixelX, int pixelY, DWORD flag) {
	if (flag & MK_LBUTTON) {
		const D2D1_POINT_2F dips = DPIScale::PixelsToDips(pixelX, pixelY);

		const float width = (dips.x - ptMouse.x) / 2;
		const float height = (dips.y - ptMouse.y) / 2;
		const float x1 = ptMouse.x + width;
		const float y1 = ptMouse.y + height;

		ellipse = D2D1::Ellipse(D2D1::Point2F(x1, y1), width, height);

		InvalidateRect(this->m_hwnd, NULL, FALSE);
	}
}

HRESULT MainWindow::CreateGraphicsResources() {
	HRESULT hr = S_OK;
	if (this->pRenderTarget == NULL) {
		RECT rc;
		GetClientRect(this->m_hwnd, &rc);
		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(this->m_hwnd, size),
			&(this->pRenderTarget));

		if (SUCCEEDED(hr)) {
			const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
			hr = this->pRenderTarget->CreateSolidColorBrush(color, &(this->pBrush));

			if (SUCCEEDED(hr)) {
				//this->CalculateLayout();
			}
		}
	}

	return hr;
}

void MainWindow::DiscardGraphicsResources() {
	SafeRelease(&pRenderTarget);
	SafeRelease(&pBrush);
}

void MainWindow::OnPaint() {
	HRESULT hr = this->CreateGraphicsResources();
	if (SUCCEEDED(hr)) {
		PAINTSTRUCT ps;
		BeginPaint(this->m_hwnd, &ps);

		this->pRenderTarget->BeginDraw();

		this->pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));
		this->pRenderTarget->FillEllipse(ellipse, pBrush);

		hr = pRenderTarget->EndDraw();

		if (FAILED(hr) || hr == D2DERR_RECREATE_TARGET) {
			this->DiscardGraphicsResources();
		}
		EndPaint(m_hwnd,&ps);
	}
}

void MainWindow::Resize() {
	if (pRenderTarget != NULL) {
		RECT rc;
		GetClientRect(this->m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		this->pRenderTarget->Resize(size);
		//CalculateLayout();
		InvalidateRect(this->m_hwnd, NULL, FALSE);
	}
}

PCWSTR MainWindow::ClassName() const{
	return L"Circle Window Class";
}

MainWindow::MainWindow()
	:pFactory(NULL),
	pRenderTarget(NULL),
	pBrush(NULL),
	ellipse(D2D1::Ellipse(D2D1::Point2F(), 0, 0)),
	ptMouse(D2D1::Point2F())
{}

LRESULT MainWindow::HandleMessage(UINT uMsg,WPARAM wParam,LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE:
		if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &(this->pFactory)))) {
			return -1;
		}
		DPIScale::Initialize(this->pFactory,this->m_hwnd);
		break;
	case WM_DESTROY:
		this->DiscardGraphicsResources();
		SafeRelease(&pFactory);
		PostQuitMessage(0);
		break;
	case WM_PAINT:
		OnPaint();
		break;
	case WM_SIZE:
		Resize();
		break;
	case WM_LBUTTONDOWN:
		OnLButtonDown(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
		break;
	case WM_LBUTTONUP:
		OnLButtonUp();
		break;
	case WM_MOUSEMOVE:
		OnMouseMove(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam), (DWORD)wParam);
		break;
	default:
		return DefWindowProc(this->m_hwnd, uMsg, wParam, lParam);
	}

	return 0;
}