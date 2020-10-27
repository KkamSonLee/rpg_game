#pragma once
#include<iostream>
#include <string>
#include <vector>

using namespace std;

class Item {
private:
    static const string namelist[4]; // 아이템 번호에 따른 이름들
    vector<vector<int>> itemlist;
    //vector<int> itemattribute; // 아이템 속성이 담긴 벡터
    vector<int> itemlist1; // 그에 따른 아이템 속성들
    vector<int> itemlist2;
    vector<int> itemlist3;
    vector<int> itemlist4;
    int itemNum;

public:
    Item();
    ~Item();
    int get_itemNum() const;
    vector<int> get_item(int i_num) const;
    string get_itemName(const int& number) const;
    // 우선은 getset 같은 경우는 전체를 한번에 수정, 반환하는 형식으로 구현, 이후 특정 변수만 반환, 수정하고 싶다면
    //추가 예정


};

