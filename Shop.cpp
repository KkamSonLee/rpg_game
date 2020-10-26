//
// Created by ASUS on 2020-10-21.
//

#include "Shop.h"

int sellList[4] = {1, 2, 3, 4};

Shop::Shop(Character myCharacter, Inventory myInventory) :
        myCharacter(myCharacter), myInventory(myCharacter) {
    int index, sellCount;
    showShop();
    bool loop = true;
    while(loop) {
        cout << "\n어떤 동작을 하시겠습니까?\n";
        cin >> choice;
        cin >> index;
        if (choice == "buy") {
            cout << "원하는 수량을 입력하세요 : ";
            cin >> sellCount;
            loop = buy(index, sellCount);
        } else if (choice == "sell") {
            loop = sell(index);
        }else{
            loop = false;
        }
    }
}

void Shop::showShop() {
    vector<int> temp = myInventory.getSlot();
    cout << "------sell List------\n";
    for (int j = 1; j <= (sizeof(sellList) / sizeof(int)); j++) {
        cout << j << ". " << myInventory.item.get_itemName(sellList[j - 1]) << "\n";
    }
    cout << "\n\n";
    cout << "------my Inventory------\n";
    int i = 1;
    for (vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++, i++) {
        cout << i << ". " << myInventory.item.get_itemName(*(iter)) << "\n";
    }
}

bool Shop::buy(int index, int buyCount) {
    if (index >= (sizeof(sellList) / sizeof(int)) || index < 0) {
        //WarningMessage.printWarning(3, "not valid index");
        return false;
    } else {
        if (myInventory.getSlot().size() + buyCount > 10) {
            //WarningMessage.printWarning(3, "not valid count");
            return false;
        } else {
            for (int i = 1; i <= buyCount; i++) {
                myInventory.addSlot(index);
            }
            return true;
        }
    }
}

bool Shop::sell(int sellItemNumber) {
    if (sellItemNumber > myInventory.getSlot().size() || sellItemNumber < 0) {
        cout << "not vaild\n";
        return false;
    } else {
        myInventory.changeMoney(myInventory.item.get_item(myInventory.getSlot().at(sellItemNumber)).at(2));
        myInventory.deleteSlot(sellItemNumber);
        return true;
    }
}