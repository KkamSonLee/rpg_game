//
// Created by ASUS on 2020-10-21.
//
#include <iostream>
#include "Inventory.h"
#include "Character.h"

#ifndef RPG_GAME_SHOP_H
#define RPG_GAME_SHOP_H
using namespace std;
struct Item {
    int itemNum;
    int itemType;
    int itemValue;
    int itemPrice;
};

//아이템 리스트를 통해 무슨 아이템인지 판별하여 String을 반환해주는 함수
//내가 할 것
//void addSlotList(int itemNum);

//캐릭터 Class
//void setMoney(int num)

//item Class
//String itemToString(Item)


//String[]화면에 출력해주는 함수.
//
class Shop {
private:
    Item *sellList;
    string choice;
public:
    Shop(Item *sellList, Character myCharacter, Inventory myInventory) {
        this->sellList = sellList;
        int index;
        this->myCharacter = myCharacter;
        showShop(myInventory);
        cout << "\n어떤 동작을 하시겠습니까?\n";
        cin >> choice >> index;
        if (choice.compare("buy")) {
            buy(index);
        } else if (choice.compare("sell")) {
            sell(index, 1);
        }
    }

    void showShop(Inventory inventory) {
    }


    bool buy(int index) {
        if (index >= sizeof(sellList) || index < 0) {
            WarningMessage.printWarning(3, "not valid index");
        } else {

            if (sellList[index] < myCharacter.money) {
                if (int slotIndex = myCharacter.isEmptySlot() >= 0) {
                    myCharacter.addSlotList(sellList[index].itemNum);
                    myCharacter.setMoney(myCharacter.getMoney() - sellList[index].itemPrice);
                }
            } else {
                WarningMessage.printWarning(3, "not enough money");
                return false;
            }
        }
        return true;
    }

    bool sell(int sellItemNumber, int sellCount) {

    }

};


#endif //RPG_GAME_SHOP_H
