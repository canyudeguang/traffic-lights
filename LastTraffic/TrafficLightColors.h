#pragma once
#include <windows.h>
#include "Frame.h";
class TrafficLightColors : public Frame
{
	private:
		HBRUSH redBrush;
		HBRUSH greenBrush;
		bool isRed;
	public:
		TrafficLightColors(HINSTANCE hInst, LPCWSTR path, int x, int y, int width, int height) : Frame(hInst,path,x,y,width,height){
			//this->isRed = false;
			redBrush = CreateSolidBrush(RGB(255,0,0));
			greenBrush = CreateSolidBrush(RGB(0,255,0));
		}

		void switchColor(bool isRed) {
			if(isRed) {
				isRed = isRed;
			} 
		}

		


		void IsRed(){
			this->isRed = true;
		}

		void update() override {
			
		}

		void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc) override {
			HDC 			hdcMem;
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
			//this->isRed = true;
		
		
			switchColor(isRed);
		
			/*if(isRed) { 
				drawColor(hdc, redA, !isRed);
				drawColor(hdc, greenB, isRed);
				drawColor(hdc, redC, !isRed);
				drawColor(hdc, greenD, isRed);
			
			} else {
				drawColor(hdc, greenA, !isRed);
				drawColor(hdc, redB, isRed);
				drawColor(hdc, greenC, !isRed);
				drawColor(hdc, redD, isRed);
			}*/
			DeleteDC(hdcMem);
		}

};

