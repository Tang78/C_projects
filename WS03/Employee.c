//This file contains the 'main' function for Employee information 
//Student Name: Orang Tang Enow
//Student Number: 14992421 
//SEP 101 FUNDAMENTALS OF PROGRAMMING
//Date: 28/09/2021
// Empoplee.c is the main program for the Employee Information

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "Employee.h"// my header file ,this includes emplooyee.h which has the values for age ,id,salary
int  main()

{

	int size = 4;//we initialize  employee to an array which we give it a size of 4
	struct Employee employee[] = {
		{22367,25,60000},//this are the values for id,age and salary stored 
		{15780, 32, 70000},
		{43679, 30, 80000},
		{43679, 30, 160000},
	};
			int i=0;
			int number = 0;
			int found = 0;
			int validEntry;//This will help us determine if the value entered is valid
			int option;

	printf("\n------------------EMPLOYEE DATA--------------------------\n\n");
	do {
		printf("1. Display Employee Information\n2. Add Employee\n3. Update Employee Salary\n4. Remove Employee\n0. Exit\n\nPlease select from the above options : ");
			scanf_s("%d", &option);
			switch (option)//This will help me take one condition at a time
			{
			case 0:
           printf("Exit the program\n");//this case causes the program toi come to an end
		   validEntry = 0;//Ensures that we enter only the write values required
				break;
			case 1:
				printf("Display Employee Data\n\n");
				printf("EMP ID  EMP AGE   EMP SALARY\n");//Enables us display the values in the array we stored
				int i;
				for (i = 0; i < size; i++) {//the space is just for alignment
					printf("%d      %d          %f\n\n", employee[i].id, employee[i].Age, employee[i].Salary);
				}
					validEntry = 1;
					break;

			case 2:
				printf(" Adding Employee \n ");//Here is for us adding a new employee
				int found = 0;//we define found here so we can determine if there is available space to input a new Employee
				for (i = 0; i < 3 && found == 0; i++) {
					if (employee[i].id == 0) {
						found = 1;
							printf("Enter Employee ID:\n");
						scanf_s("%d", &employee[i].id);
						printf("Enter Employee AGE\n");
						scanf_s("%d", &employee[i].Age);
						printf("Enter Employee Salary\n");
						scanf_s("%f", &employee[i].Salary);
					}
				}

				if (found == 0) {
					printf("ERROR!!! Maximum Number of Employees Reached\n");
				}
				else {
					printf("EMPLOYEE SUCCESFULLY ADDED\n");
				}
				validEntry = 1;
				break;
			case 3:
			printf("Update Employee Salary\n");
			int number;
			found = 0;
			printf("Enter Employee id : ");
			scanf_s("%d", &number);
			for (i = 0; i < 3 && found == 0; i++)//this will test values untill we get the value exact as what is imputed
				if (employee[i].id == number) {
					found = 1;
					printf("Enter new value for salary: ");
					scanf_s("%f", &employee[i].Salary);//Enter the new salary we want to save
					printf("SUCCESSFULLY UPDATED EMPLOYEE SALARY*****\n\n");
				}
				else {
					printf("* **ERROR: Employee ID not found!***\n\n");//if the id entered does not match then this should be displayed
				}validEntry = 1;
			break;
			case 4:
				printf("Remove Employee\n");
				 number;
				 found = 0;
				printf("Enter Employee id: ");
				scanf_s("%d", &number);
				for (i = 0; i < 3 && found == 0; i++)//we will be able to compare the inputed value and search untill we get the corresponding id the cancel everything
					if (employee[i].id == number) {
						found = 1;
						employee[i].Age = 0;
						employee[i].id= 0;
						employee[i].Salary = 0;
						printf("Employee successfully removed\n");
					}
					else {
						printf("* **ERROR: Employee ID not found!***\n");
					}validEntry = 1;
				break;
			default:
				printf("ERROR: Incorrect Option: Try Again\n\n");//if non of the cases display then this will display
                 validEntry = 1;
			}
			
	} while (validEntry != 0);
			printf("Exiting Employee Data Program. Good Bye!!!\n");

			return 0;
}
//QUESTIONS
// 1)Would you prefer to use parallel arrays for id, age and salary or do you prefer an array of structures, and why?
//Array of structures.This is because parallel arrays cannot store variables of different data types
//2)How closely related is a structure in C to a schema in a database (you may have to research what a database schema is)?
//	They both can store diffrent data types 
//3) The code will print 103, java

		





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
