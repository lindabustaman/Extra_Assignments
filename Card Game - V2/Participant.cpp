#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Card.h"
#include "Deck.h"
#include "Participant.h"

using namespace std;

void Participant::Stand()
{
}

void Participant::AddCard(Deck& deck)
{
	Card newCard = deck.dealCard();
	hand.push_back(newCard);
}

void Participant::displayHand(string display_type, string participant)
{
	if (display_type == "one_card")
	{
		cout << participant << "'s Hand:" << endl;
		Deck::displayCard(hand[0]);
		cout << "Hidden" << endl << endl;

	}

	else if (display_type == "hand")
	{
		cout << participant << "'s Hand:" << endl;
		for (Card card : hand)
		{
			Deck::displayCard(card);
		}
		cout << endl;
	}
}

int Participant::Score(string participant)
{
	for (Card card : hand)
	{
		score += card.value;
	}
	return score;
}