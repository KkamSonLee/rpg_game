#include "Item.h"

Item::Item(const int& itemNum, const int& itemType, const int& itemValue, const int& itemPrice)
    :itemNum(0),itemType(0),itemValue(1),itemPrice(0)
{
    itemattribute.push_back(this->itemNum);
    itemattribute.push_back(this->itemPrice);
    itemattribute.push_back(this->itemType);
    itemattribute.push_back(this->itemValue);

}

Item::~Item()
{
    
}

int Item::get_itemNum() const
{
    return this->itemNum;
}

vector<int> Item::get_item()
{

    return this->itemattribute;

}


