#pragma once
#include<iostream>
#include <stdbool.h>
class Resistor{
	double resistance;
	double current = 0.0;
public:
	Resistor(double _resistance);
	double GetCurrent(double _voltage);
};
