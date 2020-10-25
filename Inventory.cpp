//
// Created by ASUS on 2020-10-25.
//

#include "Inventory.h"


Inventory::Inventory() : money(0) {
}

void Inventory::addItem(Item item) {
    if (slot.size() >= 10) {
        //WarningMassage.printWarning("인벤토리가 가득찼습니다.");
    } else {
        slot.push_back(item.get_itemNum());
    }
}

void Inventory::addMoney(int money) {
    this->money += money;
}

bool Inventory::closeInv() {
    return true;
}

void Inventory::openInv() {
    cout << "현재 자금 : " << money << "메소\n";
    for (vector<int>::iterator iter = slot.begin(); iter != slot.end(); iter++) {
        cout << (*iter);
        //<< ". " << Item.getItemToString(*(iter)) << "\n";
    }

}
