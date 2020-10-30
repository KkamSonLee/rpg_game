#include "Item.h"

const string Item::namelist[4] = { "woodsword", "longsword", "HPpotion", "MPpotion" }; // 번호에 따른 아이템 이름들
int itemlist[4][3]={{ 1, 200, 200 },{ 1, 400, 400 },{ 0, 100, 100 },{ 0, 100, 100 }};

Item::Item()
{

    /*
    itemlist.push_back(itemlist1);
    itemlist.push_back(itemlist2);
    itemlist.push_back(itemlist3);
    itemlist.push_back(itemlist4);*/
}

Item::~Item() {}

int Item::get_itemNum() const
{
    return this->itemNum;
}


int* Item::get_item(int i_num)
{
    //  return this->itemattribute;
    return *(itemlist+(i_num-1));
}

string Item::get_itemName(const int& number) const 
{
    if (number > 4) {
        return "유효하지않은 아이템입니다.";
    }
    return this->namelist[number - 1];
}

