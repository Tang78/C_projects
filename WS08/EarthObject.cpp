#include <iostream>
#include "MoonObject.h"
#include "EarthObject.h"

bool EarthObject:: SetHeight(double initialHeightEarth)
{

bool retVal = true;
	if (initialHeightEarth <= 0.0) {
		retVal = false;
	}
	else {
		InitialHeightEarth = initialHeightEarth;
	}
	return retVal;
}
bool EarthObject::SetSpeed(double horizontalSpeedEarth)
{

	bool retVal = true;
	if (horizontalSpeedEarth <= 0.0) {
		retVal = false;
	}
	else {
		HorizontalSpeedEarth = horizontalSpeedEarth;
	}
	return retVal;
}
EarthObject::EarthObject(double initialHeightEarth, double horizontalSpeedEarth, double earthgravity)
{
     InitialHeightEarth = initialHeightEarth;
	HorizontalSpeedEarth = horizontalSpeedEarth;
	Earthgravity = earthgravity;
}
double EarthObject::GetXPos(double time) {
	double a;
	a = (double)(HorizontalSpeedEarth* time);
return a;
}

double EarthObject::GetYPos(double time ){
	double a;
	double b;
	double c;
	a = (time * time) * Earthgravity;
	b = a * 0.5;
	c = InitialHeightEarth - b;
	
	return c;

}