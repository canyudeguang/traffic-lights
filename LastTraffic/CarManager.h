#pragma once
#include "CarA.h"
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"
#include "Pedestrian.h"
#include "PedestrianB.h"
#include "PedestrianC.h"
#include "PedestrianD.h"
class CarManager {
private:
	vector<CarA*>carAvector;
	vector<CarB*>carBvector;
	vector<CarC*>carCvector;
	vector<CarD*>carDvector;
	Pedestrian* pedestrianA;
	PedestrianB* pedestrianB;
	PedestrianC* pedestrianC;
	PedestrianD* pedestrianD;
public:

	CarManager(HINSTANCE hInst) {
		LPCWSTR choices[2] = {L"images/CarD.bmp",L"images/ambulance.bmp"};
		LPCWSTR choices2[2] = {L"images/CarC.bmp",L"images/police.bmp"};
		int number;
		// fullfill the vectors of 50 carA`s, carB`s, carC`s and carD`s with new elements
		pedestrianA = new Pedestrian(hInst);
		pedestrianB = new PedestrianB(hInst);
		pedestrianC = new PedestrianC(hInst);
		pedestrianD = new PedestrianD(hInst);
		for (int i = 0; i < 50; i++) {
			
			carAvector.push_back(new CarA(hInst));
			carBvector.push_back(new CarB(hInst));
			number = rand() % ((1 - 0) + 1) + 0;
			carCvector.push_back(new CarC(hInst,choices2[number] ));
			number = rand() % ((1 - 0) + 1) + 0;
			carDvector.push_back(new CarD(hInst,choices[number]));
		}
	}

	void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc){
		pedestrianA->render(hwnd,ps, hdc);
		pedestrianB->render(hwnd,ps, hdc);
		pedestrianC->render(hwnd,ps, hdc);
		pedestrianD->render(hwnd,ps, hdc);
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

		bool temporary = false;

		bool carAleavedTheSquare = false;
		bool carBleavedTheSquare = false;
		bool carDleavedTheSquare = false;
		bool carCleavedTheSquare = false;

		int k = 0;

		vector<int>stackAvector;
		vector<int>stackBvector;
		vector<int>stackCvector;
		vector<int>stackDvector;

		bool isInTheSquare = false;
		bool leavedTheSquare = false;

		for(std::vector<CarB*>::size_type i = 0; i != carBvector.size(); i++) {
			//carAinTheSquare = isAnyCarAactive(carAvector);

			while(!carAinTheSquare && k<=49) {
				carAinTheSquare = carAvector[k]->isInTheSquare();
				k++;
				if(carAinTheSquare) {
					break;
				}
			}


			k = 0;
			while(!carBinTheSquare  && k<=49) {
				carBinTheSquare = carBvector[k]->isInTheSquare();
				k++;
				if(carBinTheSquare) {
					break;
				} 
			}

			k = 0;
			while(!carCinTheSquare  && k<=49) {
				carCinTheSquare = carCvector[k]->isInTheSquare();
				k++;
				if(carCinTheSquare) {
					break;
				} 
			}

			k = 0;
			while(!carDinTheSquare  && k<=49) {
				carDinTheSquare = carDvector[k]->isInTheSquare();
				k++;
				if(carDinTheSquare) {
					break;
				} 
			}


			if(!carAinTheSquare && !carCinTheSquare) {
				if(i == 0 ) {
					carBvector[0]->stopAtRed(mainHelper);
					carBvector[0]->update();
					carDvector[0]->stopAtRed(mainHelper);
					carDvector[0]->update();
				} 
				else if((carBvector[i]->checkInFront(carBvector[i-1])) && (carDvector[i]->checkInFront(carDvector[i-1]))) {
					carBvector[i]->stopAtRed(mainHelper);
					carBvector[i]->update();
					if(i == 2) {
						pedestrianB->update();
					}
					if(i == 3) {
						pedestrianD->update();
					}
					carDvector[i]->stopAtRed(mainHelper);
					carDvector[i]->update();
				} 
			}
			//carAinTheSquare = (this->isAnyCarDactive(carDvector)) || (!this->isAnyCarBactive(carBvector));
			if(!carDinTheSquare && !carBinTheSquare) {
				if(i == 0) {
					//pedestrian->update();
					carCvector[0]->stopAtRed(mainHelper);
					carCvector[0]->update();
					carAvector[0]->stopAtRed(mainHelper);
					carAvector[0]->update();
				} 
				else if((carAvector[i]->checkInFront(carAvector[i-1])) && (carCvector[i]->checkInFront(carCvector[i-1]))) {
					carCvector[i]->stopAtRed(mainHelper);
					carCvector[i]->update();
					if(i == 3) {
						pedestrianC->update();
					}
					if(i == 4) {
						pedestrianA->update();
					}
					carAvector[i]->stopAtRed(mainHelper);
					carAvector[i]->update();
				} 
			}


			/*for (int j = 0; j <= i; j++) {
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
			
			/*if(stackBvector.size() >=1 || stackDvector.size() >= 1) {
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
			}*/
		}
	}

	bool isAnyCarAactive(vector<CarA*> carAvector) {
		bool carAinTheSquare = false;
		for (int j = 0; j <= carAvector.size(); j++) {
			carAinTheSquare = carAvector[j]->isInTheSquare();
			if(carAinTheSquare) {
				break;
			} else {
				carAinTheSquare = false;
			}

		}
		return carAinTheSquare;
	}

	bool isAnyCarBactive(vector<CarB*> carBvector) {
		bool carBinTheSquare = false;
		for (int j = 0; j <= carBvector.size(); j++) {
			carBinTheSquare = carBvector[j]->isInTheSquare();
			if(carBinTheSquare) {
				break;
			} else {
				carBinTheSquare = false;
			}
		}
		return carBinTheSquare;
	}


	bool isAnyCarCactive(vector<CarC*> carCvector) {
		bool carCinTheSquare = false;
		for (int j = 0; j <= carCvector.size(); j++) {
			carCinTheSquare = carCvector[j]->isInTheSquare();
			if(carCinTheSquare) {
				break;
			} else {
				carCinTheSquare = false;
			}
		}
		return carCinTheSquare;
	}

	bool isAnyCarDactive(vector<CarD*> carDvector) {
		bool carDinTheSquare = false;
		for (int j = 0; j <= carDvector.size(); j++) {
			carDinTheSquare = carDvector[j]->isInTheSquare();
			if(carDinTheSquare) {
				break;
			} else {
				carDinTheSquare = false;
			}
		}
		return carDinTheSquare;
	}

	void stopCarManagerAtRed(Helper* mainHelper) {
		for(std::vector<CarA*>::size_type i = 0; i != carAvector.size(); i++) {
			/* std::cout << someVector[i]; ... */
			carAvector[i]->stopAtRed(mainHelper);
		}
	}

	
};

