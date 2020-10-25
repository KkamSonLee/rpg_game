//
// Created by ASUS on 2020-10-25.
//

#include "Inventory.h"

class Iterator;

Inventory::Inventory() {}

Inventory::Inventory(int money, vector<int> slot)
    : money(money), slot(slot){
    openInv();
}
void Inventory::closeInv() {

}
void Inventory::openInv(){
    for(vector<int> :: iterator iter=slot.begin();iter!=slot.end(); iter++ ){
        cout << (*iter)<< ". " << Item.getItemToString(*(iter)) << "\n";
    }
    int choice;
    cin >> choice;
    switch (Item.getInstance) {

    }
}
