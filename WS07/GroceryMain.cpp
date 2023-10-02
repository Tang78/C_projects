#define NUM 5
#include <iomanip>//setw() setprecision()
#include "Grocery.h"//PetInfo.h includes iostream

using namespace std;

int main() 
{
	int Num;
	string name;
	float  cost{};
	int barcode{};
	string tax;
	int retVal;
	GroceryInfo grocery[NUM];
	cout << "Enter the number of grocery items(5 max) : \n";
	cin >> Num;
	for (int i = 0; i < Num; ++i)
	{
		

		do {
			cout << "Enter the name of the grocery item : "<<i+1;
			cin >> name;
			string GetName(name);
			retVal = grocery[i].SetName(name);
			if (!retVal) {
				cout << "Invalid Input";
			}
	} while (!retVal);
		do {
			cout << "Enter the Barcode of the grocery item " << i + 1 << ":\n";
			cin >> barcode;
			int GetBarcode(barcode);
			retVal = grocery[i].SetBarcode(barcode);

		} while (!retVal);
		do {
			cout << "Enter the cost of item " << i + 1 << ": \n";
			cin >> cost;
			float  GetCost(cost);
			retVal = grocery[i].SetCost(cost);
		} while (!retVal);
		do {
			cout << "Is the item Taxable? [Y/N]" << i + 1 << ":\n";
			cin >> tax;
			string GetTax(tax);
			retVal = grocery[i].SetTax(tax);
		} while (!retVal);
	}
	for (int i = 0; i < Num; ++i) {
		cout.width(10);//best to put these inside the stream itself
		cout.setf(ios::right);
		cout << "name :" << setw(10) << setfill('.') << grocery[i].name << setw(20) << setfill('*') << "cost:" << grocery[i].cost << setw(5) << "tax: " << grocery[i].tax << "\n" << endl;
		//cout << setw(10) << setfill('.') << pets[i].GetName() << " is a " << setw(6) << setfill('*') << pets[i].GetType() << " and is " << setw(2) << pets[i].GetAge() << " years old." << endl;

	}
		void CalculateSubtotal();
		void  CalculateTax();
		void  CalculateTotal();
	//for (int i = 0; i < NUM; i++) {
		 void PrintReport();
	//}
	return 0;
}
/*Questions 
* Which members of your class are visible to the outside world and which members are hidden from the outside world
* int barcode; is hidden from the outside world
* while the following are visible to the outside world
	std::string name;
    std::string tax;
	double cost;
	double subtotal;
	double totaltax;
	double total;
Why do we use accessor functions to get or set these private members?
-- because   it accesses  all the private variables inside class Grocery
Do you see your class as a blackbox or as a whitebox, or as a bit of each?





*/

		   


    

