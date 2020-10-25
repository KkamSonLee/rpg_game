//
// Created by ASUS on 2020-10-25.
//

#include <vector>

#ifndef RPG_GAME_INVENTORY_H
#define RPG_GAME_INVENTORY_H
using namespace std;
class Inventory {
private:
    int money;
    vector <int> slot;
public:
    Inventory(int money, int slot[]){
        this->money = money;
        for(int i=0; i<sizeof(slot); i++){
            this->slot.push_back(slot[i]);
        }
    }
    void openInv(){

    }
    void closeInv(){

    }

};

#endif //RPG_GAME_INVENTORY_H
