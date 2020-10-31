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

    Inventory(Character& subCharacter);   //character�� �κ��丮�� ������ �ֽ��ϴ�.
    ~Inventory();
    void openInv();
    void printInvList(); //�κ��丮 ������ ����ϴ� �����Դϴ�.
    void closeInv();   //���� �߰����� ������ ������ close�� �ȴٴ� ��ø� ���ִ� �Լ��Դϴ�.
    vector<int> getSlot();   //vector<int>������ slot�� ��ȯ���ݴϴ�.
    void deleteSlot(int itemLocation);   //�ش� Location�� �������� �������ݴϴ�.
    void addSlot(int itemNum);    // Slot�ڿ� ���� �߰�
    void addSlotArr(vector<int> itemArr);
    void changeMoney(int money);   //Money�� + - �� ���� ó��
    void changeequip(int nowAtk, int choice);    // ���ü
    void usepotion(int itemValue, int itemNum);     // ���� ���
    int getMoney();  // get_Money
    void slotClear();
    Item item;    //Slot�� �ִ� int������ �������� �Ӽ��� ����ϱ� ���� ����

};
