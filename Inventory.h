//
// Created by ASUS on 2020-10-25.
//

#include <vector>
#include <iostream>
#include "item.h"

using namespace std;
class Inventory {
public:
    Inventory();
    void openInv();
    bool closeInv();
    void addItem(Item item);
    void addMoney(int money);

private:
    int money;
    vector <int> slot;
};