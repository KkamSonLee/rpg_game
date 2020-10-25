//
// Created by ASUS on 2020-10-25.
//

#include <vector>
#include <iostream>
using namespace std;
class Inventory {
private:
    int money;
    vector <int> slot;
public:
    Inventory();
    Inventory(int money, vector<int> slot);
    void openInv();
    void closeInv();

};

