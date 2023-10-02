#include<iostream>
#include"game.h"
#define MAX 21
using namespace std;
const int Max = 21;

  Game :: Game(std::string Name){
	   name=Name;
	  cash = 1000;
	  cards =nullptr;
	  numcards = 0;
}
std::string  Game::GetName() {
	  return name;
}
void Game::drawCards(int numCards) {
	numcards = numCards;
	if (cards != nullptr) {
		destroy();
	}
	cards = new int[numCards];
	if (numCards < MAX) {
		for (int i = 0; i < numCards; i++) {
			cards[i] = (rand() % 10) + 1;
		}
	}
}
int  Game::SumCards() 
{
	int runningtotal=0;
	for (int i = 0; i < numcards; i++) {
		runningtotal = runningtotal+ cards[i];
	}
	return runningtotal;
 }
void Game::stealnumCards(Game& player) {
 //this refers to player1, player refers to player2
if (this != &player) {
		delete[] this->cards;
		this->cards= nullptr;
		this->numcards = player.numcards;
		this->cards = new int[this->numcards];
		for (int i = 0; i < this->numcards; i++) {
				this->cards[i] = player.cards[i];
		}
		delete[] player.cards;
		player.cards = nullptr;
	}
}
bool Game::AddCash(int amount) 
{
   cash += amount;
   if (cash < 0)
   {
	   return true;
   }
   else {
	   return false;
   }
}
void Game::Report() {
	cout.setf(ios::fixed);
	cout.precision(2);
	cout << name << "You have $" << cash << "left over " << endl;
}
void Game::destroy() {
	delete[] cards;
	cards = nullptr;
}
Game::~Game() {
	if (cards != nullptr) {
		delete[] cards;
		cards= nullptr;
	}
}

