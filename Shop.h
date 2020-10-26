//
// Created by ASUS on 2020-10-21.
//
#include <iostream>
#include "Inventory.h"
#include "Character.h"
using namespace std;

class Shop {
private:
    vector<int> selllShop;
    string choice;
    Character myCharacter;
    Inventory myInventory;
public:
    Shop(Character myCharacter, Inventory myInventory);
    void showShop();
    bool buy(int index, int buyCount);
    bool sell(int sellItemNumber);
};