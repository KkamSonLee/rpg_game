//
// Created by ASUS on 2020-10-25.
//

#include "Inventory.h"

Inventory(int money, int slot[]){
    this->money = money;
    for(int i=0; i<sizeof(slot); i++){
        this->slot.push_back(slot[i]);
    }
}