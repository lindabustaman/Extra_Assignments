#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string Suit[4] = {"Hearts", "Spades", "Clubs", "Diamonds"};
string Rank[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
int Value[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };

struct Card
{
	string suit;
	string rank;
	int value;
};

class Deck
{
public: 
	
	//Initialize deck
	void Init()
	{
		for (int i = 0; i < 13; i++)
		{
			for (int f = 0; f < 4; f++)
			{
				Card card = { Suit[f], Rank[i], Value[i] }; 
				deck.push_back(card);
			}
		}
	}

	static void displayCard(Card card)
	{
		cout << card.rank << " of " << card.suit << endl; 
	}


	//Deal card randomly by choosing random index from deck vector
	Card dealCard()  
	{
		srand(time(0));
		int g = rand() % deck.size();
		Card dealt = deck[g];
		deck.erase(deck.begin() + g);
		return dealt;
	}

private: 
	vector<Card> deck;

};

class Participants //don't use plural for class
{
public:

	void Stand()
	{
	}

	void AddCard(Deck& deck)
	{
		Card newCard = deck.dealCard();
		hand.push_back(newCard);
	}

	void displayHand(string display_type, string participant)
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

	int score = 0;
	int Score(string participant)
	{
		for (Card card : hand)
		{
			score += card.value;
		}
		return score;
	}

protected:
	vector<Card> hand;
};

class Player : public Participants
{
public: 

	string PlayerChoice() //static function
	{
		cout << "Hit (H) or Stand (S)?" << endl;
		cin >> player_choice;
		return player_choice;
	}

	int best_score = Score("Player");
	int score_noAces;
	vector<int> possible_scores;

	void AceValue()
	{
		int num_Ace = 0;
		for (Card card : hand)
		{
			if (card.rank == "Ace")
			{
				num_Ace++;
			}
		}

		//cout << "Number of Aces is: " << num_Ace << endl;
		//cout << "Player's base score: " << score << endl;

		score_noAces = score - num_Ace;

		for (int i = 0; i < (num_Ace + 1); i++)
		{
			int ace_Value = score_noAces + (num_Ace + 10 * i);
			//cout << "Possible Ace Value: " << ace_Value << endl;
			possible_scores.push_back(ace_Value);
		}

		for (int f : possible_scores)
		{
			//cout << "Possible Scores:" << endl << f << endl;
			if ((f <= 21) && (f > score))
			{
				best_score = f;
				cout << "Player's Score: " << best_score << endl << endl;
			}
			else
			{
				cout << "Player's Score: " << best_score << endl << endl;
			}
		}
		
		//cout << "Player's Score: " << best_score << endl << endl;
	}

private:
	string player_choice;
};

class Dealer : public Participants
{
public: 
	int best_score = Score("Dealer");
	void AceValue()
	{
		int num_Ace = 0;
		for (Card card : hand)
		{
			if (card.rank == "Ace")
			{
				num_Ace++;
			}
		}

		int score_noAces = score - num_Ace;
		vector<int> possible_scores;
		for (int i = 0; i < (num_Ace + 1); i++)
		{
			int ace_Value = score_noAces + (num_Ace + 10 * i);
			//cout << "Possible Ace Value: " << ace_Value << endl;
			possible_scores.push_back(ace_Value);
		}

		for (int f : possible_scores)
		{
			//cout << "Possible Scores:" << endl << f << endl;
			if ((f > 17) && (f <= 21))
			{
				best_score = f;
				cout << "Dealer's Score: " << best_score << endl << endl;
			}
		}
		//cout << "Dealer's Score: " << score << endl << endl;

	}

};

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