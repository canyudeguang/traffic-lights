#pragma once
#include <Windows.h>
class Frame
{
protected:
	int x;
	int y;
	int vX;
	int vY;
	int width;
	int height;
	HBITMAP hBitmap;

public:
	Frame(HINSTANCE hInst, LPCWSTR path, int x, int y, int width, int height);

	virtual void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc );
	
	virtual void update()=0;
};

