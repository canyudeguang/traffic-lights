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

	bool isInTheSquare() {
		if (this->getX() > 177 && this->getX() < 633 && this->getY() > 139 && this->getY() < 521)
		{
			return true;
		} else {
			return false;
		}
	}

	void stopForAWhile(bool isStop){
		if(isStop && !!(this->getX() > 157 && this->getX() < 673 && this->getY() > 169 && this->getY() < 551)) {
			this->setVx(0);
		} else {
			this->setVx(-4);
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

	bool isAtRed(Helper* mainHelper) {
		if (this->getX() > 660 && this->getX() < 680 && this->getY() > 235 && this->getY() < 442 && mainHelper->getActiveRoad()) {
			return true;
		} else {
			return false;
		}
	}

	bool checkInFront(CarB* carB) {
		if (this->x - carB->x <= 225) {
			return false;
		} else {
			return true;
		}
	}

};

