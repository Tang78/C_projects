#pragma once
#include<iostream>
#include <stdbool.h>
#include"Capacitance.h"
Capacitor::Capacitor(double _capacitance) {
	capacitance = _capacitance;
}
double Capacitor ::GetCurrent(double _voltage, double timeStep) {
	current = capacitance * (_voltage - voltage) / timeStep;
	voltage = _voltage;
	return current;
}