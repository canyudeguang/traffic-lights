// LastTraffic.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "LastTraffic.h"
#include "TrafficLight.h"
#include "TrafficLightColors.h"
#include "Helper.h"
#include "CarA.h"
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"
#include "CarManager.h"

//CarA *carA;
//CarA *carA2;
//CarB *carB;
//CarC *carC;
//CarD *carD;

TrafficLight *trA, *trB, *trC, *trD;
Helper *mainHelper;
CarManager *carManager;
#define MAX_LOADSTRING 100


LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	bool isRed = false;
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_CREATE:
		SetTimer(hWnd, TIMER_ELAPSE, 20, NULL);
		SetTimer(hWnd, TIMER_ELAPSE_NEW, 1000, NULL);

		//carA = new CarA(hInst);
		//carB = new CarB(hInst);
		//carC = new CarC(hInst);
		//carD = new CarD(hInst);
		RECT rect;
		mainHelper = new Helper(hInst,hWnd);
		carManager = new CarManager(hInst);
		break;

	case WM_TIMER:

		switch (wParam)
		{
			case TIMER_ELAPSE_NEW: {
				
			//	if(!carA2)
				//	carA2 = new CarA(hInst);
			
				break;
				}
			case TIMER_ELAPSE:
				static int restriction_x, restriction_y;

				
				GetClientRect(hWnd, &rect);
				//vector<Frame*> trafficLights2 = mainHelper->getTrafficLights();
				//trafficLights2[0] 
				//Frame *tra = trafficLights2.begin();
				
				// if (carA->getX() > 181 && carA->getX() < 635 && carA->getY() > 82 && carA->getY() < 521 && !mainHelper->getActiveRoad())
				
				/*if(carA2 != NULL){
				
					if (carA2->getX() > 181 && carA2->getX() < 635 && carA2->getY() > 82 && carA2->getY() < 100 && !mainHelper->getActiveRoad())
					{
						carA2->carCollision(carA->getY());
						carA2->vY= 0;
					} 
					else
					{
						carA2->vY = 1;
					}

					
					carA2->update();
				}*/

				//carA->stopAtRed(mainHelper);

				

				//carA->update();
				carManager->update(mainHelper);
				//carB->update();
				//carC->update();
				//carD->update();
				InvalidateRect(hWnd, &rect, false);	
				break;
		}
		break;
	case WM_LBUTTONDOWN:
		//trA->switchColor();
		mainHelper->SwitchTrafficLights();
		break;
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	
	 case WM_PAINT:{
			hdc = BeginPaint(hWnd, &ps);
			background(hWnd,ps,hdc);
			mainHelper->staticObjectsRender(ps,hdc);
			carManager->render(hWnd, ps, hdc);
			
			


			//carA2->render(hWnd,ps,hdc);
			//carA->render(hWnd,ps,hdc);
			//carB->render(hWnd,ps, hdc);
			//carC->render(hWnd,ps,hdc);
			//carD->render(hWnd,ps, hdc);
			EndPaint(hWnd, &ps);
			break;
        }
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}


