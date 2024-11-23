#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "Header.h"
using namespace std;

void Display_Monsters(vector <Monster>& monsters)
{
	cout << endl << "Monsters" << endl << "___________________" << endl << endl;
	
	for (int i = 0; i < monsters.size(); i++)
	{
		cout << i << ") "
			<< "Name: " << monsters[i].name << "          "
			<< "Health: " << monsters[i].health << "          "
			<< "Attack Type: " << monsters[i].attackType << "          "
			<< "Attack Strength: " << monsters[i].attackStrength << "          "
			<< "Status: " << monsters[i].status << "          "
			<< endl;
	}
}

void Display_Player(Player player)
{
	cout << endl << "Player" << endl << "___________________" << endl << endl;
	cout << "Health: " << player.health << "          "
		<< "Status: " << player.status << "          "
		<< endl << endl;
}