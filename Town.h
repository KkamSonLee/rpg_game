#pragma once

#include <string>
#include "Item.h"
#include "Status.h"
#include <cctype>
#include "character_integrity_check.h"
#include "Map.h"
//#include "map_integrity_check.h"
#include "warningMessage.h"
#include "Character.h"
#include "Inventory.h"
#include "Shop.h"


using namespace std;

class Town {
private:
    Character &myCharacter;
    Inventory &myInventory;
public:
    int max_slot;
    vector<Map> admin;
    int cnt = 0;

    Town(Character &myCharacter, Inventory &myInventory, vector<Map> admin);

    ~Town();

    void choice();

    void help();

    void save(int);

    void quit();

    void inventory();

    bool move();

    void shop();

    void stat();

    bool is_digit(string);
};
