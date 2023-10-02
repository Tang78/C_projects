#pragma once
#include<iostream>
#include <stdbool.h>
class EarthObject {
	double Earthgravity;
	double InitialHeightEarth;
	double  HorizontalSpeedEarth;
	double XPos;
	double YPos;
public:
	EarthObject(double initialHeightEarth, double horizontalSpeedEarth, double earthgravity);
	bool SetHeight(double initialHeightEarth);
	bool SetSpeed(double horizontalSpeedEarth);

     double GetXPos( double time);
     double  GetYPos(double time);
	

};