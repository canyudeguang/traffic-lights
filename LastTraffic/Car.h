#pragma once
#include "Frame.h";

class Car : public Frame
{
public:
	Car(HINSTANCE hInst, LPCWSTR path, int x, int y, int width, int height) : Frame(hInst,path,x,y,width,height){
		this->vX = this->vY = 0;
		this->vX  = 1;
	}

	virtual void update() override {
		this->x += vX;
		this->y += vY;		
	}
};

