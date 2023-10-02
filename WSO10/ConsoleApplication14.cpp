// ConsoleApplication14.cpp : This file contains the 'main' function. Program execution begins and ends                inductor and capacitor placed in parallel.

#define _USE_MATH_DEFINES
#include <fstream>
#include <iomanip>
#include <math.h>
#include "Resistor.h"//this assumes the class for the resistor is in Resistor.h
#include "inductor.h"//this assumes the class for the inductor is in Inductor.h
#include "Capacitance.h"//this assumes the class for the capacitor is in Capacitor.h

using namespace std;

int main(void) {
	//The following assume that the classes for the inductor, capacitor and resistor
	//are called Inductor, Capacitor, and Resistor
	Inductor inductor(0.01);//inductance of 0.01H
	Capacitor capacitor(0.0001);//capacitance of 0.0001F
	Resistor resistor(10.0);//resistance of 10ohms
	const double delta = 0.0001;//timestep of 0.0001 seconds
	const double frequency = 50.0;//the applied voltage has a frequency of 50Hz
	ofstream file("file.dat");


	//Insert the file header here ,
	file << setw(9) << "TIME" << setw(9) << "VOLTAGE" << setw(11) << "INDUCTOR"   << setw(11) <<   "CAPACITOR" << setw(9) << "RESISTOR" << setw(9) << "TOTAL" << endl;
	for (double time = 0.0; time < 0.1; time += delta) {//the simulation runs for 0.1 seconds
		double voltage = 100 * sin(2 * M_PI * frequency * time);//the applied voltage
		double currentInductor = inductor.GetCurrent(voltage, delta);//the current through the inductor
		double currentCapacitor = capacitor.GetCurrent(voltage, delta);//the current through the capacitor
		double currentResistor = resistor.GetCurrent(voltage);//the current through the resistor
		double totalCurrent = currentInductor + currentCapacitor + currentResistor;//the total current
		//Print the results to the file here
		file.setf(ios::fixed);
		file.precision(4);
		file << setw(9) << time <<setw(9) << voltage << setw(10) << currentInductor <<setw(9) << currentCapacitor <<setw(9) << currentResistor<< setw(9)<< totalCurrent<<endl;

	}
	file.close();
	//Clean up here

	return 0;
}
//Questions
// C++ is an ideal language for analog circuit simulation due to its speed. Can you think of any other useful simulation of any kind that could be written in C/C++ or any other language?
// We can use python in neural Simulation
//Name three reasons why simulators are very useful ?
//It increases accuracy level, It handles uncertainty,It saves time
 //The Engineering portion of product development goes through three phases : Design, Implementation, and Rework.In which of these three phases would simulation be most useful ?
 // i think simulation will be most useful in the Implementation stage.
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
