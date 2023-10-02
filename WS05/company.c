//ORANG TANG ENOW
//149924219
//SEP (FUNDAMENTALS OF PROGRAMMING 
//LAB 5

#include <stdio.h>
#include "company.h"   // my header file ,this include company.h 
# define NUM 5

void InitializeInfo(struct CompanyInfo *companyinfo) 
{//InitializeInfo(&Company);

	companyinfo->name[0] = '\0';
	companyinfo->symbol[0] = '\0';
	companyinfo->annualdivident = 0.00;
	companyinfo->stockprice = 0.00;
	companyinfo->Yield = 0.00;
	companyinfo->valuation[0] = '\0';

}
		

		char valuation(struct CompanyInfo* companyinfo)
		{
			strcpy_s(companyinfo[i].valuation, MAX_STR, "");//this function will copy the value of the second argument and pass it to the first
				if (companyinfo[i].Yield < (float)5.00) {
					strcpy_s(companyinfo[i].valuation, MAX_STR, "OVER VALUED");
				}
				else if (companyinfo[i].Yield > (float)5.00) {
					strcpy_s(companyinfo[i].valuation, MAX_STR, "UNDER VALUED");
				}
				else {
					strcpy_s(companyinfo[i].valuation, MAX_STR, "VALUED");
				}
			return 0;

		}


float Yieldinfo(struct CompanyInfo *companyinfo) {

	w = 100 * companyinfo[i].annualdivident;//this two functions enable me calculate the yield accurately and return the value a to the company.yield
	a = w / companyinfo[i].stockprice;
         return a;
}
void utilClearInputBuffer(void) {// this will clear the buffer and enable the user to input next value
	
	char c;
	do {
		c = getchar();
	} while (c != '\n');
}


int main() {

	struct CompanyInfo companyinfo[NUM];
	InitializeInfo(&companyinfo);
	printf("------------------------------------INFORMATION OF COMPANIES------------------------------------------\n");
	for (i = 0; i < 5; i++) {
		printf("Enter COMPANY   name:");
		scanf_s("%[^\n]s", &companyinfo[i].name, MAX_STR);
		utilClearInputBuffer();
		printf("Enter %s's stock symbol:", companyinfo[i].name);
		scanf_s("%[^\n]s", companyinfo[i].symbol, MAX_STR);

		printf("Enter %s's  current stock price:", companyinfo[i].name);
		scanf_s("%f", &companyinfo[i].stockprice);

		printf("Enter %s's  annual divident per share:", companyinfo[i].name);
		scanf_s("%f", &companyinfo[i].annualdivident);
		utilClearInputBuffer();
		printf("\n\n");
		companyinfo[i].Yield = Yieldinfo(&companyinfo);
		valuation(&companyinfo);
	}
	printf("COMPANY           SYMBOL          PRICE            DIV             YIELD         VALUATION \n");

	for (int i = 0; i < 5; ++i) {
		printf("%s                %s               %f             %f          %f          %s   \n", companyinfo[i].name, companyinfo[i].symbol, companyinfo[i].stockprice, companyinfo[i].annualdivident, companyinfo[i].Yield, companyinfo[i].valuation);

	}





}
//QUESTIONS
/*Explain whether a structure was necessaryand if so, explain why you composed your structure as you did.
* A structure was neccessary because it helped me store diffrent data types
2) I used functions one to clear the buffer so that it can give space for the input of the next value
I used a valuation function which  i passed the address of the structure so i could determine if a company was valued,overvalued or undervalued
I used a yieldinfo function to calculate the yield of all the companies
I equally used an initializeinfo so that all the values stored in the members could be initialized to 0
3)Explain whether any loops were necessary, and why.
I used a for loop to enable me get values for all the 5 companies
*/

		





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln f


