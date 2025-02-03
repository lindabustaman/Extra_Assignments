#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Card.h"
#include "Player.h"
using namespace std;

string Player::PlayerChoice()
{
	cout << "Hit (H) or Stand (S)?" << endl;
	cin >> player_choice;
	return player_choice;
}

