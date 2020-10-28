#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "Inventory.h"

using namespace std;

class battle
{
public:
	int Battle(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num); //전투에 임하는 함수
	void show_Stats(Character& myCharacter, Monster& nowMonster); //스탯 보여주는 함수
};

