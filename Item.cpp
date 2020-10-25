#include "Item.h"

const string Item::namelist[4] = {"목검", "장검", "HP포션", "MP포션"}; // 번호에 따른 아이템 이름들
vector<vector<int>> itemlist;
//itemarr[4][3] = {{1,100,300},{1,200,500},{0,100,100},{0,100,100}};
Item::Item()
        : itemNum(0), itemType(0), itemValue(1), itemPrice(0) {

}

Item::Item(const int &i_itemNum, const int &i_itemType, const int &i_itemValue, const int &i_itemPrice) {
    this->itemNum = i_itemNum;
    this->itemType = i_itemType;
    this->itemPrice = i_itemPrice;
    this->itemValue = i_itemValue;

    vector<int> itemattribute;
    itemlist[this->itemNum] = itemattribute;

    itemattribute.push_back(this->itemPrice);
    itemattribute.push_back(this->itemType);
    itemattribute.push_back(this->itemValue);
}

Item::~Item() {}

int Item::get_itemNum() const {
    return this->itemNum;
}

vector<int> Item::get_item(int i_num) const {


//    return this->itemattribute;
    return this->itemlist[i_num];

}

string Item::get_itemName(const int &number) const {
    if (number > 4) {
        return "유효하지않은 아이템입니다.";
    }
    return this->namelist[number - 1];
}