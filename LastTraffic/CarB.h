#pragma once
#include "Frame.h"
#include "CarA.h"
#include "CarC.h"
#include "CarD.h"
#include <vector>

using namespace std;

class CarB : public Frame
{
public:
	CarB(HINSTANCE hInst) : Frame(hInst,L"images/CarB.bmp",850,250,100,50){
		this->vX = this->vY = 0;
		this->vX  = -4;
	}

	virtual void update() override {
		this->x += vX;
		this->y += vY;		
	}

	// getters
	int getX() {
		return this->x;
	}

	int getY() {
		return this->y;
	}

	int getVx() {
		return this->vX;
	}

	int getVy() {
		return this->vY;
	}

	// setters
	void setX(int _x) {
		this->x = _x;
	}

	void setY(int _y) {
		this->y = _y;
	}

	void setVx(int _v) {
		this->vX = _v;
	}

	void setVy(int _v) {
		this->vY = _v;
	}

	/*bool checkCarsInTheSquare(vector<CarA>& carAvector, vector<CarC*> carCvector, vector<CarD*> carDvector) {
		bool isInTheSquare = false; 

		// check for carB
		for(std::vector<CarA*>::size_type i = 0; i != carAvector.size(); i++) {
			if (carAvector[i]->getX() > 177 && carAvector[i]->getX() < 633 && carAvector[i]->getY() > 139 && carAvector[i]->getY() < 521) {
				isInTheSquare = true;
			}
		}	

		// check for carC
		for(std::vector<CarC*>::size_type i = 0; i != carCvector.size(); i++) {
			if (carCvector[i]->getX() > 177 && carCvector[i]->getX() < 633 && carCvector[i]->getY() > 139 && carCvector[i]->getY() < 521) {
				isInTheSquare = true;
			}
		}	

		// check for carD
		for(std::vector<CarD*>::size_type i = 0; i != carDvector.size(); i++) {
			if (carDvector[i]->getX() > 177 && carDvector[i]->getX() < 633 && carDvector[i]->getY() > 139 && carDvector[i]->getY() < 521) {
				isInTheSquare = true;
			}
		}	
		return isInTheSquare;
	}*/

	bool isInTheSquare() {
		if (this->getX() > 177 && this->getX() < 633 && this->getY() > 139 && this->getY() < 521)
		{
			return true;
		} else {
			return false;
		}
	}

		
	bool leavedTheSquare() {
		if (this->getX() > 0 && this->getX() < 197 && this->getY() > 139 && this->getY() < 521)
		{
			return true;
		} else {
			return false;
		}
	}

	bool checkBcarInTheSquare() {
		bool isInTheSquare = false; 
		if (this->x > 177 && this->x < 633 && this->y > 139 && this->y < 521) {
			isInTheSquare = true;
		}
		return isInTheSquare;
	}

	void stopAtRed(Helper* mainHelper) {
		if (this->getX() > 660 && this->getX() < 680 && this->getY() > 235 && this->getY() < 442 && mainHelper->getActiveRoad()) {
			this->vX= 0;
		} else {
			this->vX = -4;
		}
	}

	bool checkInFront(CarB* carB) {
		if (this->x - carB->x <= 125) {
			return false;
		} else {
			return true;
		}
	}

};

