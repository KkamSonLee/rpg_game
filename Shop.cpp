//
// Created by ASUS on 2020-10-21.
//

#include "Shop.h"

int sellList[4] = {1, 2, 3, 4};
vector<int> temp;

Shop::Shop(Character &myCharacter, Inventory &myInventory) : myInventory(myInventory), myCharacter(myCharacter) {
    int index, buyCount;
    warningMessage wm;
    bool loop = true;
    while (loop) {
        showShop();
        cout << "\n어떤 동작을 하시겠습니까? buy [num] sell [num]\nnow money : " << myCharacter.get_money() << "\n";
        cin.clear();
        cin >> choice;
        if (choice == "buy") {
            cout << "어떤 항목을 구매하겠습니까? \n";
            cin.clear();
            cin >> index;
            cout << "원하는 수량을 입력하세요 : ";
            cin.clear();
            cin >> buyCount;
            loop = buy(index, buyCount);
            cout << "now money : " << myCharacter.get_money() << "\n";
        } else if (choice == "sell") {
            cout << "어떤 항목을 판매하겠습니까? \n";
            cin.clear();
            cin >> index;
            loop = sell(index);
            cout << "now money : " << myCharacter.get_money() << "\n";
        } else if (choice == "return") {
            cin.ignore();
            loop = false;
        } else {
            wm.printWarning(1, "not valid");
        }
    }
}

void Shop::showShop() {
    temp = myInventory.getSlot();
    cout << "------sell List------\n";
    for (int j = 1; j <= (sizeof(sellList) / sizeof(int)); j++) {
        cout << j << ". " << myInventory.item.get_itemName(sellList[j - 1]) << "   "
             << myInventory.item.get_item(sellList[j - 1])[2] << "$"
             << "\n";
    }
    cout << "\n\n";
    cout << "------my Inventory------\n";
    myInventory.printInvList();
}

bool Shop::buy(int index, int buyCount) {
    warningMessage wm;
    if (index > (sizeof(sellList) / sizeof(int)) || index <= 0) {
        wm.printWarning(1, "index error");
        cin.ignore();
        return false;
    } else if (myCharacter.get_money() < (myInventory.item.get_item(sellList[index - 1])[2]) * buyCount) {
        wm.printWarning(1, "not enough money");
        cin.ignore();
        return false;
    } else {
        if (myInventory.getSlot().size() + buyCount > 10) {
            wm.printWarning(1, "slot is size exceed");
            cin.ignore();
            return false;
        } else {
            for (int i = 1; i <= buyCount; i++) {
                if (myInventory.getSlot().empty()) {
                    if (Item().get_item(index)[0] == 1) {
                        myCharacter.set_atk(myCharacter.get_atk() + Item().get_item(index)[1]);
                    }
                }
                myInventory.addSlot(index);
                myInventory.changeMoney(-(myInventory.item.get_item(sellList[index - 1])[2]));
            }
            return true;
        }
    }
}


bool Shop::sell(int sellItemNumber) {
    warningMessage wm;
    if (sellItemNumber > myInventory.getSlot().size() || sellItemNumber < 0) {
        wm.printWarning(1, "index error");
        cin.ignore();
        return false;
    } else if (sellItemNumber <= myInventory.getSlot().size() && sellItemNumber > 0) {
        myInventory.changeMoney(myInventory.item.get_item(myInventory.getSlot().at(sellItemNumber - 1))[2]);
        if (sellItemNumber == 1 && myInventory.getSlot().size() == 1) {
            if (Item().get_item(myInventory.getSlot().at(0))[0] == 1) {
                myCharacter.set_atk(myCharacter.get_atk() - Item().get_item(myInventory.getSlot().at(0))[1]);
            }
            myInventory.slotClear();
        } else {
            if (sellItemNumber == 1) {
                if (Item().get_item(myInventory.getSlot().at(0))[0] == 1) {
                    myCharacter.set_atk(myCharacter.get_atk() - Item().get_item(myInventory.getSlot().at(0))[1]);
                }
            }
            myInventory.deleteSlot(sellItemNumber);
            if (Item().get_item(myInventory.getSlot().at(0))[0] == 1) {
                myCharacter.set_atk(myCharacter.get_atk() + Item().get_item(myInventory.getSlot().at(0))[1]);
            }
        }
    } else {
        wm.printWarning(1, "not valid");
    }
    return true;
}