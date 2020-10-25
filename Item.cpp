#include "Item.h"

const string Item::namelist[4] = {"목검", "장검", "HP포션", "MP포션"}; // 번호에 따른 아이템 이름들
vector<vector<int>> itemlist;
vector<int> itemlist1{1, 200, 200};
vector<int> itemlist2{1, 400, 400};
vector<int> itemlist3{0, 100, 100};
vector<int> itemlist4{0, 100, 100};
Item::Item() {
    itemlist.push_back(itemlist1);
    itemlist.push_back(itemlist2);
    itemlist.push_back(itemlist3);
    itemlist.push_back(itemlist4);
}
Item::~Item() {}
int Item::get_itemNum() const {
    return this->itemNum;
}
vector<int> Item::get_item(int i_num) const {
//  return this->itemattribute;
    return this->itemlist[i_num - 1];
}

string Item::get_itemName(const int &number) const {
    if (number > 4) {
        return "유효하지않은 아이템입니다.";
    }
    return this->namelist[number - 1];
}