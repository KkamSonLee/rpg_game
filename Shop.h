//
// Created by ASUS on 2020-10-21.
//
#pragma once
#include <iostream>
#include "Inventory.h"
#include "Character.h"
#include "Item.h"
using namespace std;

class Shop {
private:
    string choice;  //buy, sell의 명령어를 받는 부분입니다.
    Inventory& myInventory;
    Character& myCharacter;
public:
    Shop(Character& myCharacter, Inventory& myInventory);
    void showShop();
    bool buy(int index, int buyCount);
    bool sell(int sellItemNumber);
};