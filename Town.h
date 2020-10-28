#pragma once
#include <string>
#include "Item.h"
#include "Status.h"
#include "character_integrity_check.h"
#include "map_integrity_check.h"
#include "warningMessage.h"
#include "Character.h"


using namespace std;

class Town
{
private:
    Character& myCharacter;
public:
	int max_slot;
	Town();
	Town(Character& myCharacter);
	~Town();
	void choice();
	void help();
	void save(int);
	void quit();;
	void inventory();
	void move(string);
	void shop();
	void stat();
	bool is_digit(string);
};
