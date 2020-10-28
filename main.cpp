#include "Status.h"
#include "Monster.h"
#include "Character.h"
#include <conio.h>

int main() {
    int num = 1;
    int hp = 3;
    int mp = 100;
    int money = 4000;
    Status st(hp, mp, hp, mp, num, num, num, num, money); //money 포함
    Character ch(st);
    Monster mon(st, 1);
    ch.show_stat();// 스탯 정보 출력

    ch.attack(mon, 10);
    cout << mon.get_nhp() << endl; //// hp = 3 , atk = 1 이기때문에 공격을 한번 한다면 hp 2가 되어야 할 것 입니다.

    ch.attack(mon, 10);
    mon.attack(ch, 10);
    mon.attack(ch, 10);
    // 캐릭터와 몬스터의 status가 똑같고 mp 소모량도 20이기 때문에 
    //캐릭터와 몬스터의 hp mp는 두번 공격했을 때 1 -37이 나와야 합니다. 
    cout << mon.get_nhp() << "," << mon.get_nmp() << endl;
    cout << ch.get_nhp() << "," <<ch.get_nmp()<<endl;

    cout << mon.get_name(3) << endl; // 이름 정보가 status에 없기 때문에 클래스내부에서 정하는 방식으로 설정해주었습니다.
    cout << mon.get_money() << endl;
    mon.set_money(2000);
    cout << mon.get_money() << endl;

    return 0;

}