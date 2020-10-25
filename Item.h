#pragma once
#include<iostream>
#include <vector>

using namespace std;

class Item {
    private:
        int itemNum;
        int itemType;
        int itemValue;
        int itemPrice;
        vector<int> itemattribute;

    public:
        Item();
        Item(const int& itemNum, const int& itemType, const int& itemValue, const int& itemPrice);
        ~Item();

        int get_itemNum() const;
        vector<int> get_item();


};