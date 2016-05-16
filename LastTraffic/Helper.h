#pragma once
#include "Frame.h"
#include "TrafficLight.h"
class Helper
{
	private:
		HINSTANCE hInst;
		HWND hwnd;
		vector<Frame*> trafficLights;
		bool activeRoad;

		void createStaticObjects() {
			Frame* tr = new TrafficLight(hInst,L"images/trafficLight.bmp",217,145,50,100);
			trafficLights.push_back(tr);
			tr = new TrafficLight(hInst,L"images/trafficLightB.bmp",609,170,100,50);
			trafficLights.push_back(tr);
			tr = new TrafficLight(hInst,L"images/trafficLightC.bmp",584,511,50,100);
			trafficLights.push_back(tr);
			tr = new TrafficLight(hInst,L"images/trafficLightD.bmp",193,485,100,50);
			trafficLights.push_back(tr);
		}



	public:
		
		vector<Frame*> getTrafficLights() {
			return this->trafficLights;
		}

		Helper(HINSTANCE hInst, HWND hwnd) {
			this->hInst = hInst;
			this->hwnd = hwnd;
			this->activeRoad = false;
			createStaticObjects();
		}

		bool getActiveRoad(){
			return this->activeRoad;
		}

		void SwitchTrafficLights(){
			for (std::vector<Frame*>::iterator scenObject = trafficLights.begin(); scenObject != trafficLights.end(); ++scenObject) {
				((TrafficLight*)*scenObject)->IsRed();
			}
			this->activeRoad = !activeRoad;
		}

		void staticObjectsRender(PAINTSTRUCT ps, HDC hdc) {
			for (std::vector<Frame*>::iterator scenObject = trafficLights.begin(); scenObject != trafficLights.end(); ++scenObject) {
				(*scenObject)->render(hwnd, ps, hdc);
			}
		}


		/*void update(){
			// de iterat prin fiecare vector cu masini, de facut update la fiecare obj din vectr
			for (std::vector<Frame*>::iterator carA = trafficLights.begin(); scenObject != trafficLights.end(); ++scenObject) {
				(*carA)->update();
				(*carA)->checkTrafficLightColor(getActiveRoad());
			}
		}*/

		// bidlocode
		// bool checkWhichCol
};

