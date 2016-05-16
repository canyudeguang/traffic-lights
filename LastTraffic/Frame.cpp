#include "StdAfx.h"
#include "Frame.h"


Frame::Frame(HINSTANCE hInst, LPCWSTR path, int x, int y, int width, int height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	hBitmap = (HBITMAP)LoadImage(hInst, path, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
}

void Frame::render(HWND hwnd, PAINTSTRUCT ps, HDC hdc){
	BITMAP 			bitmap;
	HDC 			hdcMem;
	HGDIOBJ 		oldBitmap;

	hdcMem = CreateCompatibleDC(hdc);
	oldBitmap = SelectObject(hdcMem, hBitmap);
		
	GetObject(hBitmap, sizeof(bitmap), &bitmap);
	BitBlt(hdc, x - width / 2, y - height / 2, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
	

	SelectObject(hdcMem, oldBitmap);
	DeleteDC(hdcMem);
};