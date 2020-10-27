//
// Created by ASUS on 2020-10-21.
//
#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include "Inventory.h"
#include "Character.h"
using namespace std;

class Shop {
private:
    string choice;  //buy, sell의 명령어를 받는 부분입니다.
    Inventory myInventory;
public:
    Shop(Character myCharacter, Inventory myInventory);
    void showShop();
    bool buy(int index, int buyCount);
    bool sell(int sellItemNumber);
};
#endif