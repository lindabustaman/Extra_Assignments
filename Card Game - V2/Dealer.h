#pragma once
#include <iostream>
#include <vector>

#include "Participant.h"
using namespace std;

class Dealer : public Participant
{
public:
	int best_score = Score("Dealer");

	void AceValue();

};