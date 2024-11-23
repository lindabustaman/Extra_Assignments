#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "Header.h"
using namespace std;

void playerAttack(Player& player, vector <Monster>& monsters, int playerSelection2)
{
	//cout << "choose light (0) or strong (1) attack" << endl << endl;
	int selectedMonster;

	//program crashes if player does not input correct value
	if (playerSelection2 == 0)
	{
		cout << "Choose monster: ";
		cin >> selectedMonster;
		cout << endl;
		
		if (selectedMonster > (monsters.size()-1))
		{
			cout << "You did not choose a valid option." << endl << endl;
		}
		else if (monsters[selectedMonster].status == "dead")
		{
			cout << monsters[selectedMonster].name << " is dead. You cannot attack it." << endl << endl;
		}
		else if ((monsters[selectedMonster].status == "alive") && (selectedMonster <= (monsters.size() - 1)))
		{
			monsters[selectedMonster].health -= player.strongAttackStrength;
			cout << "You attacked " << monsters[selectedMonster].name << " with " << player.strongAttackName << "!" << endl << endl;
		}
	
	}
	else if (playerSelection2 == 1)
	{
		cout << "Choose monster: ";
		cin >> selectedMonster;
		cout << endl;

		if (selectedMonster > (monsters.size() - 1))
		{
			cout << "You did not choose a valid option." << endl << endl;
		}
		else if (monsters[selectedMonster].status == "dead")
		{
			cout << monsters[selectedMonster].name << " is dead. You cannot attack it." << endl << endl;
		}
		else if ((monsters[selectedMonster].status == "alive") && (selectedMonster <= (monsters.size() - 1)))
		{
			monsters[selectedMonster].health -= player.lightAttackStrength;
			cout << "You attacked " << monsters[selectedMonster].name << " with " << player.lightAttackName << "!" << endl << endl;
		}
	}
	else
	{
		cout << "you did not choose a valid option" << endl;
	}

}

void monsterAttack(Player& player, vector <Monster>& monsters)
{
	for (int i = 0; i < monsters.size(); i++)
	{
		if (monsters[i].status == "alive")
		{
			player.health -= monsters[i].attackStrength;
			cout << monsters[i].name << " attacked you with " << monsters[i].attackType << "!" << endl << endl;
		}
	}
}

