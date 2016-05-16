#pragma once
#include "Frame.h"
#include <windows.h>

class TrafficLight : public Frame
{
private: 
	//bool isRed;
	HBRUSH redBrush;
	HBRUSH greenBrush;
public:
	bool isRed;
	TrafficLight(HINSTANCE hInst, LPCWSTR path, int x, int y, int width, int height) : Frame(hInst,path,x,y,width,height){
		this->isRed = false;
		redBrush = CreateSolidBrush(RGB(255,0,0));
		greenBrush = CreateSolidBrush(RGB(0,255,0));
	}

	void IsRed(){
		this->isRed = !this->isRed;
	}

	void drawColor(HDC hdc, POINT position, bool isRed) {
		
		if(isRed) {
			SelectObject(hdc, redBrush);
		} else {
			SelectObject(hdc, greenBrush);
		}
		int left = position.x - 20;
		int right = position.x + 20;
		int top = position.y - 20;
		int bottom = position.y +20;
		
		Ellipse(hdc, left, top, right, bottom);
	}
	

	void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc) {
		BITMAP 			bitmap;
		HDC 			hdcMem;
		HGDIOBJ 		oldBitmap;
		POINT redA, redB, redC, redD;
		POINT greenA, greenB, greenC, greenD;

		// coordinates for each red color, please forgive me, my future friend
		redA.x = 217;
		redA.y = 122;

		redB.x = 632;
		redB.y = 169;

		redC.x = 584;
		redC.y = 535;

		redD.x = 170;
		redD.y = 485;

		// coordinates for each green

		greenA.x = 217;
		greenA.y = 172;

		greenB.x = 583;
		greenB.y = 169;

		greenC.x = 584;
		greenC.y = 484;

		greenD.x = 220;
		greenD.y = 485;


		hdcMem = CreateCompatibleDC(hdc);
		oldBitmap = SelectObject(hdcMem, hBitmap);
		
		GetObject(hBitmap, sizeof(bitmap), &bitmap);
		BitBlt(hdc, x - width / 2, y - height / 2, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
		
		
		if(isRed) { 
			drawColor(hdc, redA, !isRed);
			drawColor(hdc, greenB, isRed);
			drawColor(hdc, redC, !isRed);
			drawColor(hdc, greenD, isRed);
			
		} else {
			drawColor(hdc, greenA, !isRed);
			drawColor(hdc, redB, isRed);
			drawColor(hdc, greenC, !isRed);
			drawColor(hdc, redD, isRed);
		}
		
		SelectObject(hdcMem, oldBitmap);
		DeleteDC(hdcMem);
	}


	bool switchColorNot() {
		return this->isRed;
	}
		

	void update() override {

	}
};


