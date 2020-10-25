#include <iostream>
#include "Inventory.h"

using namespace std;

int main() {
    Inventory inv = Inventory();
    Item item = Item(1,2,1,300);
    inv.addMoney(100);
    inv.addItem(item);
    inv.openInv();
    return 0;
}
