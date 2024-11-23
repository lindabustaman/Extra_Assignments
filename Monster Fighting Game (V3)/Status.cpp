#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <Windows.h>
#include "Header.h"
using namespace std;

void checkStatus(Player& player)
{
	if (player.health <= 0)
	{
		player.status = "dead";
		cout << "You died! Game over." << endl << endl;
	}

}

void checkStatus(vector <Monster>& monsters, int& defeatedMonsters)
{
	for (int i = 0; i < monsters.size(); i++)
	{
		if ((monsters[i].health <= 0) && (monsters[i].status == "alive"))
		{
			monsters[i].status = "dead";
			cout << monsters[i].name << " died!" << endl << endl;
			defeatedMonsters--;
		}

	}

	if (defeatedMonsters == 0)
	{
		cout << "All monsters defeated! You win!" << endl << endl;
	}
}