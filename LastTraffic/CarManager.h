#pragma once
#include "CarA.h"
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"
#include "Pedestrian.h"
class CarManager {
private:
	vector<CarA*>carAvector;
	vector<CarB*>carBvector;
	vector<CarC*>carCvector;
	vector<CarD*>carDvector;
	Pedestrian *pedestrian;
public:

	CarManager(HINSTANCE hInst) {
		LPCWSTR choices[2] = {L"images/CarD.bmp",L"images/ambulance.bmp"};
		LPCWSTR choices2[2] = {L"images/CarC.bmp",L"images/police.bmp"};
		int number;
		// fullfill the vectors of 50 carA`s, carB`s, carC`s and carD`s with new elements
		for (int i = 0; i < 50; i++) {
			pedestrian = new Pedestrian(hInst);
			carAvector.push_back(new CarA(hInst));
			carBvector.push_back(new CarB(hInst));
			number = rand() % ((1 - 0) + 1) + 0;
			carCvector.push_back(new CarC(hInst,choices2[number] ));
			number = rand() % ((1 - 0) + 1) + 0;
			carDvector.push_back(new CarD(hInst,choices[number]));
		}
	}

	void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc){
		for(std::vector<CarA*>::size_type i = 0; i != carAvector.size(); i++) {
			carAvector[i]->render(hwnd,ps, hdc);
			carBvector[i]->render(hwnd,ps, hdc);
			carCvector[i]->render(hwnd,ps, hdc);
			carDvector[i]->render(hwnd,ps, hdc);
			pedestrian->render(hwnd, ps, hdc);
		}
	}

	void update(Helper *mainHelper) {
		bool carAinTheSquare = false;
		bool carBinTheSquare = false;
		bool carCinTheSquare = false;
		bool carDinTheSquare = false;

		bool carAleavedTheSquare = false;
		bool carBleavedTheSquare = false;
		bool carDleavedTheSquare = false;
		bool carCleavedTheSquare = false;

		vector<int>stackAvector;
		vector<int>stackBvector;
		vector<int>stackCvector;
		vector<int>stackDvector;

		bool isInTheSquare = false;
		bool leavedTheSquare = false;

		for(std::vector<CarB*>::size_type i = 0; i != carBvector.size(); i++) {
			for (int j = 0; j <= i; j++) {
				carAinTheSquare = carAvector[j]->isInTheSquare();
				if(carAinTheSquare) {
					stackAvector.push_back(2);
				}
				carBinTheSquare = carBvector[j]->isInTheSquare();
				if(carBinTheSquare) {
					stackBvector.push_back(2);
				}
				carCinTheSquare = carCvector[j]->isInTheSquare();
				if(carCinTheSquare) {
					stackCvector.push_back(2);
				}
				carDinTheSquare = carDvector[j]->isInTheSquare();
				if(carDinTheSquare) {
					stackDvector.push_back(2);
				}
			}



			if(stackAvector.size() >=1 || stackCvector.size() >= 1) {
				if(stackAvector.size() >=1) 
					stackAvector.pop_back();
				if(stackCvector.size() >= 1)
					stackCvector.pop_back();
			} else {
				if(i == 0 ) {
					carBvector[0]->stopAtRed(mainHelper);
					carBvector[0]->update();
					carDvector[0]->stopAtRed(mainHelper);
					carDvector[0]->update();
				} 
				else if((carBvector[i]->checkInFront(carBvector[i-1])) && (carDvector[i]->checkInFront(carDvector[i-1]))) {
					carBvector[i]->stopAtRed(mainHelper);
					carBvector[i]->update();
					carDvector[i]->stopAtRed(mainHelper);
					carDvector[i]->update();
				} 
			}

			

			/*for (int j = 0; j <= i; j++) {
				carAinTheSquare = carAvector[j]->isInTheSquare();
				carBinTheSquare = carAvector[j]->isInTheSquare();
				carCinTheSquare = carAvector[j]->isInTheSquare();
				carDinTheSquare = carAvector[j]->isInTheSquare();
			}*/

			if(stackBvector.size() >=1 || stackDvector.size() >= 1) {
				if(stackBvector.size() >=1) 
					stackBvector.pop_back();
				if(stackDvector.size() >= 1)
					stackDvector.pop_back();
			} else {

				if(i == 0) {
					pedestrian->update();
					carCvector[0]->stopAtRed(mainHelper);
					carCvector[0]->update();
					carAvector[0]->stopAtRed(mainHelper);
					carAvector[0]->update();
				} 
				else if((carAvector[i]->checkInFront(carAvector[i-1])) && (carCvector[i]->checkInFront(carCvector[i-1]))) {
					carCvector[i]->stopAtRed(mainHelper);
					carCvector[i]->update();
					carAvector[i]->stopAtRed(mainHelper);
					carAvector[i]->update();
				} 
			}
		}
	}

	bool isAnyCarAactive(vector<CarA*> carAvector) {
		bool carAinTheSquare;
		for (int j = 0; j <= carAvector.size(); j++) {
			carAinTheSquare = carAvector[j]->isInTheSquare();
			if(carAinTheSquare) {
				break;
			}
		}
		return carAinTheSquare;
	}

	void stopCarManagerAtRed(Helper* mainHelper) {
		for(std::vector<CarA*>::size_type i = 0; i != carAvector.size(); i++) {
			/* std::cout << someVector[i]; ... */
			carAvector[i]->stopAtRed(mainHelper);
		}
	}

	
};

