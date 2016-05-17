#pragma once
#include "Frame.h"
#include "Helper.h"
#include <vector>
#include "CarB.h"
#include "CarC.h"
#include "CarD.h"

class Pedestrian : public Frame
{
private:
	bool active;
public:
	Pedestrian(HINSTANCE hInst) : Frame(hInst,L"images/pedestrian.bmp",200,170,50,50){
		this->vX = this->vY = 0;
		this->vX  = 7;
		active = true;
	}

	virtual void update() override {
		//if(!active)
		//	return;
		this->x += vX;
		this->y += vY;
		//this->stopAtRed();

	}
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

};
