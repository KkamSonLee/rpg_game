#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "Inventory.h"
#include "Monster.h"
#include "Shop.h"
#include "warningMessage.h"
#include "Status.h"

using namespace std;

class battle{
public:
	int Battle(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num, warningMessage& wMessage); 
	void show_Stats(Character& myCharacter, Monster& nowMonster); 
	void save_character(Character& myCharacter, Inventory& myInventory, warningMessage &wMessage); 
	int attack_situation(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num, warningMessage &wMessage); 
};