#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Card.h"
#include "Dealer.h"

using namespace std;

void Dealer::AceValue()
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

