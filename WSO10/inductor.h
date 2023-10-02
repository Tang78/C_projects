#pragma once
#include<iostream>
#include <stdbool.h>
class Inductor {
	double inductance;
	double current=0.0;
public:
	Inductor(double _inductance );
	double GetCurrent(double voltage, double timeStep);
};

