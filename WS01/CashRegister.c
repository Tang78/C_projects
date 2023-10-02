// First lab.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>

  int  main()
{
      //My name is  Orang Tang Enow 
      //FUNDAMENTALS OF PROGRAMMING       SEP 101
      int  remainder, Dollars,Quaters,Dimes,Nickels,Pennies;
    float Item1 , Item2,Item3, sum;
    //MY FIRST LAB WORK
    printf("Enter the price of  the first item you bought:\n");
    scanf_s("%f",&Item1);// Input price of first item
    printf("Enter the price of the secound item you bought:\n");
    scanf_s("%f",&Item2);// Input price of second item
    printf("Enter the price of the third item you bought:\n");
    scanf_s("%f",&Item3);// Input price of third item
    sum = Item1 + Item2 + Item3;
    printf("The total sum is %f :\n", sum);
    remainder = sum * 100 + 0.0001; 
    Dollars=remainder/100;
    remainder = remainder % 100;
    Quaters = remainder / 25;
    remainder = remainder % 25;
    Dimes = remainder / 10;
    remainder = remainder % 10;
    Nickels = remainder / 5;
    remainder = remainder % 5;
    Pennies = remainder;
    printf("You used ,%d dollar,%d quaters,%d dimes,%d nickels,%d pennies", Dollars, Quaters, Dimes, Nickels, Pennies);
    return 0 ;
        

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
