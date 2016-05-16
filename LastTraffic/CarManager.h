#pragma once
#include "CarA.h"
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"

class CarManager {
private:
	vector<CarA*>carAvector;
	vector<CarB*>carBvector;
	vector<CarC*>carCvector;
	vector<CarD*>carDvector;
public:

	CarManager(HINSTANCE hInst) {
		// fullfill the vectors of 50 carA`s, carB`s, carC`s and carD`s with new elements
		for (int i = 0; i < 50; i++) {
			carAvector.push_back(new CarA(hInst));
			carBvector.push_back(new CarB(hInst));
			carCvector.push_back(new CarC(hInst));
			carDvector.push_back(new CarD(hInst));
		}
	}

	void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc){
		for(std::vector<CarA*>::size_type i = 0; i != carAvector.size(); i++) {
			carAvector[i]->render(hwnd,ps, hdc);
			carBvector[i]->render(hwnd,ps, hdc);
			carCvector[i]->render(hwnd,ps, hdc);
			carDvector[i]->render(hwnd,ps, hdc);
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

		bool isInTheSquare = false;
		bool leavedTheSquare = false;

		for(std::vector<CarB*>::size_type i = 0; i != carBvector.size(); i++) {

			for (int j = 0; j <= i; j++) {
				carAinTheSquare = carAvector[j]->isInTheSquare();
				carBinTheSquare = carAvector[j]->isInTheSquare();
				carCinTheSquare = carAvector[j]->isInTheSquare();
				carDinTheSquare = carAvector[j]->isInTheSquare();
			}

				if(i == 0) {
					carBvector[0]->stopAtRed(mainHelper);
					carBvector[0]->update();
					
				} else if((carBvector[i]->checkInFront(carBvector[i-1]) && !(carAinTheSquare || carCinTheSquare)) ) {
					carBvector[i]->stopAtRed(mainHelper);
					carBvector[i]->update();
					
				} else if( (carBvector[i]->checkInFront(carBvector[i-1])) && !(carAinTheSquare || carCinTheSquare)) {
					carBvector[i]->stopAtRed(mainHelper);
					carBvector[i]->update();
				}

				if(i == 0) {
					carDvector[0]->stopAtRed(mainHelper);
					carDvector[0]->update();
					
				} else if((carDvector[i]->checkInFront(carDvector[i-1])) && !(carAinTheSquare || carCinTheSquare)) {
					carDvector[i]->stopAtRed(mainHelper);
					carDvector[i]->update();
					
				} else if( (carDvector[i]->checkInFront(carDvector[i-1])) && !(carAinTheSquare || carCinTheSquare)) {
					carDvector[i]->stopAtRed(mainHelper);
					carDvector[i]->update();
				}
		
				if(i == 0) {
					carCvector[0]->stopAtRed(mainHelper);
					carCvector[0]->update();
					
				} else if((carAvector[i]->checkInFront(carAvector[i-1])) && !(carBinTheSquare || carDinTheSquare)) {
					carCvector[i]->stopAtRed(mainHelper);
					carCvector[i]->update();
					
				} else if( (carCvector[i]->checkInFront(carCvector[i-1])) && !(carBinTheSquare || carDinTheSquare)) {
					carCvector[i]->stopAtRed(mainHelper);
					carCvector[i]->update();
				}

				if(i == 0 ) {
					carAvector[0]->stopAtRed(mainHelper);
					carAvector[0]->update();
					
				} else if((carAvector[i]->checkInFront(carAvector[i-1])) && !(carBinTheSquare || carDinTheSquare)) {
					carAvector[i]->stopAtRed(mainHelper);
					carAvector[i]->update();

				} else if( (carAvector[i]->checkInFront(carAvector[i-1])) && !(carBinTheSquare || carDinTheSquare)) {
					carAvector[i]->stopAtRed(mainHelper);
					carAvector[i]->update();
				}
		}
	}


	void stopCarManagerAtRed(Helper* mainHelper) {
		for(std::vector<CarA*>::size_type i = 0; i != carAvector.size(); i++) {
			/* std::cout << someVector[i]; ... */
			carAvector[i]->stopAtRed(mainHelper);
		}
	}

	
};

