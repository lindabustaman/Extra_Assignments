#pragma once
using namespace std;

struct Monster
{
	string name = "";
	int health = 100;
	string attackType = "";
	int attackStrength = 5;
	string status = "alive";
};

struct Player
{
	string name = "";
	int health = 100;
	string strongAttackName = "strong attack";
	int strongAttackStrength = 50;
	string lightAttackName = "light attack";
	int lightAttackStrength = 10;
	string status = "alive";
};

enum first_menu_option
{
	createMonster,
	editMonster,
	startGame,
	exitGame
};

enum second_menu_option
{
	strongAttackMonster,
	lightAttackMonster,
	displayHealth,
	exitGame2
};

int firstMenu(Player& player, vector <Monster>& monsters);
int secondMenu(Player& player, vector <Monster>& monsters, int& defeatedMonsters, int& turnCounter);
void Display_Monsters(vector <Monster>& monsters);
void Display_Player(Player player);
void playerAttack(Player& player, vector <Monster>& monsters, int playerChoice2);
void monsterAttack(Player& player, vector <Monster>& monsters);
void checkStatus(Player& player);
void checkStatus(vector <Monster>& monsters, int& defeatedMonsters);