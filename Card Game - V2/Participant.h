#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Deck.h"

using namespace std;


class Participant
{
public:

	void Stand();
	void AddCard(Deck& deck);
	void displayHand(string display_type, string participant);
	int Score(string participant);
	
	int score = 0;

protected:
	vector<Card> hand;
};

