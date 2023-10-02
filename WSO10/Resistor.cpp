#pragma once
#include<iostream>
#include <stdbool.h>
#include"Resistor.h"

Resistor::Resistor(double _resistance) {
	resistance= _resistance;
}
double Resistor::GetCurrent(double _voltage) {
	current = _voltage / resistance;
	return current;
}