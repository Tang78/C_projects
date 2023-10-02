#pragma once
#include<iostream>
#include <stdbool.h>
class MoonObject {
	double Moongravity;
	double InitialHeightMoon;
	double  HorizontalSpeedMoon;
	double  InitialVerticalSpeedMoon;
	double XPos;
	double YPos;
public:
	MoonObject(double initialHeightMoon, double horizontalSpeedMoon, double initialVerticalSpeedMoon);
	bool SetVerticalSpeed(double initialVerticalSpeedMoon);
    bool SetHeight(double initialHeightMoon);
	bool SetSpeed(double horizontalSpeedMoon);
	double GetXPos(double time);
	double  GetYPos(double time);

};