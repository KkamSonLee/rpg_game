#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class battle
{
public:
	int Battle(Character& myCharacter, Inventory& myInventory, Monster& nowMonster, int map_num); //������ ���ϴ� �Լ�
	void show_Stats(Character& myCharacter, Monster& nowMonster); //���� �����ִ� �Լ�
};
