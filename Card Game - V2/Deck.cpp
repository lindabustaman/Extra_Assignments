#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Card.h"
#include "Deck.h"

using namespace std;

void Deck::Init()
{
	for (int i = 0; i < 13; i++)
	{
		for (int f = 0; f < 4; f++)
		{
			Card card = { Card::Suit[f], Card::Rank[i], Card::Value[i] };
			deck.push_back(card);
		}
	}
}

void Deck::displayCard(Card card)
{
	cout << card.rank << " of " << card.suit << endl;
}


//Deal card randomly by choosing random index from deck vector
Card Deck::dealCard()
{
	srand(time(0));
	int g = rand() % deck.size();
	Card dealt = deck[g];
	deck.erase(deck.begin() + g);
	return dealt;
}
