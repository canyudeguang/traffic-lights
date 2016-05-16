#pragma once
#include "Frame.h";
#include "Helper.h"

class CarC : public Frame
{
public:
	CarC(HINSTANCE hInst) : Frame(hInst,L"images/CarC.bmp",470,720,50,100){
		this->vX = this->vY = 0;
		this->vY  = 3; 
	}

	virtual void update() override {
		this->x += vX;
		this->y -= vY;		
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
	void setX(int x) {
		this->x = x;
	}

	void setY(int y) {
		this->y = y;
	}

	void setVx(int v) {
		this->vX = v;
	}

	void setVy(int v) {
		this->vY = v;
	}

	void stopAtRed(Helper* mainHelper) {
		if (this->getX() > 267 && this->getX() < 535 && this->getY() > 545 && this->getY() < 575 && !mainHelper->getActiveRoad()) {
			this->vY= 0;
		} else {
			this->vY = 3;
		}
	}


	bool checkInFront(CarC* carC) {
		if (this->y - carC->y <= 125) {
			return false;
		} else {
			return true;
		}
	}

	bool isInTheSquare() {
		if (this->getX() > 177 && this->getX() < 633 && this->getY() > 139 && this->getY() < 521)
		{
			return true;
		} else {
			return false;
		}
	}
};

