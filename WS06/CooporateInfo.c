//CorporateInfo.c - function definitions for corporate information

#include "CooporateInfo.h"
#include<string.h>

bool GetAverageSalary(struct CorporateInfo* corp) {
	int retVal =true;
	double runningTotal = 0;
	int num = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (corp->employee[i].salary < 0) {
			retVal =false;
		}
		else {
			runningTotal += corp->employee[i].salary;
			++num;
		}
	}
	if (retVal) {
		corp->averageSalary = (double)runningTotal / num;
	}
	else {
		corp->averageSalary = INVALID_VALUE 
	}
	return retVal;
}

bool GetAverageAge(struct CorporateInfo* corp) {
	bool retVal = true;
	double runningTotal = 0;
	int num = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (corp->employee[i].age < 0) {
			retVal = false;
		}
		else {
			runningTotal += corp->employee[i].age;
			++num;
		}
	}
	if (retVal) {
		corp->averageAge = (double)runningTotal / num;
	}
	else {
		corp->averageAge = INVALID_VALUE;
	}
	return retVal;
}

bool GetMaximumSalary(struct CorporateInfo* corp) {
	bool retVal = true;
	corp->maximumSalary = 0;
	corp->indexMaximumSalary = 0;
	for (int i = 0; i < NUM_EMPLOYEES && retVal; ++i) {
		if (corp->employee[i].salary < 0) {
			retVal = false;
		}
		else {
			if (corp->employee[i].salary > corp->maximumSalary) {
				corp->maximumSalary = corp->employee[i].salary;
				corp->indexMaximumSalary = i;
			}
		}
	}
	if (!retVal) {
		corp->maximumSalary = INVALID_VALUE;
		corp->indexMaximumSalary = INVALID_VALUE;
	}
	return retVal;
}

void clearKeyboard(void) {
	while (getchar() != '\n');
}
void utilClearInputBuffer(void) {// this will clear the buffer and enable the user to input next value
  char c;
	do {
		c = getchar();
	} while (c != '\n');
}

void pause(void) {
	printf("(Press Enter to continue)");
	clearKeyboard();
}


int getInt(void)
{
	int val;
	int rc = 0;
	char nextChar = '\n';
	do {
		rc = scanf("%d%c", &val, &nextChar);
		if (rc == 0 || nextChar != '\n') {
			clearKeyboard();
			printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		}
	} while (rc == 0 || nextChar != '\n');
	return val;
}

double getDouble(void) {
	double val;
	int rc = 0;
	char nextChar = '\n';
	do {
		rc = scanf("%lf%c", &val, &nextChar);
		if (rc == 0 || nextChar != '\n') {
			clearKeyboard();
			printf("*** INVALID DOUBLE *** <Please enter a double>: ");
		}
	} while (rc == 0 || nextChar != '\n');
	return val;
}

bool FindEmployeeByName(struct CorporateInfo corp, int* index) {
	char searchname;
	bool retval = true;
	Printf("Enter the name you want to search for ");
	scanf_s("%[^\n]s", searchname);
	for (int i = 0; i < 5; i++)
	{
		if(strcmp (searchname ,corp.employee[i].name) ==0){ 
		index=i;
			retval = true;
		}
		else {
			retval = false;
		}
     }
	return retval;
}

void PrintEmployeeInfo(struct CorporateInfo corp, int index) {//given the index of the employee in the employee array, print the information for that employee
	printf("%s,%s is %lf  years old and has a salary of %lf", corp.employee[index].name, corp.employee[index].position, corp.employee[index].age, corp.employee[index].salary);

}

void PrintEmployeesInfo(struct CorporateInfo corp){	//print employee information for all employees
{
	for (int i = 0; i < 5; i++)
	{
		printf("%s,%s is %lf  years old and has a salary of %lf", corp.employee[index].name, corp.employee[index].position, corp.employee[index].age, corp.employee[index].salary);

	}
}

void CorrectEmployeeName(struct CorporateInfo* corp, int index) {//given the index of the employee in the employee array, change the name of that employee
	printf("Enter the Employees new Full Name : ");
	scanf_s("%s", corp.employee[index].name, BUFSIZE);
}

void CorrectEmployeeAge(struct CorporateInfo* corp, int index) {	//given the index of the employee in the employee array, change the age of that employee
	int intVal = 0;
	double doubleVal = 0.0;

	do {
		printf("Enter an integer value  for new AGE(-98 to quit):");
		intVal = getInt();
		if (intVal != -98) {
			printf("Enter a double value for new AGE (-98 to quit): ");
			doubleVal = getDouble();
		}
		pause();
	} while (intVal != -98 && doubleVal != -98.0);
	IntVal = corp.employee[index].age;
	return 0;
}
	
}

void ChangeEmployeePosition(struct CorporateInfo* corp, int index) {	//given the index of the employee in the employee array, change the position of that employee
	printf("Enter the Employees New Position : ");
	scanf_s("%s", corp.employee[index].position,BUFSIZE);
}

void ChangeEmployeeSalary(struct CorporateInfo* corp, int index) {	//given the index of the employee in the employee array, change the salary of that employee
	int intVal = 0;
	double doubleVal = 0.0;

	do {
		printf("Enter an integer value  for new Salary(-98 to quit):");
			intVal = getInt();
		if (intVal != -98) {
			printf("Enter a double value for new Salary (-98 to quit): ");
			doubleVal = getDouble();
		}
		pause();
	} while (intVal != -98 && doubleVal != -98.0);
	IntVal = corp.employee[index].salary;
	return 0;
}

void WriteToDatabase(struct CorporateInfo corp) {	//Write employee information for all employees to the file EmployeeDB.txt
	fp = fopen("EmployeeDB.txt", "w");

			for (int i = 0; i < NUM_EMPLOYEES && retVal == 0; ++i) {
				fprintf(fp, "%[^\n]s", corp.employee[i].name BUFSIZE);
				while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
				fprintf(fp, "%[^\n]s", corp.employee[i].position);
				fprintf(fp, "%lf", &corp.employee[i].salary);
				fprintf(fp, "%lf", &corp.employee[i].age);
				while (fgetc(fp) != '\n');//clear the file buffer before the next fscanf()
			}
		fclose(fp);
}