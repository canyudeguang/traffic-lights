#pragma once
#include "Frame.h";

class CarD : public Frame
{
public:
	CarD(HINSTANCE hInst) : Frame(hInst,L"images/CarD.bmp",-50,400,100,50){
		this->vX = this->vY = 0;
		this->vX  = 3;
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
		if (this->getX() > 115 && this->getX() < 125 && this->getY() > 235 && this->getY() < 442 && mainHelper->getActiveRoad()) {
			this->vX= 0;
		} else {
			this->vX = 3;
		}
	}

	bool checkInFront(CarD* carD) {
		if (carD->x - this->x <= 125) {
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

