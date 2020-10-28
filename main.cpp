#include "Status.h"
#include "Monster.h"
#include "Character.h"
#include "Item.h"
#include "Inventory.h"
#include "Shop.h"
#include <conio.h>

int main() {
    int num = 1;
    int hp = 3;
    int mp = 100;
    int money = 4000;
    vector<int> inven;
    inven.push_back(1);
    inven.push_back(2);
    inven.push_back(3);
    inven.push_back(4);
    Status st(hp, mp, hp, mp, num, num, num, num, money); //money ����
    Character ch(st);
    Monster mon(st, 1);
    Inventory inv(ch);
    inv.addSlotArr(inven);
    inv.openInv();

    Shop myshop(ch, inv);
    ch.show_stat();// ���� ���� ���

    ch.attack(mon, 10);
    cout << mon.get_nhp() << endl; //// hp = 3 , atk = 1 �̱⶧���� ������ �ѹ� �Ѵٸ� hp 2�� �Ǿ�� �� �� �Դϴ�.

    ch.attack(mon, 10);
    mon.attack(ch, 10);
    mon.attack(ch, 10);
    // ĳ���Ϳ� ������ status�� �Ȱ��� mp �Ҹ𷮵� 20�̱� ������ 
    //ĳ���Ϳ� ������ hp mp�� �ι� �������� �� 1 -37�� ���;� �մϴ�. 
    cout << mon.get_nhp() << "," << mon.get_nmp() << endl;
    cout << ch.get_nhp() << "," <<ch.get_nmp()<<endl;

    cout << mon.get_name(3) << endl; // �̸� ������ status�� ���� ������ Ŭ�������ο��� ���ϴ� ������� �������־����ϴ�.
    cout << mon.get_money() << endl;
    mon.set_money(2000);
    cout << mon.get_money() << endl;

    return 0;

}