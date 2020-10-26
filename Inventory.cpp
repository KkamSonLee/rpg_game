//
// Created by ASUS on 2020-10-25.
//
#include "Inventory.h"


Inventory::Inventory(Character subCharacter){
    this->character = subCharacter;
    money = 0;
}

void Inventory::openInv() {
    cout << "now Money : " << money << "$\n";
    int choice;

    while (1) {
        if (slot.empty() && money == 0) {
            cout << "inventory empty\n";
            closeInv();
            break;
        } else if (!slot.empty()) {
            int i = 1;
            cout << "0. return\n";
            for (vector<int>::iterator iter = slot.begin(); iter != slot.end(); iter++, i++) {
                cout << i << ". " << Item().get_itemName(*(iter)) << "\n";
            }
        }

        cout << "choice to use item\n";
        cin >> choice;
        Item item = Item();
        if (choice == 0) {
            closeInv();
            break;
        } else if (choice > 1) {
            if(choice == 1){
                cout << "already use equip\n";
                closeInv();
                break;
            }
            if (item.get_item(choice).at(1) == 1) {//itemType
                changeequip(item.get_item(choice));
            } else if (item.get_item(choice).at(1) == 0) {
                usepothion()
            }
        } else {
            continue;
        }
    }
}

void Inventory::changeequip(vector<int> item) {

}
void Inventory::usepothion(int itemValue, int itemNum) {

}

void Inventory::deleteSlot(int itemLocation) {
    vector<int>::iterator iter = slot.begin();
    iter += (itemLocation - 1);
    slot.erase(iter);
}

void Inventory::closeInv() {
    cout << "진행중이던 작업으로 돌아갑니다." << "\n";
}

vector<int> Inventory::getSlot() {
    return slot;
}

void Inventory::addSlot(int itemNum) {
    slot.push_back(itemNum);
}

void Inventory::changeMoney(int money) {
    this->money += money;
}