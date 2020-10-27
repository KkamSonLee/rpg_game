#include "Inventory.h"

Inventory::Inventory(Character &subCharacter) : character(subCharacter) {
    this->money = 0;
    openInv();
}

Inventory::~Inventory() {}

void Inventory::printInvList() {
    int i = 1;
    for (vector<int>::iterator iter = slot.begin(); iter != slot.end(); iter++, i++) {
        cout << i << ". " << Item().get_itemName(*(iter)) << "\n";
    }
}

void Inventory::openInv() {
    cout << "now Money : " << money << "$\n";
    int choice;
    bool loop = true;
    while (loop) {
        item = Item();
        if (slot.empty() && money == 0) {
            cout << "inventory empty\n";
            closeInv();
            break;
        } else if (!slot.empty()) {
            cout << "0. return\n";
            printInvList();
        }
        cout << "choice to use item\n";
        cin >> choice;
        if (choice == 0) {
            closeInv();
            break;
        } else if (choice >= 1 && choice <= slot.size()) {
            if (choice == 1) {
                cout << "already use equip\n";
            }
            if (item.get_item(slot[choice]).at(0) == 1) {//itemType
                changeequip(item.get_item(slot[0]).at(1), choice);
                int temp = slot.at(0);
                slot.at(0) = slot.at(choice);
                slot.at(choice) = temp;
            } else if (item.get_item(slot[choice]).at(0) == 0) {
                usepotion(item.get_item(slot[choice]).at(1), slot[choice]);
                deleteSlot(choice);
            }
        } else {
            continue;
        }
    }
}

void Inventory::changeequip(int nowAtk, int choice) {
    character.set_atk((character.get_atk() - nowAtk) + item.get_item(slot[choice]).at(1));
}

void Inventory::usepotion(int itemValue, int itemNum) {
    if (itemNum == 3) {
        if (character.get_mhp() > character.get_nhp() + itemValue) {
            character.set_nhp(character.get_mhp());
        } else {
            character.set_nhp(character.get_nhp() + itemValue);
        }
    } else if (itemNum == 4) {
        if (character.get_mmp() > character.get_nmp() + itemValue) {
            character.set_nmp(character.get_mmp());
        } else {
            character.set_nmp(character.get_nmp() + itemValue);
        }
    }
}

void Inventory::deleteSlot(int itemLocation) {
    vector<int>::iterator iter = slot.begin();
    iter += (itemLocation - 1);
    slot.erase(iter);
}

void Inventory::closeInv() {
    cout << "return to game.\n" << "\n";
}


void Inventory::addSlot(int itemNum) {
    slot.push_back(itemNum);
}

void Inventory::addSlotArr(vector<int> itemArr) {
    slot.assign(itemArr.begin(), itemArr.end());
}

void Inventory::changeMoney(int money) {
    this->money += money;
}

int Inventory::getMoney() {
    return money;
}
vector<int> Inventory::getSlot() {
    return slot;
}
