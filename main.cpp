#include "Status.h"
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include "Shop.h"
#include <conio.h>
//battle.cpp battle.h character_integrity_check.cpp character_integrity_check.h map_integrity_check.cpp map_integrity_check.h warningMessage.cpp warningMessage.h Town.cpp Town.h
int main() {
    int use_mp = 20;
    int num = 1;
    int hp = 3;
    int mp = 100;
    int money = 4000;
    vector<int> invList;
    invList.push_back(1);
    invList.push_back(2);
    invList.push_back(3);
    invList.push_back(4);
    Status st(hp, mp, hp, mp, num, num, num, num, money); //money ����
    Character ch(st);
    Monster mon(st, 1);
    Inventory inv(ch);
    inv.addSlotArr(invList);
    inv.openInv();
    ch.show_stat();// ���� ���� ���

    ch.attack(mon, mp);
    cout << mon.get_nhp() << endl; //// hp = 3 , atk = 1 �̱⶧���� ������ �ѹ� �Ѵٸ� hp 2�� �Ǿ�� �� �� �Դϴ�.

    ch.attack(mon, mp);
    mon.attack(ch, mp);
    mon.attack(ch, mp);
    // ĳ���Ϳ� ������ status�� �Ȱ��� mp �Ҹ𷮵� 20�̱� ������ 
    //ĳ���Ϳ� ������ hp mp�� �ι� �������� �� 1 -37�� ���;� �մϴ�. 
    cout << mon.get_nhp() << "," << mon.get_nmp() << endl;
    cout << ch.get_nhp() << "," <<ch.get_nmp()<<endl;

    cout << mon.get_name(3) << endl; // �̸� ������ status�� ���� ������ Ŭ�������ο��� ���ϴ� ������� �������־����ϴ�.
    cout << mon.get_money() << endl;
    mon.set_money(2000);
    cout << mon.get_money() << endl;

    Shop shop(ch, inv);
    return 0;

}