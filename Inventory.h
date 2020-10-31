//
// Created by ASUS on 2020-10-25.
//
#pragma once
#include "item.h"
#include "Character.h"
#include "Inventory.h"
#include <vector>
#include <iostream>
#include "warningMessage.h"
using namespace std;
class Inventory {
private:
    int money;
    vector <int> slot;
    Character& character;
public:

    Inventory(Character& subCharacter);   //character는 인벤토리를 가지고 있습니다.
    ~Inventory();
    void openInv();
    void printInvList(); //인벤토리 내용을 출력하는 내용입니다.
    void closeInv();   //따로 추가적인 동작은 없지만 close가 된다는 명시를 해주는 함수입니다.
    vector<int> getSlot();   //vector<int>형식의 slot을 반환해줍니다.
    void deleteSlot(int itemLocation);   //해당 Location의 아이템을 삭제해줍니다.
    void addSlot(int itemNum);    // Slot뒤에 값을 추가
    void addSlotArr(vector<int> itemArr);
    void changeMoney(int money);   //Money의 + - 에 대한 처리
    void changeequip(int nowAtk, int choice);    // 장비교체
    void usepotion(int itemValue, int itemNum);     // 포션 사용
    int getMoney();  // get_Money
    void slotClear();
    Item item;    //Slot에 있는 int값으로 아이템의 속성을 사용하기 위해 정의

};
