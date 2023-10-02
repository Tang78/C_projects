
#pragma once
#include<iostream>
#include <stdbool.h>
class Capacitor {
	double capacitance;
	double current = 0.0;
	double voltage = 0.0;
public:
	Capacitor(double _capacitance);
	double GetCurrent(double _voltage, double timeStep);
};

