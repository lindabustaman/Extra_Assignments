#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "Card.h"

using namespace std;

class Deck
{
public:
	void Init();
	static void displayCard(Card card);
	Card dealCard();

private:
	vector<Card> deck;

};
