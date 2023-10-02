#include <iostream>
#include "MoonObject.h"
#include "EarthObject.h"

bool MoonObject::SetHeight(double initialHeightMoon)
{

	bool retVal = true;
	if (initialHeightMoon <= 0.0) {
		retVal = false;
	}
	else {
		InitialHeightMoon = initialHeightMoon;
	}
	return retVal;
}
bool MoonObject::SetSpeed(double horizontalSpeedMoon)
{

	bool retVal = true;
	if (horizontalSpeedMoon <= 0.0) {
		retVal = false;
	}
	else {
		HorizontalSpeedMoon = horizontalSpeedMoon;
	}
	return retVal;
}
bool MoonObject::SetVerticalSpeed(double initialVerticalSpeedMoon)
{

	bool retVal = true;
	if (initialVerticalSpeedMoon <= 0.0) {
		retVal = false;
	}
	else {
	InitialVerticalSpeedMoon = initialVerticalSpeedMoon;
	}
	return retVal;
}
MoonObject::MoonObject(double initialHeightMoon, double horizontalSpeedMoon, double initialVerticalSpeedMoon) {
	InitialHeightMoon= initialHeightMoon;
	HorizontalSpeedMoon = horizontalSpeedMoon;
	InitialVerticalSpeedMoon = initialVerticalSpeedMoon;
}
double MoonObject::GetXPos(double time) {
	double a;
	a = (double)(HorizontalSpeedMoon * time);
return a;
}

double MoonObject::GetYPos(double time) {
	double a;
	double b;
	double c;
	double d;
	a = (time * time) * 1.625;
	b = a * 0.5;
	c = time * InitialVerticalSpeedMoon;
	d= InitialHeightMoon + c - b;
	return d;

}