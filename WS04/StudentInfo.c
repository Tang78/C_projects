//This file contains the 'main' function for Employee information 
//Student Name: Orang Tang Enow
//Student Number: 14992421 
//SEP 101 FUNDAMENTALS OF PROGRAMMING
//Date: 28/09/2021
// Empoplee.c is the main program for the Employee Information

#include <stdio.h>
#include "Employee.h"// my header file ,this includes emplooyee.h which has the values for age ,id,salary
/*
	struct Subject{
		int mark;
		char name[MAX_STR];
	};
	struct StudentInfo {
		char lastname[MAX_STR];
		int studentId;
		struct Subject subject[NUM_SUBJECTS];
		int numsubjects;
	};
*/
float averagemark(struct Subject* subject){
	float sum = 0;
	int number = 0;
	for(int i=0;i<NUM_SUBJECTS;i++){
		if(subject[i].mark == 0){
			break;
		}
		sum = sum+subject[i].mark;
		number++;//this will store thenumber of subject marks which will be used to calculate average
	}
	return sum/number;
}
int max(struct Subject* subject){
	int maximum = subject[0].mark;
	int index = 0;
	for(int i=1;i<NUM_SUBJECTS;i++){
		if(subject[i].mark == 0){
			break;
		}
		if(maximum<subject[i].mark){
			maximum = subject[i].mark;
			index = i; 
		}
	}
	return index;
}
int min(struct Subject* subject){
	int minimum = subject[0].mark;
	int index = 0;
	for(int i=1;i<NUM_SUBJECTS;i++){
		if(subject[i].mark == 0){
			break;
		}
		if(minimum>subject[i].mark){
			minimum = subject[i].mark;
			index = i;
		}
	}
	return index;
}
void initializeinfo(struct StudentInfo* studentinfo){
	(*studentinfo).lastname[0] = '\0';
	(*studentinfo).studentId = 0;
	for(int i = 0;i<NUM_SUBJECTS;i++){
		(*studentinfo).subject[i].name[0] = '\0';
		(*studentinfo).subject[i].mark = 0;
	}
}
int main() {
	struct StudentInfo studentinfo;
	initializeinfo(&studentinfo);
	
	int i;
	printf("Enter Student last name\n");
	scanf_s("%s", studentinfo.lastname);
	
	printf("Enter student ID\n");
	scanf_s("%d", &studentinfo.studentId);
	
	printf("Enter number of subjects\n");
	scanf_s("%d", &studentinfo.numsubjects);
	
	for(i=0;i < studentinfo.numsubjects;i++){
		printf("Enter the name of subject %d:\n ", i + 1);
		scanf_s("%s", studentinfo.subject[i].name);

		printf("Enter the mark for %s:\n ", studentinfo.subject[i].name);
		scanf_s("%d", &studentinfo.subject[i].mark);
	}

	float average = averagemark(studentinfo.subject);
	int maxIndex = max(studentinfo.subject);
	int minIndex = min(studentinfo.subject);	

	printf("\n");
	printf("%s with id %d has an average mark of %.2f.\n", studentinfo.lastname, studentinfo.studentId, average)// dispalys the value of average anad the name of student
	printf("%s's highest mark was %d in %s.\n", studentinfo.lastname, studentinfo.subject[maxIndex].mark, studentinfo.subject[maxIndex].name); //dispalys the value of the maximum number and the name of student
	printf("%s's lowest mark was %d in %s.\n", studentinfo.lastname, studentinfo.subject[minIndex].mark, studentinfo.subject[minIndex].name);

	//Questions
	//1) prefare using initializeinfo,averagemark ,min,max because it cause less ambiguity and it enables me get the mark for each student in less time .
	//2)I think passing them in the main function makes it easy for me a return a value or calkl a function
	





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
