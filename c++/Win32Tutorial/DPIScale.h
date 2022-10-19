#pragma once
#include<d2d1.h>
#pragma comment(lib,"d2d1")

class DPIScale
{
private:
	static float scaleX;
	static float scaleY;
public:
	static void Initialize(ID2D1Factory* pFactory,HWND hwnd);
	template<typename T>
	static D2D1_POINT_2F PixelsToDips(T x, T y) {
		return D2D1::Point2F(static_cast<float>(x) / scaleX, static_cast<float>(y) / scaleY);
	}
};

