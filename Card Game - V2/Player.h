#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "Participant.h"
using namespace std;

class Player : public Participant
{
public:

	string PlayerChoice();

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
