// ConsoleApplication13.cpp : This file contains the 'main' function. Program execution begins and ends the#include <iostream>
#include <iostream>
#include "game.h"
const int Max = 21;

using namespace std;

int main(void)
{
	int amount;
	int numCards;
	string stealCards;
	bool endgame = false;


	Game player1("New York State of Mind");
     Game player2("Street Smarts");
	do 
	{
		cout << "How much do you want to bet? $";
		cin >> amount;
		cout << player1.GetName() << ", how many cards do you want to draw? ";
		cin >> numCards;
		player1.drawCards(numCards);
		cout << player2.GetName() << ", how many cards do you want to draw? ";
		cin >> numCards;
		player2.drawCards(numCards);
		cout << endl;
		cout << player1.GetName() << ", you have " << player1.SumCards() << " points. Do you wish to steal the cards from " << player2.GetName() << "? [Y/N]";
		cin >> stealCards;
		if (stealCards == "Y" || stealCards == "y") {
			player1.stealnumCards(player2);
			cout << player2.GetName() << ", your cards have been stolen. How many cards do you want to draw? ";
			cin >> numCards;
			player2.drawCards(numCards);
		}
		cout << endl;
		cout << player2.GetName() << ", you have " << player2.SumCards() << " points. Do you wish to steal the cards from " << player1.GetName() << "? [Y/N]";
		cin >> stealCards;
		if (stealCards == "Y" || stealCards == "y") {
			player2.stealnumCards(player1);
			cout << player1.GetName() << ", your cards have been stolen. How many cards do you want to draw? ";
			cin >> numCards;
			player1.drawCards(numCards);
		}cout << endl;
		cout << player1.GetName() << " has drawn " << player1.SumCards() << " points and " << player2.GetName() << " has drawn " << player2.SumCards() << " points." << endl;

		cout << endl;
		bool player1Disqualified = false;
		bool player2Disqualified = false;
		if (player1.SumCards() > Max) {
			cout << player1.GetName() << " has gone over the limit." << endl;
			player1Disqualified = true;
		}
		if (player2.SumCards() > Max) {
			cout << player2.GetName() << " has gone over the limit." << endl;
			player2Disqualified = true;
		}
		if (!player1Disqualified && player2Disqualified) 
		{
			cout << player1.GetName() << " has won!" << endl;
		   bool  ret = player1.AddCash(amount);
			ret = player2.AddCash(-amount);
			if (ret== true) {
				endgame = true;
			}
			else {
				endgame = false;
			}
		}
		else if (!player2Disqualified && player1Disqualified) 
		{
			cout << player2.GetName() << " has won!" << endl;
			bool ret = player2.AddCash(amount);
			ret = player1.AddCash(-amount);
			if (ret== true) {
				endgame = true;
			}
			else {
				endgame = false;
			}
		}
		else if (player1.SumCards() > player2.SumCards() && !player1Disqualified) 
		{
			cout << player1.GetName() << " has won!" << endl;
			bool ret = player1.AddCash(amount);
			ret = player2.AddCash(-amount);
			if (ret== true) {
				endgame = true;
			}
			else {
				endgame = false;
			}
		}
		else if (player2.SumCards() > player1.SumCards() && !player2Disqualified) 
		{
			cout << player2.GetName() << " has won!" << endl;
			bool ret = player2.AddCash(amount);
			ret = player1.AddCash(-amount);
			if (ret== true) {
				endgame = true;
			}
			else {
				endgame = false;
			}
		}
		else if  (player1.SumCards() == player2.SumCards() && !player1Disqualified && !player2Disqualified) 
		{
			cout << player1.GetName() << " and " << player2.GetName() << " have stayed within the limits and have tied." << endl;
		}
		cout << endl;
		player1.Report();
		player2.Report();
		cout << endl;
	} while (endgame==false);
	player1.destroy();
	player2.destroy();
	player1.~Game();
	player2.~Game();
	return 0;
}
/*
QUESTIONS
Can you explain the danger when a program allocates memory but forgets to deallocate it?
--The program will experience a memory leak .It will own that memeory but will not be  able to use it again.
For memory reallocation (creating new memory), where is the best place to deallocate memory in relation to its reallocation. Should the deallocation be close to the reallocation or far from it and why?
--Beside the reallocation.
How did you make use of the *this pointer in the lab?
--We used the this pointer when we wanted to steal cards from one player to the next.








*/


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
