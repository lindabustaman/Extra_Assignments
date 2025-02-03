#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Dealer.h"
#include "Deck.h"

using namespace std;


int main()
{
	Player player;
	Dealer dealer; 

	Deck deck;

	//Initialize deck 
	deck.Init();

	//Deal cards to player and dealer
	for (int i = 0; i < 2; i++)
	{
		player.AddCard(deck);
		dealer.AddCard(deck);
	}
	
	//Display player's and dealer's hand
	player.displayHand("hand", "Player");
	dealer.displayHand("one_card", "Dealer");

	//Player chooses to hit or stand 
	string choice = player.PlayerChoice();
	while (choice == "H")
	{
		player.AddCard(deck);
		player.displayHand("hand", "Player");
		choice = player.PlayerChoice();
	}

	//Game end, hands displayed and scores totaled
	player.displayHand("hand", "Player");
	player.Score("Player");
	player.AceValue();

	dealer.displayHand("hand", "Dealer");
	dealer.Score("Dealer");
	dealer.AceValue();
	//if (dealer.best_score < 16)
	//{
		//player.AddCard(deck);
		//dealer.AceValue();
	//}



	//Determine who wins
	if ((dealer.score > 21) && (player.score > 21))
	{
		cout << "Player and dealer busts! No one wins!";
	}
	else if (player.score > 21)
	{
		cout << "Player busts! Dealer wins.";
	}
	else if (dealer.score > 21)
	{
		cout << "Dealer busts! Player wins!";
	}
	else if ((dealer.score <= 21) && (player.score <= 21))
	{
		if (player.score > dealer.score)
		{
			cout << "Player wins!";
		}

		else if (player.score < dealer.score)
		{
			cout << "Dealer wins!";
		}

		else if (player.score == dealer.score)
		{
			cout << "Player  and dealer wins!";
		}
	}

}

//add check for deck size (if run out of cards)
//finish game, then will add game class