//This file contains the 'main' function for the temperature analyzer.
//Student Name: Orang Tang Enow
//Student Number: 14992421 
//SEP 101 FUNDAMENTALS OF PROGRAMMING
//Date: 28/09/2021

#include <stdio.h>

int  main()
{     
	float  Hightemp[4];//store all high temperatures daily
	float Lowtemp[4];//store all low tempratures daily
	int i;
	float TotalTemp = 0;
	float hightempTotal = 0;//total of higest temprature
	float lowtempTotal = 0;//total of lowest temprature
	const int LowestPossibleTemp = -40;//lowest temperature should not exceed this
	const int HighestPossibleTemp = 40;//highest temperature should not exceed this
	float Averagehightemperature = 0;
	float Averagelowtemperature = 0;
	int indexHighestTemp = 0;//overall  index of highest temperature of all the days 
	int indexLowestTemp = 0;//overall index of  lowest temperature of all the days 
	float HighestTemp = 0;//overall highest temperature of all the days 
	float LowestTemp = 0;//overall lowest temperature of all the days
	int validEntry = 0;
	printf("\n------------------SEP TEMPERATURE ANALYZER--------------------------\n\n");
	for (i = 0; i < 4; i++) {
		do {//Validate temperature
			printf("\n\nEnter the value of higest temperature of day %d:\n", i +1);
			scanf_s("%f", &Hightemp[i]);
			printf("\n\nEnter the value of lowest  temperature of day %d:\n", i+1 );
			scanf_s("%f", &Lowtemp[i]);
			if (Hightemp[i] > HighestPossibleTemp || Lowtemp[i] < LowestPossibleTemp || Hightemp[i] < Lowtemp[i]) {
				validEntry = 0;
				printf("invalid entry.Temperature must be in the range  -40 to 40,high must be greater than low ");
			}
				else {
					validEntry = validEntry+1;//this should add up up to the number entries entered for both high and low temperatures
				}
		} while (validEntry == 0);
	}
		printf("\n\nThe high temperatures are %f,%f,%f,%f\n\n", Hightemp[0], Hightemp[ 1], Hightemp[ 2], Hightemp[ 3]);//Display the hightemperature values at this indexces
		printf("\n\nThe low  temperatures are %f,%f,%f,%f\n\n", Lowtemp[0], Lowtemp[ 1], Lowtemp[ 2], Lowtemp[ 3]);//Display the lowtemperature values at this indexces
		
		for (i = 0; i < 4; i++) {
			hightempTotal =hightempTotal +Hightemp[i];
		}
		for (i = 0; i < 4; i++) {
			lowtempTotal = lowtempTotal+ Lowtemp[i];
		}
		TotalTemp = TotalTemp + hightempTotal + lowtempTotal;

		printf("\n\nThe average high temperature is %f\n\n", hightempTotal / 4);//we notice that valid entry will store 4 which is the number of inputs of hightemperature input .We use the value to calculate average
		printf("\n\nThe average low temperature is %f\n\n", lowtempTotal / 4);//we notice that valid entry will store 4 which is the number of inputs of lowtemperature  input . We use the value to calculate average
		printf("\n\n The average temperature of all temperature is %f", TotalTemp / 8);
		for (i = 0; i < 4; i++) {
			if (Hightemp[i] > HighestTemp) {
				HighestTemp = Hightemp[i];
				indexHighestTemp = i+1;
                }
		}
		printf("\n\nThe  higest temperature of all the days is %f and occured on day %d\n\n " ,HighestTemp, indexHighestTemp);//this will give us the day and value of the general highest value of all high temperatures

		for (i = 0; i < 4; i++) {
			if (Lowtemp[i] < LowestTemp) {
				LowestTemp = Lowtemp[i];
				indexLowestTemp = i+1;
			}
		}
		printf("The  Lowest  temperature of all the days is %f and occured on day %d ", LowestTemp, indexLowestTemp);//this will give us the day and value of the general lowest value of all low temperatures
}


//      QUESTIONS
//What variable type did you use to store your temperatures and why?
//                  FLOAT: Because temperatures can be rational and the range of temperature values lies betwenn -40 and +40
//                         which makes float the most efficient datatype in this scenario.
//What variable type did you use to store the indices into your arrays and why ?
//                  INTEGER: This is because the index in this problem has to satisfy certain contraints which include:
//                         a)The index should be of integral type
//                         b)The type should be widw enough to accomodate "usual arithmetic conversions"
//                            
//What variable type did you use to store the averages and why ?
//                  FLOAT: Because we want to avoid loss of information since the other variables we are manipulating are of type float
//                         equally sometimes division can lead to rational numbers so we use float to store small sizes of rational numbers rather than double
//Would you prefer not to use arrays in this scenario ?
//                          NO




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
