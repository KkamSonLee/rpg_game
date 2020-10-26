//
// Created by ASUS on 2020-10-25.
//

#include <vector>
#include <iostream>
#include "item.h"
#include "Character.h"
using namespace std;
class Inventory {

public:
    Inventory(Character subCharacter);
    Character character;
    void openInv();
    void closeInv();
    vector<int> getSlot();
    void deleteSlot(int itemLocation);
    void addSlot(int itemNum);
    void changeMoney(int money);
    void changeequip(vector<int> item);
    void usepothion(int itemValue, int itemNum);
private:
    int money;
    vector <int> slot;
};