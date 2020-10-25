//
// Created by ASUS on 2020-10-21.
//

#include "Shop.h"

Shop::Shop(){

}
/*Shop::Shop(Item *sellList, Character myCharacter, Inventory myInventory){
    this->sellList = sellList;
    int index;
    this->myCharacter = myCharacter;
    showShop(myInventory);
    cout << "\n어떤 동작을 하시겠습니까?\n";
    cin >> choice >> index;
    if (choice.compare("buy")) {
        buy(index);
    } else if (choice.compare("sell")) {
        sell(index, 1);
    }
}
 */
bool Shop::buy(int index) {
    /*if (index >= sizeof(sellList) || index < 0) {
        WarningMessage.printWarning(3, "not valid index");
    } else {

        if (sellList[index] < myCharacter.money) {
            if (int slotIndex = myCharacter.isEmptySlot() >= 0) {
                myCharacter.addSlotList(sellList[index].itemNum);
                myCharacter.setMoney(myCharacter.getMoney() - sellList[index].itemPrice);
            }
        } else {
            WarningMessage.printWarning(3, "not enough money");
            return false;
        }
    }*/
    return true;
}
bool Shop::sell(int sellItemNumber, int sellCount){

}