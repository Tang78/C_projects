
#pragma once
#include<iostream>
#include <stdbool.h>
#include"inductor.h"
Inductor::Inductor(double _inductance) {
	inductance = _inductance;
}
double Inductor::GetCurrent(double voltage, double timeStep) {
	current += voltage * (timeStep / inductance);
	return current;
}
