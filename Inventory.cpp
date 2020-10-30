#include "Inventory.h"

Inventory::Inventory(Character &subCharacter) : character(subCharacter) {
    this->money = character.get_money();
    item = Item();
}

Inventory::~Inventory() {}

void Inventory::printInvList() {
    int i = 1;
    if (!slot.empty()) {
        for (vector<int>::iterator iter = slot.begin(); iter != slot.end(); iter++, i++) {
            cout << i << ". " << Item().get_itemName(*(iter)) << "\n";
        }
    }
}

void Inventory::openInv() {
    money = character.get_money();
    cout << "now Money : " << money << "$\n";
    int choice;
    bool loop = true;
    while (loop) {
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
            cin.ignore();
            break;
        } else if (choice >= 1 && choice <= slot.size()) {
            int *tempvec = (item.get_item(slot.at(choice - 1)));
            cout << *(tempvec) << "\n";
            cout << *(tempvec + 1) << "\n";
            cout << *(tempvec + 2) << "\n";
            if (choice == 1) {
                cout << "already use equip\n";
            } else if (tempvec[0] == 1) {//itemType
                changeequip(item.get_item(slot.at(0))[1], choice);

            } else if (tempvec[0] == 0) {
                usepotion(item.get_item(slot.at(choice - 1))[1], slot.at(choice - 1));
                deleteSlot(choice);
            }
        }
    }
}

void Inventory::changeequip(int nowAtk, int choice) {
    character.set_atk((character.get_atk() - nowAtk) + (item.get_item(slot.at(choice - 1))[1]));
    int temp = slot.at(0);
    slot.at(0) = slot.at(choice - 1);
    slot.at(choice - 1) = temp;
}

void Inventory::usepotion(int itemValue, int itemNum) {
    if (itemNum == 3) {
        if (character.get_mhp() <= character.get_nhp() + itemValue) {
            character.set_nhp(character.get_mhp());
        } else {
            character.set_nhp(character.get_nhp() + itemValue);
        }
    } else if (itemNum == 4) {
        if (character.get_mmp() <= character.get_nmp() + itemValue) {
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
    slot.resize(slot.size()-1);
}

void Inventory::closeInv() {
    cout << "return to game.\n";
}

void Inventory::addSlot(int itemNum) {
    slot.push_back(itemNum);
}

void Inventory::addSlotArr(vector<int> itemArr) {
    slot.assign(itemArr.begin(), itemArr.end());
}

void Inventory::changeMoney(int moneyChange) {
    character.set_money(character.get_money() + moneyChange);
}

int Inventory::getMoney() {
    return character.get_money();
}

vector<int> Inventory::getSlot() {
    return slot;
}
void Inventory::slotClear() {
    slot.clear();
}
