//ObjectMain.cpp - main program for moving objects on the moon and on earth
//Orang Tang Enow
// Lab 8
// 18-Mar-21  M. Watler         Created.

#include <iostream>
#include "MoonObject.h"
#include "EarthObject.h"

using namespace std;

int main(void) {
	
	double earthgravity = 9.81;
	double moongravity = 9.0;
   double initialHeightEarth = 100;
	double horizontalSpeedEarth = 100;
	double initialHeightMoon = 100;
	double initialVerticalSpeedMoon = 10;
    double horizontalSpeedMoon = 100;
	MoonObject moon(initialHeightMoon, horizontalSpeedMoon, initialVerticalSpeedMoon);
	EarthObject earth(initialHeightEarth, horizontalSpeedEarth,earthgravity );
	double time;
	for (time = 0.0; moon.GetYPos(time) > 0 && earth.GetYPos(time) > 0; time += 0.001) {

	}

	cout << "time:" << time << endl;
	cout << "The moon object's horizontal position is " << moon.GetXPos(time) << "m and vertical position is " << moon.GetYPos(time) << "m" << endl;
	cout << "The earth object's horizontal position is " << earth.GetXPos(time) << "m and vertical position is " << earth.GetYPos(time) << "m" << endl << endl;

	bool valid;

	//TODO: Prompt the user to enter new parameters for the moon object and the earth object.
	//      For the moon, the parameters are: initial height, initial vertical speed, and the horizontal speed.
	//      For the earth, the parameters are: initial height and the horizontal speed.
	//Be sure to perform validation on the entered values.

	cout << "Enter the moon's object  horizontal Speed  " << endl;
	cin >> horizontalSpeedMoon;
	moon.SetSpeed(horizontalSpeedMoon);
	cout << "Enter the moon's object initial vertical speed" << endl;
	cin >> initialVerticalSpeedMoon;
	moon.SetVerticalSpeed(initialVerticalSpeedMoon);
	cout << "Enter the moon's object initial height " << endl;
	cin >> initialHeightMoon;
	moon.SetHeight(initialHeightMoon);
	cout << "Enter the earth's object horizontal Speed " << endl;
	cin >> horizontalSpeedEarth;
	earth.SetSpeed(horizontalSpeedEarth);
	cout << "Enter the earth's object initial height " << endl;
	cin >> initialHeightEarth ;
	earth.SetHeight(initialHeightEarth);
	for (time = 0.0; moon.GetYPos(time) > 0 && earth.GetYPos(time) > 0; time += 0.001) {}

	cout << endl;
	cout << "time:" << time << endl;
	cout << "The moon object's horizontal position is " << moon.GetXPos(time) << "m and vertical position is " << moon.GetYPos(time) << "m" << endl;
	cout << "The earth object's horizontal position is " << earth.GetXPos(time) << "m and vertical position is " << earth.GetYPos(time) << "m" << endl;

	return 0;
}
//In this lab the constructor has been overloaded. Do you see any other functions that might require overloading in either class?
// SetSpeed,SetHeight,GetXPos,GetYpos
//Do you prefer setting class variables by the constructor or by setter functions ? Why ?
// Setter functions because it will make it more efficient
//The class for the moon objectand the class for the earth object are so similar.Describe how you could merge both of them into one class called Object.
// we can create a class say gravity and use the earth and the moon as objects oif that class whgich have the given functions then we pass their value using a constructor