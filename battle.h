#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Character.h"
#include "Inventory.h"
#include "Monster.h"
#include "Shop.h"

using namespace std;

class battle
{
public:
	int Battle(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num); //전투에 임하는 함수
	void show_Stats(Character& myCharacter, Monster& nowMonster); //스탯 보여주는 함수
	void save_character(Character& myCharacter, Inventory& myInventory); //캐릭터 정보를 저장하는 함수
	int attack_situation(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num); //attack 실행 시의 상황을 나타낸 함수
};

