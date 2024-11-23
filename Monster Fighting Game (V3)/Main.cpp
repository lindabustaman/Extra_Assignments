//Need help changing filename to "Monster Fighting Game (V3)", changing solution name manually on file explorer causes program to not load correctly

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "Header.h"
using namespace std;

vector <Monster> g_monsters;
Player g_player;
int g_defeatedMonstersCount = 0;

//counter for number of turns left before player can use strong attack again
int g_turnCounter = 0;

int main()
{	
	cout << "Menu" << endl << "___________________" << endl << endl << "0) Create Monster   1) Edit Monster   2) Start Game   3) Exit Game" << endl << endl;
	int playerSelection = firstMenu(g_player, g_monsters);

	//remove magic number 0 and 1
	while (playerSelection == 0 || playerSelection == 1)
	{
		playerSelection = firstMenu(g_player, g_monsters);
		g_defeatedMonstersCount++;
	}


	if (playerSelection != 3 && g_monsters.size() > 0) 
	{
		cout << endl << "Menu" << endl << "___________________" << endl << endl << "0) Strong Attack on Monster 1) Light Attack on Monster  2) Display Health 3) Exit Game" << endl << endl;
		int playerSelection2 = secondMenu(g_player, g_monsters, g_defeatedMonstersCount, g_turnCounter);

		while (playerSelection2 != 3 && g_player.status != "dead" && g_defeatedMonstersCount > 0)
		{
			playerSelection2 = secondMenu(g_player, g_monsters, g_defeatedMonstersCount, g_turnCounter);
			
		}
	}
	else if (playerSelection != 3 && g_monsters.size() == 0)
	{
		cout << endl << "Cannot start game without any monsters." << endl;
	}
	
	
}

