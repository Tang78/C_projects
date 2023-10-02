//PetInfo.cpp - function definitions for the pet
#include "Grocery.h"
#include <iomanip>
using namespace std;

const int NUM = 5;
GroceryInfo grocery[NUM];

std::string GroceryInfo::GetName() const {
	return name;

}

std::string GroceryInfo::GetTax() const {
	return tax;
}

double GroceryInfo::GetCost() const {
	return cost;
}

int GroceryInfo::GetBarcode() const {
	return barcode;
}
bool GroceryInfo::SetName(std::string _name) {
	bool retVal = true;
	if (_name.size() == 0) {
		retVal = false;
	}
	else {
		name = _name;
	}
	return retVal;
}
bool  GroceryInfo::SetBarcode(int _barcode)  {
	bool retVal = true;
	if (_barcode < 1) 
		retVal = false; 
	  
	else {
		barcode = _barcode;
	}
	return retVal;
}

bool GroceryInfo::SetTax(std::string _tax) {
	bool retVal = true;
	if (_tax.size() == 0) {
		retVal = false;
	}
	else {
		tax= _tax;
	}
	return retVal;

}

bool GroceryInfo::SetCost(float _cost) {
	bool retVal = true;
	if (_cost < 0) {
		retVal = false;
	}
	else {
		cost = _cost;
	}
	return retVal;
}
  void GroceryInfo::CalculateSubtotal() {
	for (int i = 0; i < 5; i++) {
		subtotal += grocery[i].SetCost(cost);
	}
}
void GroceryInfo::CalculateTax() {
	for (int i = 0; i < 5; i++) {
		totaltax += (grocery[i].SetCost(cost) * 0.13);
	}
}
void GroceryInfo::CalculateTotal() {
	total += subtotal + totaltax;
}
void GroceryInfo::PrintReport() {
	for (int i = 0; i < NUM; ++i) {
		//			cout.width(10);//best to put these inside the stream itself
		cout.setf(ios::right);
		cout << "subtotal :" << setw(1) << subtotal<< setw(20) << "Totaltax:" << setw(1) << totaltax << setw(5) << " total: " << setw(1) << total << "\n";
	}
}
