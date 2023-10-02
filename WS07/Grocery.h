//PetInfo.h - class declaration for a pet

#include<iostream>
#include <stdbool.h>
//using namespace std;//never put using namespace inside a header file. The header file might be included
					  //by many other files which may not wish to use that particular namespace.

class GroceryInfo {
	int barcode;
public:
	std::string name;
    std::string tax;
	double cost;
	double subtotal;
	double totaltax;
	double total;
public:
	std::string GetName() const;
	std::string GetTax() const;
    double  GetCost() const;
	int  GetBarcode() const;
	bool SetName(std::string _name);
	bool SetTax(std::string _tax);
	bool SetCost(float _cost);
	bool SetBarcode(int _barcode);
   void CalculateSubtotal();
	void  CalculateTax();
	void  CalculateTotal();
	void PrintReport();
};
