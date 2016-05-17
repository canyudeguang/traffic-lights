#pragma once
#include "Frame.h"
#include "Helper.h"
#include <vector>
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"

using namespace std;


class CarA : public Frame
{
private:
	bool active;

public:
	int vY;
	CarA(HINSTANCE hInst) : Frame(hInst,L"images/CarA.bmp",300,-50,50,100){
		this->vX = this->vY = 0;
		this->vY  = 3;
		active = true;
	}

	virtual void update() override {
		//if(!active)
		//	return;
		this->x += vX;
		this->y += vY;
		//this->stopAtRed();

	}

	/*virtual void render(HWND hwnd, PAINTSTRUCT ps, HDC hdc) override {
		if(!active)
			return;
	}*/


	// getters
	int getX() {
		return this->x;
	};

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

	void stopAtRed(Helper* mainHelper) {
		if (this->getX() > 181 && this->getX() < 635 && this->getY() > 82 && this->getY() < 100 && !mainHelper->getActiveRoad()) {
			this->vY= 0;
		} else {
			this->vY = 3;
		}
	}

	bool isAtRed(Helper* mainHelper) {
		if (this->getX() > 181 && this->getX() < 635 && this->getY() > 82 && this->getY() < 100 && !mainHelper->getActiveRoad()) {
			return true;
		} else {
			return false;
		}
		
	}


	bool checkInFront(CarA* carA) {
		if (carA->y - this->y <= 235) {
			return false;
		} else {
			return true;
		}
	}




	bool isInTheSquare() {
		if (this->getX() > 177 && this->getX() < 633 && this->getY() > 139 && this->getY() < 521) {
			return true;
		} else {
			return false;
		}
	}

	/*void stopIfOthersInTheSquare(CarB* carB) {
		if(carB->isInTheSquare()) {
			this->setVy(0);
		} else {
			this->setVy(1);
		}
	}*/

	
	/*void checkCarsInTheSquare(vector<CarB*> carBvector, vector<CarC*> carCvector, vector<CarD*> carDvector) {
		bool isInTheSquare = false; 
		this->setVy(0);

		// check for carB
		for(std::vector<CarB*>::size_type i = 0; i != carBvector.size(); i++) {
			//if (carBvector[i]->getX() > 177 && carBvector[i]->getX() < 633 && carBvector[i]->getY() > 139 && carBvector[i]->getY() < 521) {
				isInTheSquare = true;
				this->vY= 0;
			//}
		}	

		// check for carC
		for(std::vector<CarC*>::size_type i = 0; i != carCvector.size(); i++) {
			if (carCvector[i]->getX() > 177 && carCvector[i]->getX() < 633 && carCvector[i]->getY() > 139 && carCvector[i]->getY() < 521) {
				isInTheSquare = true;
				this->vY= 0;
			}
		}	

		// check for carD
		for(std::vector<CarD*>::size_type i = 0; i != carDvector.size(); i++) {
			if (carDvector[i]->getX() > 177 && carDvector[i]->getX() < 633 && carDvector[i]->getY() > 139 && carDvector[i]->getY() < 521) {
				isInTheSquare = true;
				this->vY= 0;
			}
		}	
		
	}*/
	
	//void startAtGreen(){

	// Method for managing car collision
	/*void carCollision(int y) {
		//if(x - 20) 
		if(this->y + 70 >= y) {
			active = false;
		}
	}*/
	
	// functioun that manages intersection of carA with other cars
	

	void stopForAWhile(bool isStop){
		if(isStop && !(this->getX() > 177 && this->getX() < 633 && this->getY() > 139 && this->getY() < 521)) {
			this->setVy(0);
		} else {
			this->setVy(3);
		}
	}

	/*bool stopIfB(vector<CarB*> _carBvector) {
		bool carBinTheSquare = false;
		for (int j = 0; j <= _carBvector.size(); j++) {
			carBinTheSquare = _carBvector[j]->isInTheSquare();
			if(carBinTheSquare) {
				break;
			} else {
				carBinTheSquare = false;
			}
		}
		return carBinTheSquare;
	}*/
};
