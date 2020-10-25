#pragma once
#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
    private:
        static const string namelist[4]; // 아이템 번호에 따른 이름들
        int itemNum;
        int itemType;
        int itemValue;
        int itemPrice;
        vector<int> itemattribute; // 아이템 속성들을 담는 벡터

    public:
        Item();
        Item(const int& itemNum, const int& itemType, const int& itemValue, const int& itemPrice);
        ~Item();

        int get_itemNum() const;
        string get_itemName(const int& number) const;
        vector<int> get_item() const;
        
        // 우선은 getset 같은 경우는 전체를 한번에 수정, 반환하는 형식으로 구현, 이후 특정 변수만 반환, 수정하고 싶다면
        //추가 예정


};