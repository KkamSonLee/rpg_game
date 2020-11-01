#include "Inventory.h"

Inventory::Inventory(Character &subCharacter) : character(subCharacter) {
    this->money = character.get_money();
    item = Item();
}

Inventory::~Inventory() {}

void Inventory::printInvList() {
    int i = 1;
    if (!slot.empty()) {
        for (vector<int>::iterator iter = slot.begin(); iter != slot.end(); iter++) {
            cout << i++ << ". " << Item().get_itemName(*(iter)) << "\n";
        }
    }
}

void Inventory::openInv() {
    warningMessage wm;
    money = character.get_money();
    cout << "now Money : " << money << "$\n";
    int choice;
    bool loop = true;
    while (loop) {
        if (slot.empty() && money == 0) {
            wm.printWarning(1, "inventory empty");
            closeInv();
            break;
        }
        cout << "0. return\n";
        printInvList();
        cout << "choice to use item\n";
        cin.clear();
        cin >> choice;
        if (choice == 0) {
            closeInv();
            break;
        } else if (choice >= 1 && choice <= slot.size()) {
            int *tempvec = (item.get_item(slot.at(choice - 1)));
            if (tempvec[0] == 1) {//itemType
                if (item.get_item(slot.at(0))[0] == 1) {
                    character.set_atk((character.get_atk() - item.get_item(slot.at(0))[1]) + (tempvec[1]));
                } else {
                    character.set_atk((character.get_atk() + tempvec[1]));
                }
                changeequip(choice);
            } else if (tempvec[0] == 0) {
                usepotion(item.get_item(slot.at(choice - 1))[1], slot.at(choice - 1));
                deleteSlot(choice);
                if (choice == 1 && Item().get_item(slot.at(0))[0] == 1) {
                    character.set_atk(character.get_atk() + Item().get_item(slot.at(0))[1]);
                }
            }
        } else {
            wm.printWarning(1, "this slot is empty");
        }
    }
}

void Inventory::changeequip(int choice) {
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
}

void Inventory::closeInv() {
    cout << "return to game.\n";
    cin.clear();
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
    if (slot.empty()) {
        vector<int> s;
        return s;
    } else {
        return slot;

    }
}

void Inventory::slotClear() {
    slot.clear();
}
