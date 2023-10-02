//Account.h - Header file for account information

#include<iostream>
#include <stdbool.h>
class Game {
	std::string name;
	double cash;
	int* cards;
	int numcards;
public:
	Game(std::string Name);
	std::string GetName();
	void drawCards(int numCards);
	int SumCards();
	void stealnumCards(Game& player);
	bool  AddCash(int amount);
	void Report();
	void destroy();
	~Game();
};
