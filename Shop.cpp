//
// Created by ASUS on 2020-10-21.
//

#include "Shop.h"

int sellList[4] = {1, 2, 3, 4};
vector<int> temp;
Shop::Shop(Character& myCharacter, Inventory& myInventory):myInventory(myInventory), myCharacter(myCharacter){
    int index, sellCount;

    bool loop = true;
    while(loop) {
        showShop();
        cout << "\n어떤 동작을 하시겠습니까?\n";
        cin >> choice;
        if (choice == "buy") {
            cin >> index;
            cout << "원하는 수량을 입력하세요 : ";
            cin >> sellCount;
            loop = buy(index, sellCount);
            cout << "now money : " << myCharacter.get_money() << "\n";
        } else if (choice == "sell") {
            cin >> index;
            loop = sell(index);
            cout << "now money : " << myCharacter.get_money() << "\n";
        } else if (choice == "return") {
            loop = false;
        } else{
            loop = false;
        }
    }
}

void Shop::showShop() {
    temp = myInventory.getSlot();

    cout << "------sell List------\n";
    for (int j = 1; j <= (sizeof(sellList) / sizeof(int)); j++) {
        cout << j << ". " << myInventory.item.get_itemName(sellList[j - 1]) << "\n";
    }
    cout << "\n\n";
    cout << "------my Inventory------\n";
    myInventory.printInvList();
}

bool Shop::buy(int index, int buyCount) {
    warningMessage wm;
    if (index >= (sizeof(sellList) / sizeof(int)) || index < 0) {
                wm.printWarning(0, 1);
        return false;
    } else {
        if (myInventory.getSlot().size() + buyCount > 10) {
            wm.printWarning(3, 1);
            return false;
        } else {
            for (int i = 1; i <= buyCount; i++) {
                myInventory.addSlot(index);
                myInventory.changeMoney(-(myInventory.item.get_item(sellList[index])[2]));
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
        cout << "slot size : " << myInventory.getSlot().size() << "\n";
        myInventory.changeMoney(myInventory.item.get_item(myInventory.getSlot().at(sellItemNumber-1))[2]);
        if(sellItemNumber==1&&myInventory.getSlot().size()==1){
            myInventory.slotClear();
        }else{
            myInventory.deleteSlot(sellItemNumber);
        }

        return true;
    }
}