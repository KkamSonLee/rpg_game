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
    Status st(hp, mp, hp, mp, num, num, num, num, money); //money 포함
    Character ch(st);
    Monster mon(st, 1);
    Inventory inv(ch);
    inv.addSlotArr(invList);
    inv.openInv();
    ch.show_stat();// 스탯 정보 출력

    ch.attack(mon, mp);
    cout << mon.get_nhp() << endl; //// hp = 3 , atk = 1 이기때문에 공격을 한번 한다면 hp 2가 되어야 할 것 입니다.

    ch.attack(mon, mp);
    mon.attack(ch, mp);
    mon.attack(ch, mp);
    // 캐릭터와 몬스터의 status가 똑같고 mp 소모량도 20이기 때문에 
    //캐릭터와 몬스터의 hp mp는 두번 공격했을 때 1 -37이 나와야 합니다. 
    cout << mon.get_nhp() << "," << mon.get_nmp() << endl;
    cout << ch.get_nhp() << "," <<ch.get_nmp()<<endl;

    cout << mon.get_name(3) << endl; // 이름 정보가 status에 없기 때문에 클래스내부에서 정하는 방식으로 설정해주었습니다.
    cout << mon.get_money() << endl;
    mon.set_money(2000);
    cout << mon.get_money() << endl;

    Shop shop(ch, inv);
    return 0;

}