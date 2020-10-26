//
// Created by ASUS on 2020-10-25.
//
#include "Inventory.h"


Inventory::Inventory(Character subCharacter) : character(subCharacter) {
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
            if (choice == 1) {
                cout << "already use equip\n";
            }
            if (item.get_item(slot[choice]).at(0) == 1) {//itemType
                changeequip(item.get_item(slot[0]).at(1), item.get_item(choice));
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

void Inventory::changeequip(int nowAtk, vector<int> item) {
    character.set_atk((character.get_atk() - nowAtk) + item.at(1));
}

void Inventory::usepotion(int itemValue, int itemNum) {
    if (itemNum == 3) {
        if (character.get_stat().get_mhp() > character.get_nhp() + itemValue) {
            character.set_nhp(character.get_stat().get_mhp());
        } else {
            character.set_nhp(character.get_nhp() + itemValue);
        }
    } else if (itemNum == 4) {
        if (character.get_stat().get_mmp() > character.get_nmp() + itemValue) {
            character.set_nmp(character.get_stat().get_mhp());
        } else {
            character.setnmp(character.get_nmp() + itemValue);
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

vector<int> Inventory::getSlot() {
    return slot;
}

void Inventory::addSlot(int itemNum) {
    slot.push_back(itemNum);
}

void Inventory::changeMoney(int money) {
    this->money += money;
}

int Inventory::getMoney() {
    return money;
}