#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <Windows.h>
#include "Header.h"
using namespace std;

int firstMenu(Player& player, vector <Monster>& monsters)
{
	int playerChoice;

	cout << "Your move: ";
	cin >> playerChoice;

	switch (playerChoice)
	{
	case createMonster:
	{
		Monster monster;
		cout << "Enter name: ";
		cin >> monster.name;
		cout << "Enter Attack Type: ";
		cin >> monster.attackType;
		cout << "Enter Attack Strength: ";
		cin >> monster.attackStrength;
		monsters.push_back(monster);
		

		//std::move() = instead of copying data, moves data into vector address
		//std::move doesn't show up as a valid function even with #include <utility>


		Display_Monsters(monsters);

		break;
	}
	case editMonster:
	{
		if (monsters.empty())
		{
			cout << "No monsters to edit! Create some monsters" << endl;
		}
		else
		{
			cout << "Select which monster to edit" << endl;
			int monsterSelected;
			cin >> monsterSelected;
			cout << "Enter name" << endl;
			cin >> monsters[monsterSelected].name;
			cout << "Enter Attack Type" << endl;
			cin >> monsters[monsterSelected].attackType;
			cout << "Enter Attack Strength" << endl;
			cin >> monsters[monsterSelected].attackStrength;

			Display_Monsters(monsters);
		}
		
		break;
	}
	case startGame:
		break;
	case exitGame:
		break;
	default:
		break;
	}

	return playerChoice;
}

int secondMenu(Player& player, vector <Monster>& monsters, int& defeatedMonsters, int& turnCounter)
{

	int defeatedMonsterCount = 0;
	
	cout << "Your move: ";
	int playerChoice2;
	cin >> playerChoice2;

	switch (playerChoice2)
	{
	case strongAttackMonster:
		
		if (turnCounter == 0)
		{
			playerAttack(player, monsters, 0);
			turnCounter = 3;
		}
		else if (turnCounter > 0)
		{
			cout << "Sorry! " << turnCounter << " more turns until you can use strong attack" << endl;
			turnCounter--;
		}
		
		checkStatus(monsters, defeatedMonsters);
		monsterAttack(player, monsters);

		checkStatus(player);
		
		break;
	case lightAttackMonster:
		playerAttack(player, monsters, 1);

		checkStatus(monsters, defeatedMonsters);
		monsterAttack(player, monsters);

		checkStatus(player);
		

		if (turnCounter > 0)
		{
			turnCounter--;
		}

		break;
	case displayHealth:
		Display_Player(player);
		Display_Monsters(monsters);
		break;
	case exitGame2:
		break;
	default:
		break;
	}

	return playerChoice2;
}