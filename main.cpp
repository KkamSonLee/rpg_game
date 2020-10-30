#include "Status.h"
#include "Character.h"
#include "Inventory.h"
#include "Monster.h"
#include "Town.h"
//#include "character_integrity_check.h"
#include "Shop.h"
#include <sstream>
#include <string>
#include <cstring>


Status stat;
void load(int inum);

//battle.cpp battle.h warningMessage.cpp warningMessage.h Town.cpp Town.h character_integrity_check.cpp character_integrity_check.h map_integrity_check.cpp map_integrity_check.h
//character_integrity_check charcheck;

int main() {
    int select = 1;

    //Town mytown(ch);
    int use_mp = 20;
    int num = 100;
    int atkc = 10;
    int atkb = 10;
    int hp = 100;
    int mp = 100;
    int money = 4000;
    vector<int> invList;
    invList.push_back(1);
    invList.push_back(2);
    invList.push_back(3);
    invList.push_back(4);
    Status charstat(mp, mp, mp, mp, atkc, mp, hp, mp, money);
    Status monstat(num, num, num, num, atkb, num, num, num, money); //money ํฌํจ
    Monster mon(monstat, 1);
    load(1);
    Character ch(stat);
    Inventory inventory(ch);
    inventory.addSlot(1);
    inventory.addSlot(2);
    inventory.addSlot(3);
    inventory.addSlot(4);
<<<<<<< HEAD
    Town myTown(ch, inventory);

    ch.show_stat();// ฝบลศ มคบธ รโทย
=======
    ch.show_stat();// ์คํฏ ์ ๋ณด ์ถ๋ ฅ
>>>>>>> 3e1624f49232b8b508a0b849e0b9db38056204c4

    //ch.attack(mon, mp);
    cout << mon.get_nhp() << endl; //// hp = 3 , atk = 1 ์ด๊ธฐ๋๋ฌธ์ ๊ณต๊ฒฉ์ ํ๋ฒ ํ๋ค๋ฉด hp 2๊ฐ ๋์ด์ผ ํ  ๊ฒ ์๋๋ค.

    ch.attack(mon, use_mp);
    mon.attack(ch, use_mp);
    mon.attack(ch, use_mp);
    // ์บ๋ฆญํฐ์ ๋ชฌ์คํฐ์ status๊ฐ ๋๊ฐ๊ณ  mp ์๋ชจ๋๋ 20์ด๊ธฐ ๋๋ฌธ์
    //์บ๋ฆญํฐ์ ๋ชฌ์คํฐ์ hp mp๋ ๋๋ฒ ๊ณต๊ฒฉํ์ ๋ 1 -37์ด ๋์์ผ ํฉ๋๋ค. 
    cout << mon.get_nhp() << "," << mon.get_nmp() << endl;
    cout << ch.get_nhp() << "," << ch.get_nmp() << endl;

    cout << mon.get_name(1) << endl; // ์ด๋ฆ ์ ๋ณด๊ฐ status์ ์๊ธฐ ๋๋ฌธ์ ํด๋์ค๋ด๋ถ์์ ์ ํ๋ ๋ฐฉ์์ผ๋ก ์ค์ ํด์ฃผ์์ต๋๋ค.
    cout << "char : " << ch.get_money() << endl;
    ch.set_money(2000);
    cout << "char atk: " << ch.get_atk() << endl;
    Shop shop(ch, inventory);
    cout << "char : " << ch.get_money() << endl;
    inventory.openInv();
    cout << "char atk: " << ch.get_atk() << endl;


    //Shop shop(ch, inv);
    return 0;

}

void load(int inum) {
    string numstr = to_string(inum);
    string str = "character" + numstr;
    stringstream ss;
    ss << str << ".txt";
    string filename = ss.str();
    char charfilename[20];
    strcpy(charfilename, filename.c_str());
    int level;
    int exp;
    int mhp;
    int mmp;
    int nhp;
    int nmp;
    int atk;
    int location;
    int money;
    //charcheck.load_set(filename);
    ifstream file(charfilename);
    if (!file.is_open()) {
        string basicstat = "1\t0\t100\t50\t100\t50\t10\t0\t0";
        ofstream newfile(charfilename);
        if (newfile.is_open()) {
            newfile << basicstat;
            newfile.close();
        }
        level = 1;
        exp = 0;
        mhp = 100;
        mmp = 50;
        nhp = 100;
        nmp = 50;
        atk = 10;
        location = 0;
        money = 0;

        stat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
    } else {
        char buffer[100];
        char *value;
        while (!file.eof()) {
            file.getline(buffer, 100);

            char *ptr = strtok(buffer, "\t");
            cout << ptr << endl;
            level = atoi(ptr);
            cout << level << "<- level \n";
            ptr = strtok(NULL, "\t");
            exp = atoi(ptr);
            cout << exp << "<- exp \n";
            ptr = strtok(NULL, "\t");
            mhp = atoi(ptr);
            cout << mhp << "<- mhp \n";
            ptr = strtok(NULL, "\t");
            mmp = atoi(ptr);
            cout << mmp << "<- mmp \n";
            ptr = strtok(NULL, "\t");
            nhp = atoi(ptr);
            ptr = strtok(NULL, "\t");
            nmp = atoi(ptr);
            ptr = strtok(NULL, "\t");
            atk = atoi(ptr);
            ptr = strtok(NULL, "\t");
            location = atoi(ptr);
            ptr = strtok(NULL, "\t");
            money = atoi(ptr);
            
            /*ptr = strtok(NULL, "\t");
            while (ptr != NULL) {
                myinventory.addSlot(atoi(ptr));
                ptr = strtok(NULL, "\t");
            }*/

            stat.set_status(mhp, mmp, nhp, nmp, atk, exp, level, location, money);
            file.close();
        }
    }
    stat.show();
    cout << "Load complete" << endl;
    //warning->printWarning(0, 3);//๋ถ๋ฌ์ค๋ ค๋ ํ์ผ ๋ฌธ๋ฒ ์ค๋ฅ ๋ฉ์ธ์ง
    //return Character(Status());
}
