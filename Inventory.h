//
// Created by ASUS on 2020-10-25.
//
#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
#include "Character.h"
using namespace std;
class Inventory {
private:
    int money;
    vector <int> slot;
public:
    Inventory(Character subCharacter);   //character�� �κ��丮�� ������ �ֽ��ϴ�.
    ~Inventory();
    Character character;
    void openInv();   //�κ��丮 ������ ����ϴ� �����Դϴ�.
    void closeInv();   //���� �߰����� ������ ������ close�� �ȴٴ� ��ø� ���ִ� �Լ��Դϴ�.
    vector<int> getSlot();   //vector<int>������ slot�� ��ȯ���ݴϴ�.
    void deleteSlot(int itemLocation);   //�ش� Location�� �������� �������ݴϴ�.
    void addSlot(int itemNum);    // Slot�ڿ� ���� �߰�
    void changeMoney(int money);   //Money�� + - �� ���� ó��
    void changeequip(int nowAtk, vector<int> item);    // ���ü
    void usepotion(int itemValue, int itemNum);     // ���� ���
    int getMoney();  // get_Money
    Item item;    //Slot�� �ִ� int������ �������� �Ӽ��� ����ϱ� ���� ����

};
#endif