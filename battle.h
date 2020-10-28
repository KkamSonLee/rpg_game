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
	int Battle(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num); //������ ���ϴ� �Լ�
	void show_Stats(Character& myCharacter, Monster& nowMonster); //���� �����ִ� �Լ�
	void save_character(Character& myCharacter, Inventory& myInventory); //ĳ���� ������ �����ϴ� �Լ�
	int attack_situation(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num); //attack ���� ���� ��Ȳ�� ��Ÿ�� �Լ�
};