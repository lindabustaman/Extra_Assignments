#pragma once
#include <string>
using namespace std;


struct Card
{
	string suit;
	string rank;
	int value;

	static string Suit[4];
	static string Rank[13];
	static int Value[13];
};

